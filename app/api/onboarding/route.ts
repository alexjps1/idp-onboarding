import { NextResponse } from "next/server"

import {
  OPENAI_BASE_URL,
  OPENAI_CONTENT_MODEL,
  getOpenAIKey,
} from "@/lib/openai"
import { ONBOARDING_SYSTEM_PROMPT } from "@/lib/prompts"
import { gifsForFolder } from "@/lib/gif-catalog"

export const runtime = "nodejs"

// 1–7 scale used by the self-assessment Fragebogen.
const SCALE = [
  "keins/keine",
  "sehr wenig",
  "wenig",
  "eher wenig",
  "eher viel",
  "viel",
  "sehr viel",
]

// Total attempts per module: 1 initial + up to 2 corrective retries.
const MAX_ATTEMPTS = 3

type ModulePayload = {
  id: string
  title: string
  paragraphs: { text: string; gifs?: string[] }[]
  bullets?: { text: string; gif?: string }[]
  system?: string
  alwaysKeep?: boolean
  /** GIF catalog folder name when it differs from the module id. */
  gifFolder?: string
}

type RequestBody = {
  modules: ModulePayload[]
  /** Ratings keyed by system name: 1–7, or absent if unrated. */
  knowledge: Record<string, { theory?: number; practice?: number }>
}

type ModuleForModel = {
  id: string
  title: string
  alwaysKeep: boolean
  knowledge: string
  baseline: string
  /** GIF catalog folder name when it differs from the module id. */
  gifFolder?: string
  /**
   * Whether the average of theory and practice exceeds 5 for this module —
   * decided deterministically here, not by the model. This is a pure
   * threshold on two numbers with no dependency on module content, so
   * there's nothing for an LLM call to get right or wrong; omitted modules
   * skip adaptModule (and its cost/latency) entirely.
   */
  omitted: boolean
}

type AdaptedParagraph = { text: string; gifs?: string[] }

type AdaptedSection = {
  id: string
  title: string
  paragraphs: AdaptedParagraph[]
  omitted?: boolean
}

function scaleLabel(value?: number): string {
  if (value == null || value < 1 || value > 7) return "unbekannt"
  return SCALE[value - 1]
}

/** Omit a module when the average of its theory and practice ratings exceeds 5. */
function isAboveOmitThreshold(theory?: number, practice?: number): boolean {
  if (theory == null || practice == null) return false
  return (theory + practice) / 2 > 5
}

export async function POST(request: Request) {
  const apiKey = getOpenAIKey()
  if (!apiKey) {
    return NextResponse.json(
      { error: "OpenAI API key not configured (set OPENAI_API_KEY)." },
      { status: 501 }
    )
  }

  const body = (await request.json().catch(() => null)) as RequestBody | null
  if (!body?.modules?.length) {
    return NextResponse.json(
      { error: "Missing 'modules' in request body." },
      { status: 400 }
    )
  }

  // Build a compact, per-module knowledge brief for the model.
  const ratings = Object.values(body.knowledge ?? {})
  const overallTheory = avg(ratings.map((r) => r.theory))
  const overallPractice = avg(ratings.map((r) => r.practice))

  const modulesForModel: ModuleForModel[] = body.modules.map((m) => {
    const rating = m.system ? body.knowledge?.[m.system] : undefined
    const theory = rating?.theory ?? overallTheory
    const practice = rating?.practice ?? overallPractice
    return {
      id: m.id,
      title: m.title,
      alwaysKeep: m.alwaysKeep ?? false,
      knowledge: m.system
        ? `System "${m.system}": Theorie=${scaleLabel(theory)}, Praxis=${scaleLabel(practice)}`
        : `Allgemein (kein Einzelsystem): Theorie≈${scaleLabel(theory)}, Praxis≈${scaleLabel(practice)}`,
      baseline: [
        ...m.paragraphs.map((p) => p.text),
        ...(m.bullets?.map((b) => b.text) ?? []),
      ].join("\n"),
      gifFolder: m.gifFolder,
      // alwaysKeep modules are never sent here at all (filtered client-side),
      // but guard anyway — they must never be omitted regardless of rating.
      omitted: !m.alwaysKeep && isAboveOmitThreshold(theory, practice),
    }
  })

  // Adapt every module in parallel and stream each finished section back as a
  // newline-delimited JSON object the moment it is ready. The first result thus
  // returns roughly as fast as the quickest single module instead of after the
  // whole batch, and the client swaps each module from baseline to the adapted
  // version as it arrives — no waiting for everything.
  const encoder = new TextEncoder()
  const stream = new ReadableStream<Uint8Array>({
    async start(controller) {
      await Promise.all(
        modulesForModel.map(async (mod) => {
          if (mod.omitted) {
            // Deterministic — no LLM call needed (see ModuleForModel.omitted).
            const section: AdaptedSection = {
              id: mod.id,
              title: mod.title,
              paragraphs: [],
              omitted: true,
            }
            controller.enqueue(
              encoder.encode(JSON.stringify({ section }) + "\n")
            )
            return
          }
          try {
            const section = await adaptModule(mod, apiKey)
            if (section) {
              controller.enqueue(
                encoder.encode(JSON.stringify({ section }) + "\n")
              )
            }
          } catch (err) {
            // Swallow per-module failures: the client renders the baseline
            // content for any module it never receives an adapted section for.
            // Still logged (unlike the transient per-attempt warnings in
            // adaptModule) since this means that module's participant-facing
            // content silently fell back to baseline.
            console.error(`[onboarding] Modul "${mod.id}" komplett fehlgeschlagen, Baseline wird verwendet:`, err)
          }
        })
      )
      controller.close()
    },
  })

  return new Response(stream, {
    headers: {
      "Content-Type": "application/x-ndjson; charset=utf-8",
      "Cache-Control": "no-cache, no-transform",
      // Disable proxy buffering so sections reach the client incrementally.
      "X-Accel-Buffering": "no",
    },
  })
}

/**
 * Strict Structured Outputs schema for a single module's adapted section.
 * The caller only ever invokes adaptModule for modules already decided to
 * be kept (see ModuleForModel.omitted), so the model is never asked to
 * decide "omitted" here at all — one less thing for it to get wrong.
 * `gifs` items are enum-constrained to exactly the GIFs that exist in this
 * module's own folder, so a hallucinated or cross-module filename is
 * structurally impossible rather than merely discouraged by prompt wording.
 * Strict mode requires every object to set additionalProperties: false and
 * list every property in `required` — `gifs` is therefore always present
 * (an empty array, not omitted) rather than optional.
 */
function buildSectionResponseFormat(allowedGifNames: string[]) {
  return {
    type: "json_schema" as const,
    json_schema: {
      name: "adapted_section",
      strict: true,
      schema: {
        type: "object",
        properties: {
          sections: {
            type: "array",
            items: {
              type: "object",
              properties: {
                id: { type: "string" },
                title: { type: "string" },
                paragraphs: {
                  type: "array",
                  items: {
                    type: "object",
                    properties: {
                      text: { type: "string" },
                      gifs: {
                        type: "array",
                        items: { type: "string", enum: allowedGifNames },
                      },
                    },
                    required: ["text", "gifs"],
                    additionalProperties: false,
                  },
                },
              },
              required: ["id", "title", "paragraphs"],
              additionalProperties: false,
            },
          },
        },
        required: ["sections"],
        additionalProperties: false,
      },
    },
  }
}

// Two placeholders with nothing but whitespace between them — a strong
// signal they were dumped together (usually at the paragraph's end) rather
// than each placed at its own contentful spot in the text.
const ADJACENT_PLACEHOLDERS_RE = /\[GIF[1-3]\]\s*\[GIF[1-3]\]/

/**
 * Checks the guardrails that the schema alone can't express (Structured
 * Outputs strict mode doesn't reliably enforce minItems/maxItems, and can't
 * express cross-field/ordering constraints at all): that each paragraph's
 * [GIF1]/[GIF2]/[GIF3] placeholders exactly match its `gifs` array — same
 * count, 1..N, no gaps/dupes/extras, AND in that exact left-to-right reading
 * order (order matters: [GIF1] must be read before [GIF2], since gifs[0]
 * always renders leftmost) — that no two placeholders sit directly next to
 * each other, and that no GIF filename repeats across the module's
 * paragraphs. Returns a human-readable problem per violation, fed back to
 * the model verbatim on a corrective retry.
 */
function validateSection(
  section: AdaptedSection,
  allowedGifNames: string[]
): string[] {
  const problems: string[] = []
  const allowed = new Set(allowedGifNames)
  const seen = new Set<string>()

  section.paragraphs.forEach((para, i) => {
    const gifs = para.gifs ?? []
    const label = `Absatz ${i + 1}`

    if (gifs.length > 3) {
      problems.push(`${label}: ${gifs.length} Gifs angegeben, erlaubt sind höchstens 3.`)
    }
    for (const name of gifs) {
      if (!allowed.has(name)) {
        problems.push(`${label}: Gif "${name}" gehört nicht zu diesem Modul.`)
      }
      if (seen.has(name)) {
        problems.push(`Gif "${name}" wird mehrfach im selben Modul verwendet — jedes Gif darf nur einmal vorkommen.`)
      }
      seen.add(name)
    }

    // Order of appearance matters here — NOT sorted — so [GIF2] appearing
    // before [GIF1] in the text is correctly rejected instead of silently
    // accepted as "the right set of indices".
    const found = [...para.text.matchAll(/\[GIF([1-3])\]/g)].map((m) =>
      Number(m[1])
    )
    const expected = gifs.map((_, idx) => idx + 1)
    const matchesExpected =
      found.length === expected.length &&
      found.every((v, idx) => v === expected[idx])
    if (!matchesExpected) {
      const foundLabel = found.length
        ? found.map((n) => `[GIF${n}]`).join(",")
        : "keine"
      const expectedLabel = expected.length
        ? expected.map((n) => `[GIF${n}]`).join(",")
        : "keine"
      problems.push(
        `${label}: hat ${gifs.length} Gif(s), aber die Platzhalter ${foundLabel} wurden (in dieser Reihenfolge) im Text gefunden — erwartet werden genau ${expectedLabel} in genau dieser Reihenfolge.`
      )
    }

    if (ADJACENT_PLACEHOLDERS_RE.test(para.text)) {
      problems.push(
        `${label}: zwei Platzhalter stehen direkt nebeneinander (auch mit Leerzeichen dazwischen) — jeder Platzhalter muss an einer eigenen, inhaltlich passenden Stelle im Text stehen, nicht gebündelt am Satz- oder Absatzende.`
      )
    }
  })

  return problems
}

/** Position label per placeholder index, keyed by that paragraph's total GIF count. */
const POSITION_LABELS: Record<number, string[]> = {
  1: ["unten"],
  2: ["links", "rechts"],
  3: ["links", "Mitte", "rechts"],
}

/** Replaces a validated paragraph's [GIF1]/[GIF2]/[GIF3] placeholders with the correct position label. */
function resolvePlaceholders(text: string, gifsCount: number): string {
  const labels = POSITION_LABELS[gifsCount]
  if (!labels) return text
  return text.replace(/\[GIF([1-3])\]/g, (_match, idxStr: string) => {
    const idx = Number(idxStr)
    return `(${labels[idx - 1]})`
  })
}

/**
 * Adapts a single module (already decided to be kept — see
 * ModuleForModel.omitted, checked by the caller before this is ever
 * invoked) and returns its section, or null on a non-result. Retries with
 * corrective feedback (up to MAX_ATTEMPTS total) if the response fails GIF
 * validation; throws if still invalid after that, which the caller already
 * treats like any other per-module failure (swallowed — the client falls
 * back to that module's baseline content).
 */
async function adaptModule(
  mod: ModuleForModel,
  apiKey: string
): Promise<AdaptedSection | null> {
  const allowedGifNames = gifsForFolder(mod.gifFolder ?? mod.id).map(
    (g) => g.name
  )
  const responseFormat = buildSectionResponseFormat(allowedGifNames)

  const messages: { role: "system" | "user" | "assistant"; content: string }[] = [
    { role: "system", content: ONBOARDING_SYSTEM_PROMPT },
    { role: "user", content: JSON.stringify({ modules: [mod] }) },
  ]

  for (let attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
    const res = await fetch(`${OPENAI_BASE_URL}/chat/completions`, {
      method: "POST",
      headers: {
        Authorization: `Bearer ${apiKey}`,
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        model: OPENAI_CONTENT_MODEL,
        // gpt-5-mini is a reasoning model: it rejects a custom temperature.
        // "low" effort keeps it responsive while reliably following the
        // adaptation/GIF-placement rules below.
        reasoning_effort: "low",
        response_format: responseFormat,
        messages,
      }),
    })

    if (!res.ok) throw new Error(await res.text())

    const data = (await res.json()) as {
      choices?: { message?: { content?: string } }[]
    }
    const raw = data.choices?.[0]?.message?.content ?? "{}"
    const parsed = JSON.parse(raw) as { sections?: AdaptedSection[] }
    const section = parsed.sections?.[0] ?? null
    if (!section) return null

    const problems = validateSection(section, allowedGifNames)
    if (problems.length === 0) {
      return {
        ...section,
        omitted: false,
        paragraphs: section.paragraphs.map((p) => ({
          ...p,
          text: resolvePlaceholders(p.text, (p.gifs ?? []).length),
        })),
      }
    }

    console.warn(
      `[onboarding] Modul "${mod.id}" Versuch ${attempt + 1}/${MAX_ATTEMPTS} ungültig:\n${problems.map((p) => `  - ${p}`).join("\n")}`
    )

    if (attempt === MAX_ATTEMPTS - 1) break

    messages.push({ role: "assistant", content: raw })
    messages.push({
      role: "user",
      content: `Deine letzte Antwort hat folgende Probleme, die zwingend behoben werden müssen. Antworte erneut mit dem vollständigen, korrigierten JSON-Objekt im gleichen Format:\n${problems.map((p) => `- ${p}`).join("\n")}`,
    })
  }

  throw new Error(
    `GIF-Validierung für Modul "${mod.id}" nach ${MAX_ATTEMPTS} Versuchen fehlgeschlagen.`
  )
}

function avg(values: (number | undefined)[]): number | undefined {
  const nums = values.filter((v): v is number => typeof v === "number")
  if (!nums.length) return undefined
  return Math.round(nums.reduce((a, b) => a + b, 0) / nums.length)
}

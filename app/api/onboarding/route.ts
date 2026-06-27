import { NextResponse } from "next/server"

import {
  OPENAI_BASE_URL,
  OPENAI_CONTENT_MODEL,
  getOpenAIKey,
} from "@/lib/openai"
import { ONBOARDING_SYSTEM_PROMPT } from "@/lib/prompts"

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

type ModulePayload = {
  id: string
  title: string
  paragraphs: { text: string; gifs?: string[] }[]
  bullets?: { text: string; gif?: string }[]
  system?: string
  alwaysKeep?: boolean
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
}

type AdaptedSection = {
  id: string
  title: string
  paragraphs: { text: string; gifs?: string[] }[]
  omitted?: boolean
}

function scaleLabel(value?: number): string {
  if (value == null || value < 1 || value > 7) return "unbekannt"
  return SCALE[value - 1]
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
          try {
            const section = await adaptModule(mod, apiKey)
            if (section) {
              controller.enqueue(
                encoder.encode(JSON.stringify({ section }) + "\n")
              )
            }
          } catch {
            // Swallow per-module failures: the client renders the baseline
            // content for any module it never receives an adapted section for.
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

/** Adapts a single module and returns its section, or null on a non-result. */
async function adaptModule(
  mod: ModuleForModel,
  apiKey: string
): Promise<AdaptedSection | null> {
  const res = await fetch(`${OPENAI_BASE_URL}/chat/completions`, {
    method: "POST",
    headers: {
      Authorization: `Bearer ${apiKey}`,
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      model: OPENAI_CONTENT_MODEL,
      // gpt-5-mini is a reasoning model: it rejects a custom temperature. "low"
      // effort keeps it responsive while reliably making the per-module
      // keep-vs-omit decision (minimal effort tended to write a filler sentence
      // instead of actually omitting).
      reasoning_effort: "low",
      response_format: { type: "json_object" },
      messages: [
        { role: "system", content: ONBOARDING_SYSTEM_PROMPT },
        { role: "user", content: JSON.stringify({ modules: [mod] }) },
      ],
    }),
  })

  if (!res.ok) throw new Error(await res.text())

  const data = (await res.json()) as {
    choices?: { message?: { content?: string } }[]
  }
  const raw = data.choices?.[0]?.message?.content ?? "{}"
  const parsed = JSON.parse(raw) as { sections?: AdaptedSection[] }
  return parsed.sections?.[0] ?? null
}

function avg(values: (number | undefined)[]): number | undefined {
  const nums = values.filter((v): v is number => typeof v === "number")
  if (!nums.length) return undefined
  return Math.round(nums.reduce((a, b) => a + b, 0) / nums.length)
}

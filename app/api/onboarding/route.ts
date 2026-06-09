import { NextResponse } from "next/server"

import {
  OPENAI_BASE_URL,
  OPENAI_CONTENT_MODEL,
  getOpenAIKey,
} from "@/lib/openai"

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
  paragraphs: string[]
  bullets?: string[]
  system?: string
  alwaysKeep?: boolean
}

type RequestBody = {
  modules: ModulePayload[]
  /** Ratings keyed by system name: 1–7, or absent if unrated. */
  knowledge: Record<string, { theory?: number; practice?: number }>
}

function scaleLabel(value?: number): string {
  if (value == null || value < 1 || value > 7) return "unbekannt"
  return SCALE[value - 1]
}

const SYSTEM_PROMPT = `Du bereitest den Onboarding-Leitfaden für teilautomatisiertes Fahren (SAE Level 2) individuell auf.
Für jedes Modul kennst du das Vorwissen der teilnehmenden Person (theoretisches Wissen und praktische Erfahrung auf einer Skala von "keins" bis "sehr viel").

Passe jeden Abschnitt an dieses Vorwissen an:
- Wenig/kein Vorwissen ("keins", "sehr wenig", "wenig"): ausführlicher erklären, einfache Sprache, ggf. eine kurze Alltagsanalogie. Mehr Sätze sind erlaubt.
- Mittleres Vorwissen ("eher wenig", "eher viel"): knapp und sachlich halten.
- Hohes Vorwissen ("viel", "sehr viel"): stark kürzen auf das prozedural Wesentliche; bei sehr hohem Vorwissen darfst du das Modul ganz weglassen (setze "omitted": true).

Strenge Regeln:
- Erfinde keine Funktionen oder Fakten. Bleib inhaltlich exakt bei der Vorlage.
- Module mit "alwaysKeep": true (Sicherheit/Verantwortung) niemals kürzen oder weglassen; alle Stichpunkte sinngemäß vollständig behalten.
- Antworte ausschließlich auf Deutsch.
- Reihenfolge und "id" jedes Moduls unverändert lassen.

Antworte als JSON-Objekt exakt in diesem Format:
{"sections":[{"id":"...","title":"...","paragraphs":["..."],"omitted":false}]}
Bei weggelassenen Modulen "omitted": true und "paragraphs": [].`

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

  const modulesForModel = body.modules.map((m) => {
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
      baseline: [...m.paragraphs, ...(m.bullets ?? [])].join("\n"),
    }
  })

  const res = await fetch(`${OPENAI_BASE_URL}/chat/completions`, {
    method: "POST",
    headers: {
      Authorization: `Bearer ${apiKey}`,
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      model: OPENAI_CONTENT_MODEL,
      temperature: 0.4,
      response_format: { type: "json_object" },
      messages: [
        { role: "system", content: SYSTEM_PROMPT },
        { role: "user", content: JSON.stringify({ modules: modulesForModel }) },
      ],
    }),
  })

  if (!res.ok) {
    const detail = await res.text()
    return NextResponse.json(
      { error: "Adaptation failed.", detail },
      { status: 502 }
    )
  }

  const data = (await res.json()) as {
    choices?: { message?: { content?: string } }[]
  }
  const raw = data.choices?.[0]?.message?.content ?? "{}"
  try {
    const parsed = JSON.parse(raw) as {
      sections?: {
        id: string
        title: string
        paragraphs: string[]
        omitted?: boolean
      }[]
    }
    return NextResponse.json({ sections: parsed.sections ?? [] })
  } catch {
    return NextResponse.json(
      { error: "Model returned malformed JSON." },
      { status: 502 }
    )
  }
}

function avg(values: (number | undefined)[]): number | undefined {
  const nums = values.filter((v): v is number => typeof v === "number")
  if (!nums.length) return undefined
  return Math.round(nums.reduce((a, b) => a + b, 0) / nums.length)
}

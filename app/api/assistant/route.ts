import { NextResponse } from "next/server"

import {
  OPENAI_BASE_URL,
  OPENAI_CONTENT_MODEL,
  getOpenAIKey,
} from "@/lib/openai"

export const runtime = "nodejs"

const SYSTEM_PROMPT = `Du bist ein KI-Tutor in einem teilautomatisiert fahrenden Fahrzeug (SAE Level 2).
Du beantwortest gesprochene Fragen der fahrenden Person zu den Fahrerassistenzsystemen
(Aktivierung, Verkehrszeichenassistent, Abstandsregeltempomat, Ampelerkennung,
Spurführungsassistent, Notbremsassistent, Deaktivierung sowie Risiken und Verantwortung).
Antworte auf Deutsch, knapp und klar in höchstens 3 kurzen Sätzen, da die Antwort
während der Fahrt auf einem Display angezeigt wird. Weise bei sicherheitsrelevanten
Themen darauf hin, dass die fahrende Person stets die Verantwortung behält.`

/**
 * Content endpoint. Receives the transcribed question and asks the chat model
 * for a short, display-friendly tutor answer. Called once per recognised
 * utterance — never on a timer.
 */
export async function POST(request: Request) {
  const apiKey = getOpenAIKey()
  if (!apiKey) {
    return NextResponse.json(
      { error: "OpenAI API key not configured (set OPENAI_API_KEY)." },
      { status: 501 }
    )
  }

  const body = (await request.json().catch(() => null)) as {
    prompt?: string
  } | null
  const prompt = body?.prompt?.trim()
  if (!prompt) {
    return NextResponse.json(
      { error: "Missing 'prompt' in request body." },
      { status: 400 }
    )
  }

  const res = await fetch(`${OPENAI_BASE_URL}/chat/completions`, {
    method: "POST",
    headers: {
      Authorization: `Bearer ${apiKey}`,
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      model: OPENAI_CONTENT_MODEL,
      temperature: 0.3,
      messages: [
        { role: "system", content: SYSTEM_PROMPT },
        { role: "user", content: prompt },
      ],
    }),
  })

  if (!res.ok) {
    const detail = await res.text()
    return NextResponse.json(
      { error: "Content generation failed.", detail },
      { status: 502 }
    )
  }

  const data = (await res.json()) as {
    choices?: { message?: { content?: string } }[]
  }
  const content = data.choices?.[0]?.message?.content?.trim() ?? ""
  return NextResponse.json({ content })
}

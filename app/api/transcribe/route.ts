import { NextResponse } from "next/server"

import {
  OPENAI_BASE_URL,
  OPENAI_TRANSCRIPTION_MODEL,
  getOpenAIKey,
} from "@/lib/openai"

export const runtime = "nodejs"

/**
 * Live transcription endpoint. The client records a short audio chunk *only
 * while the user is actually speaking* (voice-activity detection) and posts it
 * here as multipart/form-data. We forward it to OpenAI's transcription model
 * and return the recognised text.
 */
export async function POST(request: Request) {
  const apiKey = getOpenAIKey()
  if (!apiKey) {
    return NextResponse.json(
      { error: "OpenAI API key not configured (set OPENAI_API_KEY)." },
      { status: 501 }
    )
  }

  const form = await request.formData()
  const audio = form.get("audio")
  if (!(audio instanceof Blob) || audio.size === 0) {
    return NextResponse.json(
      { error: "Missing 'audio' file in form data." },
      { status: 400 }
    )
  }

  const upstream = new FormData()
  upstream.append("file", audio, "speech.webm")
  upstream.append("model", OPENAI_TRANSCRIPTION_MODEL)
  upstream.append("language", "de")
  upstream.append("response_format", "json")

  const res = await fetch(`${OPENAI_BASE_URL}/audio/transcriptions`, {
    method: "POST",
    headers: { Authorization: `Bearer ${apiKey}` },
    body: upstream,
  })

  if (!res.ok) {
    const detail = await res.text()
    return NextResponse.json(
      { error: "Transcription failed.", detail },
      { status: 502 }
    )
  }

  const data = (await res.json()) as { text?: string }
  return NextResponse.json({ text: data.text?.trim() ?? "" })
}

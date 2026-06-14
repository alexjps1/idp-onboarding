import { NextResponse } from "next/server"

import {
  OPENAI_BASE_URL,
  OPENAI_REALTIME_MODEL,
  OPENAI_REALTIME_VOICE,
  OPENAI_TRANSCRIPTION_MODEL,
  getOpenAIKey,
} from "@/lib/openai"
import { REALTIME_INSTRUCTIONS } from "@/lib/prompts"

export const runtime = "nodejs"

/**
 * Mints an ephemeral Realtime client secret. The browser uses it to open a
 * WebRTC session directly with OpenAI — the long-lived API key never leaves
 * the server. Called once each time the assistant overlay is opened.
 */
export async function POST() {
  const apiKey = getOpenAIKey()
  if (!apiKey) {
    return NextResponse.json(
      { error: "OpenAI API key not configured (set OPENAI_API_KEY)." },
      { status: 501 }
    )
  }

  const res = await fetch(`${OPENAI_BASE_URL}/realtime/client_secrets`, {
    method: "POST",
    headers: {
      Authorization: `Bearer ${apiKey}`,
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      session: {
        type: "realtime",
        model: OPENAI_REALTIME_MODEL,
        instructions: REALTIME_INSTRUCTIONS,
        audio: {
          input: {
            transcription: {
              model: OPENAI_TRANSCRIPTION_MODEL,
              language: "de",
            },
            // Filter cabin/background noise before VAD so the tutor is only
            // interrupted by actual speech, not by random sounds.
            noise_reduction: { type: "near_field" },
            turn_detection: { type: "semantic_vad" },
          },
          output: { voice: OPENAI_REALTIME_VOICE },
        },
      },
    }),
  })

  if (!res.ok) {
    const detail = await res.text()
    return NextResponse.json(
      { error: "Realtime session creation failed.", detail },
      { status: 502 }
    )
  }

  const data = (await res.json()) as { value?: string }
  if (!data.value) {
    return NextResponse.json(
      { error: "Realtime session creation returned no client secret." },
      { status: 502 }
    )
  }

  return NextResponse.json({
    clientSecret: data.value,
    model: OPENAI_REALTIME_MODEL,
  })
}

import { NextResponse } from "next/server"

import {
  OPENAI_BASE_URL,
  OPENAI_REALTIME_MODEL,
  OPENAI_REALTIME_VOICE,
  OPENAI_TRANSCRIPTION_MODEL,
  getOpenAIKey,
} from "@/lib/openai"
import {
  REALTIME_INSTRUCTIONS,
  buildProactiveInstructions,
} from "@/lib/prompts"
import { GIF_NAMES, buildShowGifDescription } from "@/lib/gif-catalog"

export const runtime = "nodejs"

type RealtimeBody = {
  proactive?: boolean
  theory?: Record<string, number>
  practice?: Record<string, number>
}

/**
 * Mints an ephemeral Realtime client secret. The browser uses it to open a
 * WebRTC session directly with OpenAI — the long-lived API key never leaves
 * the server. Called once each time the assistant overlay is opened.
 *
 * An optional JSON body opens the session in *proactive* mode: the tutor greets
 * on its own and offers to explain one assistance system, chosen from the
 * participant's self-assessment (theory/practice ratings) passed in the body.
 * No body (or an invalid one) yields the normal reactive tutor.
 */
export async function POST(req: Request) {
  const apiKey = getOpenAIKey()
  if (!apiKey) {
    return NextResponse.json(
      { error: "OpenAI API key not configured (set OPENAI_API_KEY)." },
      { status: 501 }
    )
  }

  let body: RealtimeBody = {}
  try {
    body = (await req.json()) as RealtimeBody
  } catch {
    // No/invalid body → default reactive session.
  }

  const instructions = body.proactive
    ? buildProactiveInstructions(body.theory ?? {}, body.practice ?? {})
    : REALTIME_INSTRUCTIONS

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
        instructions,
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
        tools: [
          {
            type: "function",
            name: "show_gif",
            description: buildShowGifDescription(),
            parameters: {
              type: "object",
              properties: {
                name: {
                  type: "string",
                  enum: GIF_NAMES,
                  description: "Name des anzuzeigenden GIFs.",
                },
              },
              required: ["name"],
            },
          },
          {
            type: "function",
            name: "hide_gif",
            description:
              "Blendet das aktuell angezeigte GIF aus, wenn es nicht mehr relevant ist.",
            parameters: {
              type: "object",
              properties: {},
              required: [],
            },
          },
          {
            type: "function",
            name: "end_session",
            description:
              "Beendet das Sprachgespräch und schließt den Assistenten. Nur aufrufen, wenn die fahrende Person das Gespräch ausdrücklich beenden möchte – erst nach einem kurzen gesprochenen Abschied.",
            parameters: {
              type: "object",
              properties: {},
              required: [],
            },
          },
        ],
        tool_choice: "auto",
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

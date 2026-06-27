"use client"

import * as React from "react"

import { withBasePath } from "@/lib/base-path"
import type { VoiceMessage } from "@/lib/study-data"

/**
 * Replace microphone input with a text field — useful for testing in quiet
 * environments (library, office). Controlled via NEXT_PUBLIC_REALTIME_TEXT_INPUT
 * and defaults to false (real microphone). When enabled, the agent still
 * responds with audio; a silent dummy stream is sent instead of real mic data
 * so the WebRTC connection succeeds without requesting microphone permission.
 */
export const REALTIME_TEXT_INPUT =
  process.env.NEXT_PUBLIC_REALTIME_TEXT_INPUT === "true"

export type VoiceTutorStatus =
  | "idle" // no session
  | "connecting" // minting token + WebRTC handshake
  | "listening" // session live, waiting for speech
  | "speaking" // user is talking
  | "responding" // tutor is answering (audio is playing)
  | "error"

type VoiceTutorState = {
  status: VoiceTutorStatus
  transcript: string // last recognised user utterance
  answer: string // tutor answer, streamed in as it is spoken
  currentGif: string | null // GIF name currently shown below the speech bubble
  error: string | null
}

const INITIAL: VoiceTutorState = {
  status: "idle",
  transcript: "",
  answer: "",
  currentGif: null,
  error: null,
}

// Server events arriving on the data channel. Only the fields we read.
type RealtimeEvent = {
  type: string
  transcript?: string
  delta?: string
  // function call fields
  call_id?: string
  name?: string
  arguments?: string
  error?: { message?: string }
}

/**
 * Live voice conversation with the tutor via the OpenAI Realtime API.
 *
 * start() fetches an ephemeral client secret from /api/realtime and opens a
 * WebRTC session: the mic track streams up, the tutor's voice streams back
 * into a hidden <audio> element, and JSON events on the "oai-events" data
 * channel drive the status/transcript display. Turn-taking (VAD) and barge-in
 * are handled server-side, so the session stays open until stop().
 */
export function useVoiceTutor(
  options: {
    onMessage?: (message: VoiceMessage) => void
    /** Called when the tutor ends the session itself (driver asked to stop). */
    onEnd?: () => void
  } = {}
) {
  const [state, setState] = React.useState<VoiceTutorState>(INITIAL)

  // Keep the latest callbacks in refs so handleEvent's identity stays stable
  // and the live WebRTC session isn't torn down when the parent re-renders.
  const onMessageRef = React.useRef(options.onMessage)
  React.useEffect(() => {
    onMessageRef.current = options.onMessage
  }, [options.onMessage])

  const onEndRef = React.useRef(options.onEnd)
  React.useEffect(() => {
    onEndRef.current = options.onEnd
  }, [options.onEnd])

  const patch = React.useCallback(
    (partial: Partial<VoiceTutorState>) =>
      setState((prev) => ({ ...prev, ...partial })),
    []
  )

  const pcRef = React.useRef<RTCPeerConnection | null>(null)
  const dcRef = React.useRef<RTCDataChannel | null>(null)
  const streamRef = React.useRef<MediaStream | null>(null)
  const audioRef = React.useRef<HTMLAudioElement | null>(null)
  const audioCtxRef = React.useRef<AudioContext | null>(null)
  // Set when the tutor calls end_session; the session is torn down once the
  // spoken goodbye has finished playing (or a fallback timer fires).
  const endRequestedRef = React.useRef(false)
  const endTimerRef = React.useRef<ReturnType<typeof setTimeout> | null>(null)

  const teardown = React.useCallback(() => {
    if (endTimerRef.current) {
      clearTimeout(endTimerRef.current)
      endTimerRef.current = null
    }
    endRequestedRef.current = false
    dcRef.current?.close()
    dcRef.current = null
    pcRef.current?.close()
    pcRef.current = null
    streamRef.current?.getTracks().forEach((t) => t.stop())
    streamRef.current = null
    if (audioRef.current) {
      audioRef.current.srcObject = null
      audioRef.current = null
    }
    audioCtxRef.current?.close().catch(() => {})
    audioCtxRef.current = null
  }, [])

  const stop = React.useCallback(() => {
    teardown()
    patch({ status: "idle", currentGif: null })
  }, [teardown, patch])

  // Finalise a tutor-initiated end: tear down and notify the parent so the
  // assistant overlay closes. Guarded so it runs once even if both the
  // audio-finished event and the fallback timer fire.
  const finishEnd = React.useCallback(() => {
    if (!endRequestedRef.current) return
    teardown()
    patch({ status: "idle", currentGif: null })
    onEndRef.current?.()
  }, [teardown, patch])

  const handleEvent = React.useCallback(
    (event: RealtimeEvent) => {
      if (!pcRef.current) return // session already torn down
      switch (event.type) {
        case "input_audio_buffer.speech_started":
          // New turn: clear the previous exchange from the display.
          patch({ status: "speaking", transcript: "", answer: "" })
          break
        case "conversation.item.input_audio_transcription.completed":
          patch({ transcript: event.transcript ?? "" })
          if (event.transcript) {
            onMessageRef.current?.({
              role: "user",
              text: event.transcript,
              at: new Date().toISOString(),
            })
          }
          break
        case "response.created":
          patch({ status: "responding" })
          break
        // GA and beta event names for the spoken answer's transcript.
        case "response.output_audio_transcript.delta":
        case "response.audio_transcript.delta":
          setState((prev) => ({
            ...prev,
            status: "responding",
            answer: prev.answer + (event.delta ?? ""),
          }))
          break
        case "response.output_audio_transcript.done":
        case "response.audio_transcript.done":
          if (event.transcript) {
            patch({ answer: event.transcript })
            onMessageRef.current?.({
              role: "assistant",
              text: event.transcript,
              at: new Date().toISOString(),
            })
          }
          break
        case "response.done":
          patch({ status: "listening" })
          break
        case "output_audio_buffer.stopped":
          // The spoken goodbye has finished playing — safe to close now.
          if (endRequestedRef.current) finishEnd()
          break
        case "response.function_call_arguments.done": {
          const { name, arguments: argsStr, call_id } = event
          if (name === "end_session") {
            // The driver asked to end the conversation. Acknowledge the call,
            // let the goodbye spoken in this same response play out, then tear
            // down on output_audio_buffer.stopped. The timer is a safety net in
            // case that event never arrives (e.g. a goodbye-less response).
            endRequestedRef.current = true
            dcRef.current?.send(
              JSON.stringify({
                type: "conversation.item.create",
                item: { type: "function_call_output", call_id, output: "ok" },
              })
            )
            endTimerRef.current = setTimeout(finishEnd, 8000)
            break
          }
          if (name === "show_gif") {
            const gifName = (JSON.parse(argsStr ?? "{}") as { name?: string })
              .name
            if (gifName) {
              setState((prev) =>
                prev.currentGif === gifName
                  ? prev
                  : { ...prev, currentGif: gifName }
              )
            }
          } else if (name === "hide_gif") {
            patch({ currentGif: null })
          }
          // Acknowledge the tool call so the model can continue speaking.
          dcRef.current?.send(
            JSON.stringify({
              type: "conversation.item.create",
              item: { type: "function_call_output", call_id, output: "ok" },
            })
          )
          dcRef.current?.send(JSON.stringify({ type: "response.create" }))
          break
        }
        case "error":
          patch({
            status: "error",
            error: event.error?.message ?? "Unbekannter Fehler",
          })
          break
      }
    },
    [patch, finishEnd]
  )

  const start = React.useCallback(async () => {
    if (pcRef.current) return
    try {
      patch({ status: "connecting", error: null, transcript: "", answer: "" })

      // Acquire the audio stream first, while the user's tap is still the active
      // gesture. iOS Safari drops that activation across an awaited network
      // request, which would otherwise suppress the mic-permission prompt.
      let stream: MediaStream
      if (REALTIME_TEXT_INPUT) {
        // Produce a silent audio track so the WebRTC offer has a valid audio
        // m-line without requesting microphone permission.
        const ctx = new AudioContext()
        audioCtxRef.current = ctx
        const oscillator = ctx.createOscillator()
        const gain = ctx.createGain()
        gain.gain.value = 0
        const dst = ctx.createMediaStreamDestination()
        oscillator.connect(gain)
        gain.connect(dst)
        oscillator.start()
        stream = dst.stream
      } else {
        if (!navigator.mediaDevices?.getUserMedia) {
          // getUserMedia only exists in a secure context (HTTPS or localhost).
          throw new Error(
            "Mikrofon nur über HTTPS verfügbar – bitte die Seite über https:// öffnen."
          )
        }
        // Echo cancellation keeps the tutor's own voice from re-entering the
        // mic; noise suppression prevents background sounds from triggering VAD.
        stream = await navigator.mediaDevices.getUserMedia({
          audio: {
            echoCancellation: true,
            noiseSuppression: true,
            autoGainControl: true,
          },
        })
      }
      streamRef.current = stream

      const tokenRes = await fetch(withBasePath("/api/realtime"), {
        method: "POST",
      })
      if (!tokenRes.ok) {
        throw new Error(
          (await tokenRes.json()).error ??
            "Sprachsitzung konnte nicht erstellt werden"
        )
      }
      const { clientSecret, model } = (await tokenRes.json()) as {
        clientSecret: string
        model: string
      }

      const pc = new RTCPeerConnection()
      pcRef.current = pc

      // The tutor's voice arrives as a remote audio track.
      const audioEl = document.createElement("audio")
      audioEl.autoplay = true
      audioRef.current = audioEl
      pc.ontrack = (e) => {
        audioEl.srcObject = e.streams[0]
      }

      pc.addTrack(stream.getAudioTracks()[0], stream)

      const dc = pc.createDataChannel("oai-events")
      dcRef.current = dc
      dc.onopen = () => patch({ status: "listening" })
      dc.onmessage = (e) => {
        try {
          handleEvent(JSON.parse(e.data) as RealtimeEvent)
        } catch {
          // Ignore malformed events.
        }
      }

      const offer = await pc.createOffer()
      await pc.setLocalDescription(offer)

      const sdpRes = await fetch(
        `https://api.openai.com/v1/realtime/calls?model=${encodeURIComponent(model)}`,
        {
          method: "POST",
          headers: {
            Authorization: `Bearer ${clientSecret}`,
            "Content-Type": "application/sdp",
          },
          body: offer.sdp,
        }
      )
      if (!sdpRes.ok) throw new Error("Realtime-Verbindung fehlgeschlagen")
      const answerSdp = await sdpRes.text()

      // stop() may have run while we were waiting on the network.
      if (pcRef.current !== pc) return
      await pc.setRemoteDescription({ type: "answer", sdp: answerSdp })
    } catch (err) {
      teardown()
      patch({
        status: "error",
        error:
          err instanceof Error
            ? `Sprachassistent nicht verfügbar: ${err.message}`
            : "Sprachassistent nicht verfügbar",
      })
    }
  }, [patch, handleEvent, teardown])

  const sendText = React.useCallback(
    (text: string) => {
      if (!dcRef.current) return
      patch({ transcript: text, answer: "", currentGif: null, status: "responding" })
      dcRef.current.send(
        JSON.stringify({
          type: "conversation.item.create",
          item: {
            type: "message",
            role: "user",
            content: [{ type: "input_text", text }],
          },
        })
      )
      dcRef.current.send(JSON.stringify({ type: "response.create" }))
    },
    [patch]
  )

  // Tear down on unmount.
  React.useEffect(() => () => teardown(), [teardown])

  return { ...state, start, stop, sendText }
}

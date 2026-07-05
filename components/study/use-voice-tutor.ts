"use client"

import * as React from "react"

import { withBasePath } from "@/lib/base-path"
import {
  buildProactiveInstructions,
  buildIntroInstructions,
  buildZoneNudgeInstructions,
  buildSystemLimitInstructions,
} from "@/lib/prompts"
import type { VoiceMessage } from "@/lib/study-data"
import type { Ratings } from "@/components/study/study-provider"

/**
 * Which proactive moment is being opened. "adas_on" = the driving automation
 * was just switched on for the first time (uses the self-assessment ratings
 * to pick a system to offer); "intro" = the one-time self-introduction
 * shortly after the drive view loads; "zone_nudge" = the car entered a fixed
 * track zone with ADAS off; "system_limit" = the car passed the DHL-van
 * takeover with ADAS having been on beforehand.
 */
export type ProactiveKind = "adas_on" | "intro" | "zone_nudge" | "system_limit"

/**
 * Options for {@link useVoiceTutor.start}. When `proactiveKind` is set the
 * session is opened in proactive mode (the tutor speaks first); the
 * self-assessment ratings are only used by the "adas_on" kind.
 */
export type StartOptions = {
  proactiveKind?: ProactiveKind
  theory?: Ratings
  practice?: Ratings
}

/** Picks the instructions for a given proactive kind (client-side use). */
function buildInstructionsForKind(
  kind: ProactiveKind,
  theory: Ratings,
  practice: Ratings
): string {
  switch (kind) {
    case "adas_on":
      return buildProactiveInstructions(theory, practice)
    case "intro":
      return buildIntroInstructions()
    case "zone_nudge":
      return buildZoneNudgeInstructions()
    case "system_limit":
      return buildSystemLimitInstructions()
  }
}

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
  | "ready" // pre-warmed: connected, mic muted, no conversation yet
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

// Backoff schedule (ms) for a failed pre-warm attempt. Exhausted silently —
// start() always falls back to an on-demand connect, so a stuck pre-warm is
// never user-visible.
const PREWARM_RETRY_DELAYS_MS = [2000, 5000, 15000]

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
 * The connection is pre-warmed in the background (see {@link prewarm}): a
 * session opens on mount with the mic muted, so start() can just unmute and
 * begin talking instantly instead of waiting out a fresh WebRTC handshake.
 * Each conversation still starts fresh — once it ends, the connection is
 * closed and a new one is pre-warmed for next time, rather than kept alive
 * (that would let the tutor remember earlier turns and let per-turn cost
 * creep up over the drive — see the session's design discussion).
 *
 * start() either activates an already-warm session or, if none is ready yet,
 * fetches an ephemeral client secret from /api/realtime and opens a WebRTC
 * session itself: the mic track streams up, the tutor's voice streams back
 * into a hidden <audio> element, and JSON events on the "oai-events" data
 * channel drive the status/transcript display. Turn-taking (VAD) and
 * barge-in are handled server-side, so the session stays open until stop().
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

  // Mirrors state.status synchronously — state updates are async, but event
  // handlers created mid-connect (e.g. the ICE state handler below) need to
  // read the *current* status.
  const statusRef = React.useRef<VoiceTutorStatus>(INITIAL.status)

  const patch = React.useCallback(
    (partial: Partial<VoiceTutorState>) =>
      setState((prev) => {
        const next = { ...prev, ...partial }
        statusRef.current = next.status
        return next
      }),
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
  // "warm" while pre-warming/pre-warmed, "live" once a real conversation has
  // started — lets start() tell a still-connecting pre-warm apart from an
  // already-active conversation.
  const connectModeRef = React.useRef<"warm" | "live" | null>(null)
  // Pre-warm retry bookkeeping (reset on every fresh prewarm() call).
  const prewarmAttemptsRef = React.useRef(0)
  const retryTimerRef = React.useRef<ReturnType<typeof setTimeout> | null>(
    null
  )

  const teardown = React.useCallback(() => {
    if (endTimerRef.current) {
      clearTimeout(endTimerRef.current)
      endTimerRef.current = null
    }
    if (retryTimerRef.current) {
      clearTimeout(retryTimerRef.current)
      retryTimerRef.current = null
    }
    endRequestedRef.current = false
    connectModeRef.current = null
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

  // prewarm()/runConnect() are defined lower down but need to call each other
  // and be called from finishEnd/handleEvent above them — forwarded through
  // refs, same pattern as onMessageRef/onEndRef above, to avoid a dependency
  // cycle between the callbacks.
  const prewarmRef = React.useRef<() => void>(() => {})
  // Internal retry-only warm connect — unlike prewarm(), does not reset the
  // attempt counter, so the backoff schedule actually escalates.
  const retryWarmRef = React.useRef<() => void>(() => {})

  const stop = React.useCallback(() => {
    teardown()
    patch({ status: "idle", currentGif: null })
    // Ready for the next interaction: each open still starts a fresh
    // conversation, just with the connection already sitting open.
    prewarmRef.current()
  }, [teardown, patch])

  // Finalise a tutor-initiated end: tear down and notify the parent so the
  // assistant overlay closes. Guarded so it runs once even if both the
  // audio-finished event and the fallback timer fire.
  const finishEnd = React.useCallback(() => {
    if (!endRequestedRef.current) return
    teardown()
    patch({ status: "idle", currentGif: null })
    onEndRef.current?.()
    prewarmRef.current()
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

  /**
   * Shared connect implementation for both a full start() and a background
   * prewarm(). In "warm" mode the mic track is added but immediately
   * disabled (silence only — VAD filters it out, so a muted pre-warmed
   * connection costs nothing while it waits) and the data channel's open
   * handler stops at status "ready" instead of unmuting/greeting.
   */
  const runConnect = React.useCallback(
    async (mode: "warm" | "live", opts?: StartOptions) => {
      const proactiveKind =
        mode === "live" ? opts?.proactiveKind : undefined
      connectModeRef.current = mode
      try {
        patch({
          status: "connecting",
          error: null,
          transcript: "",
          answer: "",
        })

        // Acquire the audio stream first, while the user's tap is still the active
        // gesture. iOS Safari drops that activation across an awaited network
        // request, which would otherwise suppress the mic-permission prompt. (Not
        // a concern in "warm" mode: pre-warming only ever runs after the entry
        // page's mic-permission gate has already been granted, so this call needs
        // no gesture there.)
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
        if (mode === "warm") {
          stream.getAudioTracks().forEach((t) => {
            t.enabled = false
          })
        }
        streamRef.current = stream

        const tokenRes = await fetch(withBasePath("/api/realtime"), {
          method: "POST",
          ...(proactiveKind
            ? {
                headers: { "Content-Type": "application/json" },
                body: JSON.stringify({
                  proactiveKind,
                  theory: opts?.theory ?? {},
                  practice: opts?.practice ?? {},
                }),
              }
            : {}),
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

        // While pre-warmed and unused, an unexpected drop (network blip, a
        // Realtime-side idle/session limit) should repair itself silently —
        // nobody is watching a "ready" connection. Once a real conversation
        // is live, statusRef is no longer "ready" and this is a no-op.
        pc.oniceconnectionstatechange = () => {
          if (pcRef.current !== pc) return
          const st = pc.iceConnectionState
          if (
            (st === "failed" || st === "disconnected" || st === "closed") &&
            statusRef.current === "ready"
          ) {
            teardown()
            patch({ status: "idle" })
            prewarmRef.current()
          }
        }

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
        dc.onopen = () => {
          if (mode === "warm") {
            prewarmAttemptsRef.current = 0
            patch({ status: "ready" })
            return
          }
          patch({ status: "listening" })
          // In proactive mode the user hasn't said anything, so ask the model to
          // generate the opening turn itself (it follows the proactive session
          // instructions and greets first).
          if (proactiveKind) {
            patch({ status: "responding" })
            dc.send(JSON.stringify({ type: "response.create" }))
          }
        }
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
        if (mode === "warm") {
          // Pre-warming is a latency optimisation, not a correctness
          // requirement — start() falls back to an on-demand connect
          // regardless, so a failed pre-warm never needs to be user-visible.
          console.error("Realtime pre-warm failed", err)
          patch({ status: "idle" })
          const attempt = prewarmAttemptsRef.current
          if (attempt < PREWARM_RETRY_DELAYS_MS.length) {
            prewarmAttemptsRef.current += 1
            retryTimerRef.current = setTimeout(
              () => retryWarmRef.current(),
              PREWARM_RETRY_DELAYS_MS[attempt]
            )
          }
        } else {
          patch({
            status: "error",
            error:
              err instanceof Error
                ? `Sprachassistent nicht verfügbar: ${err.message}`
                : "Sprachassistent nicht verfügbar",
          })
        }
      }
    },
    [patch, handleEvent, teardown]
  )

  /**
   * Opens a muted, pre-warmed session in the background so start() can
   * activate it instantly later. No-op if a connect (warm or live) is
   * already in flight or a session is already open.
   */
  const prewarm = React.useCallback(() => {
    if (pcRef.current) return
    prewarmAttemptsRef.current = 0
    if (retryTimerRef.current) {
      clearTimeout(retryTimerRef.current)
      retryTimerRef.current = null
    }
    void runConnect("warm")
  }, [runConnect])

  React.useEffect(() => {
    prewarmRef.current = prewarm
  }, [prewarm])

  React.useEffect(() => {
    retryWarmRef.current = () => {
      if (!pcRef.current) void runConnect("warm")
    }
  }, [runConnect])

  /**
   * Fast path: unmute an already-"ready" pre-warmed session and, for a
   * proactive open, swap in the proactive instructions (a partial
   * session.update — everything else, tools included, stays as configured)
   * before asking the model to greet.
   */
  const activate = React.useCallback(
    (opts?: StartOptions) => {
      streamRef.current?.getAudioTracks().forEach((t) => {
        t.enabled = true
      })
      connectModeRef.current = "live"
      if (opts?.proactiveKind) {
        const instructions = buildInstructionsForKind(
          opts.proactiveKind,
          opts.theory ?? {},
          opts.practice ?? {}
        )
        dcRef.current?.send(
          JSON.stringify({
            type: "session.update",
            session: { type: "realtime", instructions },
          })
        )
        patch({
          status: "responding",
          error: null,
          transcript: "",
          answer: "",
        })
        dcRef.current?.send(JSON.stringify({ type: "response.create" }))
      } else {
        patch({ status: "listening", error: null, transcript: "", answer: "" })
      }
    },
    [patch]
  )

  const start = React.useCallback(
    async (opts?: StartOptions) => {
      if (statusRef.current === "ready" && pcRef.current) {
        activate(opts)
        return
      }
      if (pcRef.current) {
        if (connectModeRef.current === "warm") {
          // A pre-warm is still connecting — abandon it and connect fresh
          // rather than leaving the caller waiting on a session that will
          // come up muted. Same "Verbinden…" experience as before
          // pre-warming existed.
          teardown()
        } else {
          return // already connecting/live — ignore a duplicate call
        }
      }
      await runConnect("live", opts)
    },
    [runConnect, activate, teardown]
  )

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

  // Tear down on unmount — no re-arm: leaving /drive means there is no next
  // interaction to prepare for.
  React.useEffect(() => () => teardown(), [teardown])

  return { ...state, start, stop, sendText, prewarm }
}

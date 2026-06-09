"use client"

import * as React from "react"

export type VoiceTutorStatus =
  | "idle" // mic closed
  | "listening" // mic open, waiting for speech
  | "speaking" // user is talking, audio is being captured
  | "transcribing" // sending the captured utterance to /api/transcribe
  | "thinking" // sending the transcript to /api/assistant
  | "error"

type VoiceTutorState = {
  status: VoiceTutorStatus
  transcript: string // last recognised utterance
  answer: string // last tutor answer to display
  error: string | null
}

// Voice-activity detection tuning. We only ever record — and therefore only
// ever call OpenAI — while speech energy is present. Silence never hits the API.
const SPEECH_THRESHOLD = 0.018 // RMS level (0–1) that counts as "speech"
const SILENCE_HANGOVER_MS = 900 // stop recording after this much trailing silence
const MIN_UTTERANCE_MS = 350 // ignore blips shorter than this

const INITIAL: VoiceTutorState = {
  status: "idle",
  transcript: "",
  answer: "",
  error: null,
}

export function useVoiceTutor() {
  const [state, setState] = React.useState<VoiceTutorState>(INITIAL)
  const patch = React.useCallback(
    (partial: Partial<VoiceTutorState>) =>
      setState((prev) => ({ ...prev, ...partial })),
    []
  )

  // Imperative audio plumbing kept in refs so the rAF loop can read it cheaply.
  const streamRef = React.useRef<MediaStream | null>(null)
  const audioCtxRef = React.useRef<AudioContext | null>(null)
  const analyserRef = React.useRef<AnalyserNode | null>(null)
  const recorderRef = React.useRef<MediaRecorder | null>(null)
  const chunksRef = React.useRef<Blob[]>([])
  const rafRef = React.useRef<number | null>(null)
  const speakingRef = React.useRef(false)
  const speechStartRef = React.useRef(0)
  const lastVoiceRef = React.useRef(0)
  const activeRef = React.useRef(false)
  // True while an utterance is mid round-trip — gates barge-in without reading
  // React state inside the rAF loop (which would capture a stale value).
  const processingRef = React.useRef(false)

  const sendUtterance = React.useCallback(
    async (audio: Blob) => {
      processingRef.current = true
      try {
        patch({ status: "transcribing", error: null })
        const form = new FormData()
        form.append("audio", audio, "speech.webm")
        const tRes = await fetch("/api/transcribe", {
          method: "POST",
          body: form,
        })
        if (!tRes.ok) throw new Error((await tRes.json()).error ?? "Transkription fehlgeschlagen")
        const { text } = (await tRes.json()) as { text: string }
        if (!text) {
          // Nothing intelligible — drop back to listening without an API call.
          patch({ status: activeRef.current ? "listening" : "idle" })
          return
        }
        patch({ transcript: text, status: "thinking" })

        const aRes = await fetch("/api/assistant", {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify({ prompt: text }),
        })
        if (!aRes.ok) throw new Error((await aRes.json()).error ?? "Antwort fehlgeschlagen")
        const { content } = (await aRes.json()) as { content: string }
        patch({
          answer: content,
          status: activeRef.current ? "listening" : "idle",
        })
      } catch (err) {
        patch({
          status: "error",
          error: err instanceof Error ? err.message : "Unbekannter Fehler",
        })
      } finally {
        processingRef.current = false
      }
    },
    [patch]
  )

  const startRecorder = React.useCallback(() => {
    const stream = streamRef.current
    if (!stream || recorderRef.current) return
    const recorder = new MediaRecorder(stream)
    chunksRef.current = []
    recorder.ondataavailable = (e) => {
      if (e.data.size > 0) chunksRef.current.push(e.data)
    }
    recorder.onstop = () => {
      const elapsed = performance.now() - speechStartRef.current
      const blob = new Blob(chunksRef.current, { type: recorder.mimeType })
      recorderRef.current = null
      // Skip blips and trailing-silence-only captures: no API call.
      if (elapsed >= MIN_UTTERANCE_MS && blob.size > 0) {
        void sendUtterance(blob)
      } else {
        patch({ status: activeRef.current ? "listening" : "idle" })
      }
    }
    recorder.start()
    recorderRef.current = recorder
  }, [patch, sendUtterance])

  // Holds the latest detection loop so the rAF callback can re-enter it without
  // a self-reference (which the hooks linter forbids).
  const tickRef = React.useRef<() => void>(() => {})

  // The detection loop: measure mic energy and gate recording on speech.
  const tick = React.useCallback(() => {
    const analyser = analyserRef.current
    if (!analyser || !activeRef.current) return
    const buf = new Uint8Array(analyser.fftSize)
    analyser.getByteTimeDomainData(buf)
    let sumSq = 0
    for (let i = 0; i < buf.length; i++) {
      const v = (buf[i] - 128) / 128
      sumSq += v * v
    }
    const rms = Math.sqrt(sumSq / buf.length)
    const now = performance.now()

    if (rms > SPEECH_THRESHOLD) {
      lastVoiceRef.current = now
      // Don't barge in while a previous utterance is still being processed.
      if (!speakingRef.current && !processingRef.current) {
        speakingRef.current = true
        speechStartRef.current = now
        patch({ status: "speaking" })
        startRecorder()
      }
    } else if (
      speakingRef.current &&
      now - lastVoiceRef.current > SILENCE_HANGOVER_MS
    ) {
      // Sustained silence ends the utterance.
      speakingRef.current = false
      recorderRef.current?.stop()
    }

    rafRef.current = requestAnimationFrame(() => tickRef.current())
  }, [patch, startRecorder])

  React.useEffect(() => {
    tickRef.current = tick
  }, [tick])

  const stop = React.useCallback(() => {
    activeRef.current = false
    speakingRef.current = false
    if (rafRef.current) cancelAnimationFrame(rafRef.current)
    rafRef.current = null
    recorderRef.current?.stop()
    recorderRef.current = null
    streamRef.current?.getTracks().forEach((t) => t.stop())
    streamRef.current = null
    void audioCtxRef.current?.close()
    audioCtxRef.current = null
    analyserRef.current = null
    patch({ status: "idle" })
  }, [patch])

  const start = React.useCallback(async () => {
    if (activeRef.current) return
    try {
      patch({ status: "listening", error: null, transcript: "", answer: "" })
      const stream = await navigator.mediaDevices.getUserMedia({ audio: true })
      streamRef.current = stream
      const ctx = new AudioContext()
      audioCtxRef.current = ctx
      const source = ctx.createMediaStreamSource(stream)
      const analyser = ctx.createAnalyser()
      analyser.fftSize = 1024
      source.connect(analyser)
      analyserRef.current = analyser
      activeRef.current = true
      lastVoiceRef.current = performance.now()
      rafRef.current = requestAnimationFrame(() => tickRef.current())
    } catch (err) {
      patch({
        status: "error",
        error:
          err instanceof Error
            ? `Mikrofon nicht verfügbar: ${err.message}`
            : "Mikrofon nicht verfügbar",
      })
    }
  }, [patch])

  // Tear down on unmount.
  React.useEffect(() => () => stop(), [stop])

  return { ...state, start, stop }
}

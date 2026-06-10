"use client"

import * as React from "react"

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
  error: string | null
}

const INITIAL: VoiceTutorState = {
  status: "idle",
  transcript: "",
  answer: "",
  error: null,
}

// Server events arriving on the data channel. Only the fields we read.
type RealtimeEvent = {
  type: string
  transcript?: string
  delta?: string
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
export function useVoiceTutor() {
  const [state, setState] = React.useState<VoiceTutorState>(INITIAL)
  const patch = React.useCallback(
    (partial: Partial<VoiceTutorState>) =>
      setState((prev) => ({ ...prev, ...partial })),
    []
  )

  const pcRef = React.useRef<RTCPeerConnection | null>(null)
  const dcRef = React.useRef<RTCDataChannel | null>(null)
  const streamRef = React.useRef<MediaStream | null>(null)
  const audioRef = React.useRef<HTMLAudioElement | null>(null)

  const teardown = React.useCallback(() => {
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
  }, [])

  const stop = React.useCallback(() => {
    teardown()
    patch({ status: "idle" })
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
          if (event.transcript) patch({ answer: event.transcript })
          break
        case "response.done":
          patch({ status: "listening" })
          break
        case "error":
          patch({
            status: "error",
            error: event.error?.message ?? "Unbekannter Fehler",
          })
          break
      }
    },
    [patch]
  )

  const start = React.useCallback(async () => {
    if (pcRef.current) return
    try {
      patch({ status: "connecting", error: null, transcript: "", answer: "" })

      const tokenRes = await fetch("/api/realtime", { method: "POST" })
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

      // Echo cancellation keeps the tutor's own voice (played over the
      // speakers) from re-entering the mic and interrupting the answer;
      // noise suppression keeps background sounds from triggering the VAD.
      const stream = await navigator.mediaDevices.getUserMedia({
        audio: {
          echoCancellation: true,
          noiseSuppression: true,
          autoGainControl: true,
        },
      })
      streamRef.current = stream

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

  // Tear down on unmount.
  React.useEffect(() => () => teardown(), [teardown])

  return { ...state, start, stop }
}

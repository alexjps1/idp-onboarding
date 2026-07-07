"use client"

import * as React from "react"

import { withBasePath } from "@/lib/base-path"

const POLL_INTERVAL_MS = 2000

type SimulationStartOptions = {
  /** Gate polling — enable once the drive has actually started (left the Eingewöhnungsumgebung). */
  enabled: boolean
  /** Called once, with the ISO timestamp of the first new SILAB packet observed after `enabled` became true. */
  onDetected: (at: string) => void
}

/**
 * Polls /api/simstate every 2 seconds (same cadence as useAdasMonitor) for
 * `receivedAt` — the server-side time SilabServer.java's push last landed at
 * /api/silab-ingest — and calls `onDetected` once, the first time a *new*
 * receivedAt shows up after this hook is enabled. This is "the first real
 * SILAB packet received after the drive started", approximated to within one
 * poll interval. Only fires in SILAB_COMMUNICATION_MODE="api" (what this
 * study runs in) — "tcp" mode has no receivedAt/push concept, so `enabled`
 * simply never observes a change there.
 */
export function useSimulationStart({
  enabled,
  onDetected,
}: SimulationStartOptions) {
  const onDetectedRef = React.useRef(onDetected)
  React.useEffect(() => {
    onDetectedRef.current = onDetected
  })

  React.useEffect(() => {
    if (!enabled) return

    let baseline: number | null = null // receivedAt seen on the first poll after enabling
    let fired = false
    let cancelled = false

    const poll = async () => {
      try {
        const res = await fetch(withBasePath("/api/simstate"), {
          cache: "no-store",
        })
        if (!res.ok) return
        const data = (await res.json()) as { receivedAt?: number | null }
        const receivedAt = data.receivedAt
        if (cancelled || typeof receivedAt !== "number") return

        if (baseline === null) {
          baseline = receivedAt
          return
        }

        if (fired || receivedAt <= baseline) return
        fired = true // resolve at most once
        onDetectedRef.current(new Date(receivedAt).toISOString())
      } catch {
        // Network/parse error → treat as no change and keep polling.
      }
    }

    void poll()
    const id = setInterval(poll, POLL_INTERVAL_MS)
    return () => {
      cancelled = true
      clearInterval(id)
    }
  }, [enabled])
}

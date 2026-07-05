"use client"

import * as React from "react"

import { withBasePath } from "@/lib/base-path"

const POLL_INTERVAL_MS = 2000

type AdasMonitorOptions = {
  /** Gate polling — e.g. only in mit-Tutor mode while the drive view is open. */
  enabled: boolean
  /** Fired once, the first time an inactive→active transition is observed. */
  onActivate: () => void
  /** Return true to drop the trigger (e.g. a conversation is already open). */
  shouldSuppress: () => boolean
}

/**
 * Polls the SILAB driving-automation (ADAS) state via /api/simstate every 2
 * seconds and fires `onActivate` exactly once — the first time it observes
 * the automation flip from inactive to active.
 *
 * The transition must be *observed*: the first successful poll only records a
 * baseline, so an already-active state at mount does not trigger. If
 * `shouldSuppress()` is true at the moment of the edge, the trigger is dropped
 * permanently (it will not fire on a later activation).
 */
export function useAdasMonitor({
  enabled,
  onActivate,
  shouldSuppress,
}: AdasMonitorOptions) {
  // Keep the latest callbacks in refs so the poll loop never goes stale and the
  // interval isn't re-armed on every render.
  const onActivateRef = React.useRef(onActivate)
  const shouldSuppressRef = React.useRef(shouldSuppress)
  React.useEffect(() => {
    onActivateRef.current = onActivate
    shouldSuppressRef.current = shouldSuppress
  })

  React.useEffect(() => {
    if (!enabled) return

    let prevActive: boolean | null = null // null until the first successful poll
    let fired = false
    let cancelled = false

    const poll = async () => {
      try {
        const res = await fetch(withBasePath("/api/simstate"), {
          cache: "no-store",
        })
        if (!res.ok) return
        const data = (await res.json()) as { adas?: { active?: boolean } }
        const active = data.adas?.active
        if (cancelled || typeof active !== "boolean") return

        const wasInactive = prevActive === false
        prevActive = active

        if (fired || !wasInactive || !active) return
        fired = true // fire (or drop) at most once
        if (!shouldSuppressRef.current()) onActivateRef.current()
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

"use client"

import * as React from "react"

/** "suppressed" = the timer elapsed but the assistant was already open; "fired" = it actually opened. */
export type IntroTriggerOutcome = "suppressed" | "fired"

type IntroTriggerOptions = {
  /** Gate the timer — e.g. only in mit-Tutor mode while the drive view is open. */
  enabled: boolean
  /** Delay before firing, in milliseconds. */
  delayMs: number
  /** Called once, after `delayMs` has elapsed, with the outcome. */
  onTrigger: (outcome: IntroTriggerOutcome) => void
  /** Return true to drop the trigger irretrievably (e.g. assistant already open). */
  shouldSuppress: () => boolean
}

/**
 * Calls `onTrigger` exactly once, `delayMs` after the hook is enabled — the
 * one-time self-introduction shortly after the drive view loads. If
 * `shouldSuppress()` is true at the moment the timer elapses, the outcome is
 * "suppressed" and the trigger is dropped permanently (same semantics as
 * use-adas-monitor's onActivate) — otherwise it's "fired".
 */
export function useIntroTrigger({
  enabled,
  delayMs,
  onTrigger,
  shouldSuppress,
}: IntroTriggerOptions) {
  const onTriggerRef = React.useRef(onTrigger)
  const shouldSuppressRef = React.useRef(shouldSuppress)
  React.useEffect(() => {
    onTriggerRef.current = onTrigger
    shouldSuppressRef.current = shouldSuppress
  })

  React.useEffect(() => {
    if (!enabled) return
    const id = setTimeout(() => {
      onTriggerRef.current(shouldSuppressRef.current() ? "suppressed" : "fired")
    }, delayMs)
    return () => clearTimeout(id)
  }, [enabled, delayMs])
}

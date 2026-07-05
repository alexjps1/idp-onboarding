"use client"

import * as React from "react"

import { withBasePath } from "@/lib/base-path"
import {
  ADAS_NUDGE_ZONES,
  SYSTEM_LIMIT_ZONE_BEFORE,
  SYSTEM_LIMIT_ZONE_AFTER,
  pointInZone,
} from "@/lib/track-zones"

const POLL_INTERVAL_MS = 2000

/**
 * "detected" = zone entered, but no tutor action was needed (ADAS already on
 * for a nudge zone; ADAS was off beforehand for the system-limit zone).
 * "suppressed" = action was needed but the assistant was already open.
 * "fired" = action was needed and the tutor actually opened.
 */
export type ZoneOutcome = "detected" | "suppressed" | "fired"

type ZoneTriggerOptions = {
  /** Gate polling — e.g. only in mit-Tutor mode while the drive view is open. */
  enabled: boolean
  /** Called once per nudge zone, at first entry, with the zone index and outcome. */
  onZoneNudge: (index: number, outcome: ZoneOutcome) => void
  /** Called once, at first entry into the after-zone, with the outcome. */
  onSystemLimitExplain: (outcome: ZoneOutcome) => void
  /** Return true to drop a trigger irretrievably (e.g. assistant already open). */
  shouldSuppress: () => boolean
}

/**
 * Polls the SILAB driving state (ADAS status + ego car refPoint) via
 * /api/simstate every 2 seconds and evaluates the fixed track zones from
 * lib/track-zones.ts:
 *
 * - ADAS_NUDGE_ZONES: each zone is checked once, at the moment the car first
 *   enters it — if ADAS is off at that instant, `onZoneNudge` reports "fired"
 *   or "suppressed"; if ADAS is already on, it reports "detected". The zone
 *   is never re-checked afterwards, regardless of the outcome.
 * - SYSTEM_LIMIT_ZONE_BEFORE / _AFTER: the "before" zone snapshots whether
 *   ADAS was active, once, at first entry (not itself reported). The "after"
 *   zone (placed past the DHL-van takeover) calls `onSystemLimitExplain`
 *   once, at first entry: "fired"/"suppressed" if that snapshot was `true`,
 *   "detected" otherwise.
 *
 * Like use-adas-monitor, `shouldSuppress()` drops a trigger permanently if
 * true at the moment its condition is met — it is not retried later.
 */
export function useZoneTriggers({
  enabled,
  onZoneNudge,
  onSystemLimitExplain,
  shouldSuppress,
}: ZoneTriggerOptions) {
  const onZoneNudgeRef = React.useRef(onZoneNudge)
  const onSystemLimitExplainRef = React.useRef(onSystemLimitExplain)
  const shouldSuppressRef = React.useRef(shouldSuppress)
  React.useEffect(() => {
    onZoneNudgeRef.current = onZoneNudge
    onSystemLimitExplainRef.current = onSystemLimitExplain
    shouldSuppressRef.current = shouldSuppress
  })

  React.useEffect(() => {
    if (!enabled) return

    let cancelled = false
    const nudgeResolved = ADAS_NUDGE_ZONES.map(() => false)
    let limitBeforeResolved = false
    let limitAdasWasOn: boolean | null = null
    let limitAfterFired = false

    const poll = async () => {
      try {
        const res = await fetch(withBasePath("/api/simstate"), {
          cache: "no-store",
        })
        if (!res.ok) return
        const data = (await res.json()) as {
          adas?: { active?: boolean }
          trf?: { refPoint?: { x?: number; y?: number } }
        }
        if (cancelled) return
        const active = data.adas?.active
        const x = data.trf?.refPoint?.x
        const y = data.trf?.refPoint?.y
        if (
          typeof active !== "boolean" ||
          typeof x !== "number" ||
          typeof y !== "number"
        ) {
          return
        }

        ADAS_NUDGE_ZONES.forEach((zone, i) => {
          if (nudgeResolved[i] || !pointInZone(x, y, zone)) return
          nudgeResolved[i] = true // checked once, never again — regardless of outcome
          if (!active) {
            onZoneNudgeRef.current(
              i,
              shouldSuppressRef.current() ? "suppressed" : "fired"
            )
          } else {
            onZoneNudgeRef.current(i, "detected")
          }
        })

        if (!limitBeforeResolved && pointInZone(x, y, SYSTEM_LIMIT_ZONE_BEFORE)) {
          limitBeforeResolved = true
          limitAdasWasOn = active
        }

        if (!limitAfterFired && pointInZone(x, y, SYSTEM_LIMIT_ZONE_AFTER)) {
          limitAfterFired = true
          if (limitAdasWasOn) {
            onSystemLimitExplainRef.current(
              shouldSuppressRef.current() ? "suppressed" : "fired"
            )
          } else {
            onSystemLimitExplainRef.current("detected")
          }
        }
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

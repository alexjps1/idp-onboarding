"use client"

import * as React from "react"

import { useStudy, type StudyMode } from "@/components/study/study-provider"
import { withBasePath } from "@/lib/base-path"

/** Maps a study mode back to the route that (re)starts that flow. */
function entryPathForMode(mode: StudyMode | null): string | null {
  if (mode === "onboarding-drive") return "/mittutor"
  if (mode === "onboarding-only") return "/ohnetutor"
  return null
}

/** True when running as an installed home-screen app (iOS or the PWA spec). */
function isStandalone(): boolean {
  if (typeof window === "undefined") return false
  return (
    window.matchMedia?.("(display-mode: standalone)").matches === true ||
    (window.navigator as unknown as { standalone?: boolean }).standalone === true
  )
}

/**
 * The study runs as two installed PWAs (one per mode). Restarting the study on a
 * mere foreground resume would also wipe a run whenever the iPad locks or the user
 * briefly switches apps. So we only restart on a genuine cold launch — i.e. after
 * the app was fully closed (swiped away in the app switcher) or evicted from
 * memory, which makes iOS reload the document and re-run this effect on mount.
 *
 * A warm resume (background → foreground, screen unlock) restores the page from
 * memory without re-running scripts, so this effect does not fire and the run is
 * preserved. On a cold launch iOS may restore the last visited page rather than
 * the start url, so we hard-navigate to the mode's entry route, where
 * {@link StudyEntry} wipes the state and rerolls a fresh participant id.
 *
 * Mounted once in the root layout; renders nothing. Only active in standalone
 * mode, so a normal browser tab is unaffected.
 */
export function PwaRelauncher() {
  const { mode } = useStudy()
  // The mount-time mode (loaded from storage) is all we need: this effect runs
  // once per document load. Held in a ref so it isn't a dependency.
  const modeRef = React.useRef(mode)

  React.useEffect(() => {
    if (!isStandalone()) return
    const entry = entryPathForMode(modeRef.current)
    if (!entry) return
    const target = withBasePath(entry)
    // Already on the entry route → StudyEntry handles the reset; avoid a loop.
    if (window.location.pathname === target) return
    window.location.replace(target)
  }, [])

  return null
}

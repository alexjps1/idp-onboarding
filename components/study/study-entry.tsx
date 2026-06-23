"use client"

import * as React from "react"
import { useRouter } from "next/navigation"

import { useStudy, type StudyMode } from "@/components/study/study-provider"
import { generateParticipantId } from "@/lib/participant"
import { STUDY_STEPS } from "@/lib/study-steps"

/**
 * Headless entry point for a study run. The study is run by many participants on
 * the same tablet, so each run starts clean: the previous participant's stored
 * answers are wiped, the mode is set, a fresh participant id is assigned, then we
 * forward to the first step. Rendered by the /mittutor and /ohnetutor routes.
 */
export function StudyEntry({ mode }: { mode: StudyMode }) {
  const router = useRouter()
  const { setMode, setParticipantId, reset } = useStudy()
  const started = React.useRef(false)

  React.useEffect(() => {
    if (started.current) return
    started.current = true

    // Clear the previous run from localStorage so old answers aren't shown.
    reset()
    setMode(mode)
    setParticipantId(generateParticipantId())
    router.replace(STUDY_STEPS[0].path)
    // Run exactly once on mount; the ref guards against re-entry.
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [])

  return (
    <div className="flex h-screen w-screen items-center justify-center bg-background text-on-surface">
      <p className="label-caps text-on-surface-variant">Studie wird gestartet…</p>
    </div>
  )
}

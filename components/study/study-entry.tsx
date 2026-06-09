"use client"

import * as React from "react"
import { useRouter } from "next/navigation"

import { useStudy, type StudyMode } from "@/components/study/study-provider"
import { generateParticipantId } from "@/lib/participant"
import { STUDY_STEPS } from "@/lib/study-steps"

/**
 * Headless entry point for a study run. Sets the mode, assigns a randomized
 * participant id on first visit (kept if one already exists), then forwards to
 * the first step. Rendered by the /mittutor and /ohnetutor routes.
 */
export function StudyEntry({ mode }: { mode: StudyMode }) {
  const router = useRouter()
  const { participantId, setMode, setParticipantId } = useStudy()
  const started = React.useRef(false)

  React.useEffect(() => {
    if (started.current) return
    started.current = true

    setMode(mode)
    if (!participantId) setParticipantId(generateParticipantId())
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

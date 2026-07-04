"use client"

import * as React from "react"
import { useRouter } from "next/navigation"

import { useStudy, type StudyMode } from "@/components/study/study-provider"
import {
  PARTICIPANT_ID_PATTERN,
  generateUniqueParticipantId,
} from "@/lib/participant"
import { STUDY_STEPS } from "@/lib/study-steps"

/**
 * Headless entry point for a study run. The study is run by many participants on
 * the same tablet, so each run starts clean: the previous participant's stored
 * answers are wiped and the mode is set. Rendered by the /mittutor and
 * /ohnetutor routes.
 *
 * The Probanden-ID comes from the landing page as `pid`. When a valid custom id
 * is supplied we adopt it and forward straight to the first step. Otherwise —
 * empty field, or the route was opened directly — we generate a fresh random id
 * and surface it in a dialog so the study lead can note it (or go back to enter
 * a custom one). The id is only committed once they confirm, so backing out
 * never writes a stray session file.
 */
export function StudyEntry({ mode, pid }: { mode: StudyMode; pid?: string }) {
  const router = useRouter()
  const { setMode, setParticipantId, reset } = useStudy()
  const started = React.useRef(false)
  const [randomId, setRandomId] = React.useState<string | null>(null)

  React.useEffect(() => {
    if (started.current) return
    started.current = true

    // Clear the previous run from localStorage so old answers aren't shown.
    reset()
    setMode(mode)

    const custom = pid?.toUpperCase()
    if (custom && PARTICIPANT_ID_PATTERN.test(custom)) {
      setParticipantId(custom)
      router.replace(STUDY_STEPS[0].path)
      return
    }

    // No (valid) id supplied — generate a collision-free random one and let the
    // study lead confirm via the dialog before committing it.
    void generateUniqueParticipantId().then(setRandomId)
    // Run exactly once on mount; the ref guards against re-entry.
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [])

  function confirmRandom() {
    if (!randomId) return
    setParticipantId(randomId)
    router.replace(STUDY_STEPS[0].path)
  }

  if (randomId) {
    return (
      <div className="flex h-screen w-screen items-center justify-center bg-background px-8 text-on-surface">
        <div className="flex w-full max-w-md flex-col gap-6 rounded-2xl border border-outline-variant bg-surface-container-low p-8 text-center shadow-lg">
          <h2 className="text-xl font-bold tracking-tight">
            Studie ohne Probanden-ID gestartet
          </h2>
          <p className="text-on-surface-variant">
            Es wurde automatisch eine zufällige Probanden-ID generiert:
          </p>
          <p className="data-mono text-3xl tracking-widest text-primary">
            {randomId}
          </p>
          <p className="text-sm text-on-surface-variant">
            Wenn Sie stattdessen eine eigene Probanden-ID vergeben möchten,
            kehren Sie zur Startseite zurück.
          </p>
          <div className="flex flex-col gap-3 sm:flex-row-reverse">
            <button
              type="button"
              onClick={confirmRandom}
              className="rounded-xl bg-primary px-6 py-3 text-base font-semibold text-on-primary transition-opacity hover:opacity-90"
            >
              Fortfahren
            </button>
            <button
              type="button"
              onClick={() => router.push("/")}
              className="rounded-xl border border-outline-variant bg-surface-container-low px-6 py-3 text-base font-semibold transition-colors hover:bg-surface-variant"
            >
              Zurück zur Startseite
            </button>
          </div>
        </div>
      </div>
    )
  }

  return (
    <div className="flex h-screen w-screen items-center justify-center bg-background text-on-surface">
      <p className="label-caps text-on-surface-variant">Studie wird gestartet…</p>
    </div>
  )
}

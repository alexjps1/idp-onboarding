"use client"

import * as React from "react"
import { useRouter } from "next/navigation"

import { Button } from "@/components/ui/button"
import {
  Card,
  CardContent,
  CardDescription,
  CardFooter,
  CardHeader,
  CardTitle,
} from "@/components/ui/card"
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
      <div className="flex h-screen w-screen items-center justify-center bg-background p-6">
        <Card className="w-full max-w-2xl">
          <CardHeader>
            <CardTitle>Studie ohne Probanden-ID gestartet</CardTitle>
            <CardDescription>
              Es wurde automatisch eine zufällige Probanden-ID generiert. Wenn
              Sie stattdessen eine eigene ID vergeben möchten, kehren Sie zur
              Startseite zurück.
            </CardDescription>
          </CardHeader>
          <CardContent>
            <span className="font-mono text-5xl font-semibold tracking-wide">
              {randomId}
            </span>
          </CardContent>
          <CardFooter className="gap-3">
            <Button
              variant="outline"
              size="lg"
              onClick={() => router.push("/")}
              className="h-14 flex-1 text-xl"
            >
              Zurück zur Startseite
            </Button>
            <Button
              size="lg"
              onClick={confirmRandom}
              className="h-14 flex-1 text-xl"
            >
              Fortfahren
            </Button>
          </CardFooter>
        </Card>
      </div>
    )
  }

  return (
    <div className="flex h-screen w-screen items-center justify-center bg-background">
      <p className="text-xl text-muted-foreground">Studie wird gestartet…</p>
    </div>
  )
}

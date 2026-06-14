"use client"

import * as React from "react"

import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { ASSISTANCE_SYSTEMS } from "@/lib/assistance-systems"
import { useStudy } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"
import { LikertMatrix } from "@/components/study/likert-matrix"

const SCALE = [
  "keins",
  "sehr wenig",
  "wenig",
  "eher wenig",
  "eher viel",
  "viel",
  "sehr viel",
]

export default function TheoryAssessmentPage() {
  const { theory, setTheory } = useStudy()
  const { previous, next } = getAdjacentSteps("self-assessment-theory")

  // The matrix is index-based; map rows to system names for persistence.
  const answers = React.useMemo<Record<number, number>>(() => {
    const out: Record<number, number> = {}
    ASSISTANCE_SYSTEMS.forEach((system, index) => {
      if (theory[system.name] != null) out[index] = theory[system.name]
    })
    return out
  }, [theory])

  const answered = Object.keys(answers).length
  const total = ASSISTANCE_SYSTEMS.length

  return (
    <StudyShell
      progress={getStepProgress("self-assessment-theory")}
      footer={
        <StudyFooter
          prevHref={previous?.path}
          nextHref={next?.path}
          nextDisabled={answered < total}
        />
      }
    >
      <div className="mx-auto flex h-full w-full max-w-6xl flex-col">
        <header className="mb-5 shrink-0">
          <div className="mb-2 flex items-center justify-between">
            <span className="label-caps tracking-[0.2em] text-primary">
              Theoretisches Wissen
            </span>
            <span className="data-mono text-[14px] text-secondary">
              {answered} von {total} beantwortet
            </span>
          </div>
          <h1 className="text-xl font-bold tracking-tight">
            Wie viel theoretisches Wissen (z.&nbsp;B. über Artikel, Videos, etc.)
            haben Sie über die folgenden Fahrerassistenzsysteme?
          </h1>
        </header>

        <LikertMatrix
          className="min-h-0 flex-1"
          fillHeight
          scaleLabels={SCALE}
          systems={ASSISTANCE_SYSTEMS}
          answers={answers}
          onChange={(rowIndex, value) =>
            setTheory(ASSISTANCE_SYSTEMS[rowIndex].name, value)
          }
        />
      </div>
    </StudyShell>
  )
}

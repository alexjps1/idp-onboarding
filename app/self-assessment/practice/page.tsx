"use client"

import * as React from "react"

import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { ASSISTANCE_SYSTEMS } from "@/lib/assistance-systems"
import { useStudy } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"
import { LikertMatrix } from "@/components/study/likert-matrix"

const SCALE = [
  "keine",
  "sehr wenig",
  "wenig",
  "eher wenig",
  "eher viel",
  "viel",
  "sehr viel",
]

export default function PracticeAssessmentPage() {
  const { practice, setPractice } = useStudy()
  const { previous, next } = getAdjacentSteps("self-assessment-practice")

  // The matrix is index-based; map rows to system names for persistence.
  const answers = React.useMemo<Record<number, number>>(() => {
    const out: Record<number, number> = {}
    ASSISTANCE_SYSTEMS.forEach((system, index) => {
      if (practice[system.name] != null) out[index] = practice[system.name]
    })
    return out
  }, [practice])

  const answered = Object.keys(answers).length
  const total = ASSISTANCE_SYSTEMS.length

  return (
    <StudyShell
      progress={getStepProgress("self-assessment-practice")}
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
              Praktische Erfahrung
            </span>
            <span className="data-mono text-[14px] text-secondary">
              {answered} von {total} beantwortet
            </span>
          </div>
          <h1 className="text-xl font-bold tracking-tight">
            Wie viel praktische Erfahrung haben Sie mit den folgenden
            Fahrerassistenzsystemen?
          </h1>
        </header>

        <LikertMatrix
          className="min-h-0 flex-1"
          fillHeight
          scaleLabels={SCALE}
          systems={ASSISTANCE_SYSTEMS}
          answers={answers}
          onChange={(rowIndex, value) =>
            setPractice(ASSISTANCE_SYSTEMS[rowIndex].name, value)
          }
        />
      </div>
    </StudyShell>
  )
}

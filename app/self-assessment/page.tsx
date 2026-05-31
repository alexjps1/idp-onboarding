"use client"

import * as React from "react"

import { cn } from "@/lib/utils"
import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"
import { LikertScale } from "@/components/study/likert-scale"

const SYSTEMS = [
  "Verkehrszeichenassistent",
  "Abstandsregeltempomat",
  "Ampelerkennung",
  "Spurführungsassistent",
  "Notbremsassistent",
]

type Answers = Record<string, number>

export default function SelfAssessmentPage() {
  const [answers, setAnswers] = React.useState<Answers>({})
  const { previous, next } = getAdjacentSteps("self-assessment")

  const totalQuestions = SYSTEMS.length * 2
  const answeredCount = Object.keys(answers).length

  function setAnswer(key: string, value: number) {
    setAnswers((prev) => ({ ...prev, [key]: value }))
  }

  return (
    <StudyShell
      progress={getStepProgress("self-assessment")}
      footer={
        <StudyFooter
          prevHref={previous?.path}
          nextHref={next?.path}
          nextDisabled={answeredCount < totalQuestions}
        />
      }
    >
      <div className="mx-auto max-w-5xl">
        <header className="mb-12">
          <div className="mb-2 flex items-center justify-between">
            <span className="label-caps tracking-[0.2em] text-primary">
              Participant ID: 8821
            </span>
            <span className="data-mono text-[14px] text-secondary">
              Schritt {answeredCount} von {totalQuestions} beantwortet
            </span>
          </div>
          <h1 className="text-[32px] leading-10 font-bold tracking-tight">
            Deine Erfahrung mit Assistenzsystemen
          </h1>
          <p className="mt-2 max-w-2xl text-on-surface-variant">
            Bitte bewerten Sie Ihre Kenntnisse und Ihre praktische Anwendung der
            folgenden Systeme auf einer Skala von 1 (keine Erfahrung) bis 5
            (Experte).
          </p>
        </header>

        <div className="overflow-hidden rounded-xl border border-outline-variant bg-surface-container-low">
          {/* Column headers */}
          <div className="grid grid-cols-[2fr_1.5fr_1.5fr] border-b border-outline-variant bg-surface-container">
            <div className="border-r border-outline-variant p-6 label-caps text-on-surface-variant">
              Assistenzsystem
            </div>
            <div className="border-r border-outline-variant p-6 text-center label-caps text-on-surface-variant">
              Theoretisches Wissen
            </div>
            <div className="p-6 text-center label-caps text-on-surface-variant">
              Praktische Erfahrung
            </div>
          </div>

          {/* Rows */}
          {SYSTEMS.map((system, index) => {
            const theoryKey = `theory_${index + 1}`
            const practicalKey = `practical_${index + 1}`
            return (
              <div
                key={system}
                className={cn(
                  "grid grid-cols-[2fr_1.5fr_1.5fr] items-center border-b border-outline-variant last:border-0",
                  index % 2 === 1 && "bg-surface-container/50"
                )}
              >
                <div className="border-r border-outline-variant p-6 text-lg text-on-surface">
                  {system}
                </div>
                <div className="border-r border-outline-variant p-6">
                  <LikertScale
                    name={theoryKey}
                    value={answers[theoryKey] ?? null}
                    onChange={(value) => setAnswer(theoryKey, value)}
                  />
                </div>
                <div className="p-6">
                  <LikertScale
                    name={practicalKey}
                    value={answers[practicalKey] ?? null}
                    onChange={(value) => setAnswer(practicalKey, value)}
                  />
                </div>
              </div>
            )
          })}
        </div>
      </div>
    </StudyShell>
  )
}

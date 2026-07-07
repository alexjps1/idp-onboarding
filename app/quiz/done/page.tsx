"use client"

import * as React from "react"
import { ArrowRight, Car, PartyPopper } from "lucide-react"

import { getAdjacentSteps } from "@/lib/study-steps"
import { useStudy } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"

/**
 * Congratulation screen shown once the quiz has been fully answered. When a
 * drive follows it doubles as the "Willkommen im Fahrzeug" lead-in to the drive;
 * for the onboarding-only condition it simply hands off to the final screen.
 */
export default function QuizDonePage() {
  const { mode } = useStudy()
  const { next } = getAdjacentSteps("quiz-done", mode)
  const toDrive = next?.slug === "drive"

  const heading = toDrive ? "Willkommen im Fahrzeug!" : "Herzlichen Glückwunsch!"
  const paragraphs = toDrive
    ? [
        "Herzlichen Glückwunsch – Sie haben alle Fragen richtig beantwortet!",
        "Testen Sie nun das teilautomatisierte Fahren für mehr Sicherheit und Komfort. Viel Spaß!",
      ]
    : ["Sie haben alle Fragen richtig beantwortet."]

  return (
    <StudyShell
      footer={
        <StudyFooter
          nextHref={next?.path}
          nextLabel={toDrive ? "Zur Fahrt wechseln" : "Zum Abschluss"}
          nextIcon={toDrive ? <Car /> : <ArrowRight />}
        />
      }
    >
      <div className="mx-auto flex w-full max-w-2xl flex-col items-center gap-8 text-center">
        <div className="flex size-24 items-center justify-center rounded-full border-2 border-primary/20 bg-card">
          <PartyPopper className="size-12 text-primary" strokeWidth={1.5} />
        </div>

        <div className="space-y-4">
          <h1 className="text-4xl font-bold tracking-tight text-foreground sm:text-5xl">
            {heading}
          </h1>
          <div className="space-y-3 text-xl leading-relaxed text-muted-foreground">
            {paragraphs.map((paragraph) => (
              <p key={paragraph}>{paragraph}</p>
            ))}
          </div>
        </div>
      </div>
    </StudyShell>
  )
}

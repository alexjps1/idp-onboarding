"use client"

import { useRouter } from "next/navigation"
import { ArrowRight, Check, PartyPopper } from "lucide-react"

import { getAdjacentSteps } from "@/lib/study-steps"
import { useStudy } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"

/**
 * Congratulation screen shown once the quiz has been fully answered. Pressing
 * the button stamps the onboarding-end timestamp (see
 * StudyProvider.markOnboardingEnded) and hands off to the next step — the
 * "Willkommen im Fahrzeug" drive lead-in when a drive follows, or the final
 * screen in the onboarding-only condition.
 */
export default function QuizDonePage() {
  const router = useRouter()
  const { mode, markOnboardingEnded } = useStudy()
  const { next } = getAdjacentSteps("quiz-done", mode)
  const driveFollows = next?.slug === "drive-welcome"

  const paragraph = driveFollows
    ? "Sie haben nun alle Fragen richtig beantwortet! Testen Sie nun das teilautomatisierte Fahren für mehr Sicherheit und Komfort. Viel Spaß!"
    : "Sie haben alle Fragen richtig beantwortet."

  function handleContinue() {
    markOnboardingEnded()
    if (next) router.push(next.path)
  }

  return (
    <StudyShell
      footer={
        <StudyFooter
          nextLabel={driveFollows ? "OK" : "Zum Abschluss"}
          nextIcon={driveFollows ? <Check /> : <ArrowRight />}
          onNext={handleContinue}
        />
      }
    >
      <div className="mx-auto flex w-full max-w-2xl flex-col items-center gap-8 text-center">
        <div className="flex size-24 items-center justify-center rounded-full border-2 border-primary/20 bg-card">
          <PartyPopper className="size-12 text-primary" strokeWidth={1.5} />
        </div>

        <div className="space-y-4">
          <h1 className="text-4xl font-bold tracking-tight text-foreground sm:text-5xl">
            Herzlichen Glückwunsch!
          </h1>
          <p className="text-xl leading-relaxed text-muted-foreground">
            {paragraph}
          </p>
        </div>
      </div>
    </StudyShell>
  )
}

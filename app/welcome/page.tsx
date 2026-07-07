"use client"

import * as React from "react"
import { useRouter } from "next/navigation"
import { ArrowRight } from "lucide-react"

import { getAdjacentSteps } from "@/lib/study-steps"
import { useStudy } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { Button } from "@/components/ui/button"

/**
 * Welcome / intro screen shown at the start of the onboarding flow. Introduces
 * the tutorial and hands off to the self-assessment. Pressing "Anpassung
 * starten" stamps the study-begin timestamp (see StudyProvider.markStarted).
 */
export default function WelcomePage() {
  const router = useRouter()
  const { mode, markStarted } = useStudy()
  const { next } = getAdjacentSteps("welcome", mode)

  // Drive-only (Nur Fahrt) has no self-assessment or adaptation — it goes
  // straight into the drive, so its intro copy and CTA differ.
  const isDriveOnly = mode === "drive-only"
  const paragraphs = isDriveOnly
    ? [
        "In dieser Fahrt erleben Sie, wie Sie die wichtigsten Assistenzsysteme dieses teilautomatisierten Fahrzeugs sicher und effizient nutzen – praxisnah und direkt im Fahrzeug.",
        "Ihr Tutor begleitet Sie während der Fahrt und unterstützt Sie bei allen Fragen rund um die Assistenzsysteme.",
      ]
    : [
        "Dieses Tutorial zeigt Ihnen, wie Sie die wichtigsten Assistenzsysteme dieses teilautomatisierten Fahrzeugs sicher und effizient nutzen – kompakt, praxisnah und direkt im Fahrzeug.",
        "Damit Sie nur die Informationen erhalten, die für Sie relevant sind, wird dieses Tutorial an Ihren Wissensstand angepasst. Geben Sie dazu im nächsten Schritt bitte eine kurze Einschätzung ab.",
      ]
  const buttonLabel = isDriveOnly ? "Zur Fahrt" : "Anpassung starten"

  function handleStart() {
    markStarted()
    if (next) router.push(next.path)
  }

  return (
    <StudyShell>
      <div className="mx-auto flex w-full max-w-3xl flex-col items-center gap-8 text-center">
        <h1 className="text-4xl font-bold tracking-tight sm:text-5xl">
          Willkommen im Fahrzeug!
        </h1>

        <div className="space-y-5 text-xl leading-relaxed text-muted-foreground">
          {paragraphs.map((paragraph) => (
            <p key={paragraph}>{paragraph}</p>
          ))}
        </div>

        <Button
          size="lg"
          onClick={handleStart}
          className="mt-2 h-14 px-10 text-xl [&_svg]:size-6"
        >
          {buttonLabel}
          <ArrowRight />
        </Button>
      </div>
    </StudyShell>
  )
}

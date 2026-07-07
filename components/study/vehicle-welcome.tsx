"use client"

import { ArrowRight } from "lucide-react"

import { StudyShell } from "@/components/study/study-shell"
import { Button } from "@/components/ui/button"

/**
 * "Willkommen im Fahrzeug!" drive lead-in copy. Shared so the drive-only
 * welcome (the very first screen of the /nurfahrt condition) and the
 * post-onboarding drive hand-off show the identical greeting.
 */
export const DRIVE_WELCOME_PARAGRAPHS = [
  "In dieser Fahrt erleben Sie, wie Sie die wichtigsten Assistenzsysteme dieses teilautomatisierten Fahrzeugs sicher und effizient nutzen – praxisnah und direkt im Fahrzeug.",
  "Ihr Tutor begleitet Sie während der Fahrt und unterstützt Sie bei allen Fragen rund um die Assistenzsysteme.",
]

type VehicleWelcomeProps = {
  paragraphs: string[]
  buttonLabel: string
  onStart: () => void
}

/**
 * The "Willkommen im Fahrzeug!" welcome screen: a centered heading, a short
 * intro and a single primary CTA. The heading is fixed; callers supply the
 * body copy and the button label/handler for their step.
 */
export function VehicleWelcome({
  paragraphs,
  buttonLabel,
  onStart,
}: VehicleWelcomeProps) {
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
          onClick={onStart}
          className="mt-2 h-14 px-10 text-xl [&_svg]:size-6"
        >
          {buttonLabel}
          <ArrowRight />
        </Button>
      </div>
    </StudyShell>
  )
}

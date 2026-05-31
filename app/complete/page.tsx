"use client"

import { useRouter } from "next/navigation"
import { CheckCircle2, Info } from "lucide-react"

import { useStudy } from "@/components/study/study-provider"
import { StudyTopBar } from "@/components/study/study-top-bar"
import { StudyButton } from "@/components/study/study-button"

export default function CompletePage() {
  const router = useRouter()
  const { participantId, reset } = useStudy()

  function restart() {
    reset()
    router.push("/consent")
  }

  return (
    <div className="relative flex h-screen w-screen flex-col overflow-hidden bg-background text-on-surface">
      {/* Atmospheric background */}
      <div className="pointer-events-none fixed inset-0 overflow-hidden">
        <div className="absolute -top-1/4 -right-1/4 size-[800px] rounded-full bg-primary/5 blur-[120px]" />
        <div className="absolute -bottom-1/4 -left-1/4 size-[600px] rounded-full bg-secondary/5 blur-[100px]" />
      </div>

      <StudyTopBar />

      <main className="relative flex flex-1 flex-col items-center justify-center px-margin-tablet text-center">
        {/* Success orb */}
        <div className="relative mb-12">
          <div className="orb-glow flex size-32 items-center justify-center rounded-full border-2 border-primary/20 bg-surface-container-lowest">
            <CheckCircle2 className="size-16 text-primary" strokeWidth={1.5} />
          </div>
          <div className="absolute inset-0 scale-150 rounded-full border border-primary/10 opacity-20" />
        </div>

        <div className="space-y-6">
          <h1 className="text-[32px] leading-10 font-bold tracking-tight text-primary">
            Onboarding erfolgreich abgeschlossen
          </h1>

          <div className="inline-flex items-center rounded-full border border-outline-variant bg-surface-container-high px-6 py-2 shadow-sm">
            <span className="mr-3 label-caps text-secondary">
              Participant ID:
            </span>
            <span className="data-mono text-on-surface">
              {participantId ?? "PB-8821"}
            </span>
          </div>

          <p className="mx-auto max-w-xl text-lg leading-relaxed text-on-surface-variant">
            Vielen Dank für deine Teilnahme. Bitte wende dich nun an die
            Studienleitung.
          </p>
        </div>

        <div className="mt-16 flex flex-col items-center gap-stack-gap">
          <StudyButton
            type="button"
            onClick={restart}
            className="h-16 rounded-xl px-12 text-2xl font-semibold"
          >
            Studie neu starten
          </StudyButton>
          <div className="mt-4 flex items-center gap-2 text-on-surface-variant/60">
            <Info className="size-4" />
            <span className="label-caps text-[12px]">
              Modus A: Scientific Validation Core
            </span>
          </div>
        </div>
      </main>

      {/* Aesthetic footer rule */}
      <footer className="pointer-events-none fixed bottom-12 flex w-full justify-center">
        <div className="flex gap-4 opacity-20">
          <div className="h-px w-24 bg-gradient-to-r from-transparent via-primary to-transparent" />
          <div className="h-px w-4 bg-primary" />
          <div className="h-px w-24 bg-gradient-to-l from-transparent via-primary to-transparent" />
        </div>
      </footer>
    </div>
  )
}

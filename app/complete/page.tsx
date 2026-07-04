"use client"

import { useRouter } from "next/navigation"
import { CheckCircle2, Info } from "lucide-react"

import { useStudy } from "@/components/study/study-provider"
import { StudyTopBar } from "@/components/study/study-top-bar"
import { Button } from "@/components/ui/button"

export default function CompletePage() {
  const router = useRouter()
  const { participantId, mode, reset } = useStudy()

  function restart() {
    reset()
    router.push("/")
  }

  // The participant group the run belonged to, derived from the study mode.
  const groupLabel =
    mode === "onboarding-drive"
      ? "Probandengruppe „Onboarding + Tutor“"
      : mode === "onboarding-only"
        ? "Probandengruppe „nur Onboarding“"
        : null

  return (
    <div className="relative flex h-screen w-screen flex-col overflow-hidden bg-background text-foreground">
      {/* Atmospheric background */}
      <div className="pointer-events-none fixed inset-0 overflow-hidden">
        <div className="absolute -top-1/4 -right-1/4 size-[800px] rounded-full bg-primary/5 blur-[120px]" />
        <div className="absolute -bottom-1/4 -left-1/4 size-[600px] rounded-full bg-primary/5 blur-[100px]" />
      </div>

      <StudyTopBar />

      <main className="relative flex flex-1 flex-col items-center justify-center px-margin-tablet text-center">
        {/* Success orb */}
        <div className="relative mb-12">
          <div className="orb-glow flex size-32 items-center justify-center rounded-full border-2 border-primary/20 bg-card">
            <CheckCircle2 className="size-16 text-primary" strokeWidth={1.5} />
          </div>
          <div className="absolute inset-0 scale-150 rounded-full border border-primary/10 opacity-20" />
        </div>

        <div className="space-y-6">
          <h1 className="text-[32px] leading-10 font-bold tracking-tight text-foreground">
            Onboarding erfolgreich abgeschlossen
          </h1>

          <div className="inline-flex items-center rounded-full border bg-card px-6 py-2 shadow-sm">
            <span className="mr-3 text-sm text-muted-foreground">
              Probanden-ID:
            </span>
            <span className="font-mono text-foreground">
              {participantId ?? "RAND0000"}
            </span>
          </div>

          <p className="mx-auto max-w-xl text-lg leading-relaxed text-muted-foreground">
            Vielen Dank für deine Teilnahme. Bitte wende dich nun an die
            Studienleitung.
          </p>
        </div>

        <div className="mt-16 flex flex-col items-center gap-4">
          <Button
            type="button"
            size="lg"
            onClick={restart}
            className="h-12 rounded-xl px-10 text-base"
          >
            Studie neu starten
          </Button>
          {groupLabel ? (
            <div className="mt-4 flex items-center gap-2 text-muted-foreground">
              <Info className="size-4" />
              <span className="text-xs">{groupLabel}</span>
            </div>
          ) : null}
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

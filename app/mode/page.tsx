"use client"

import { GraduationCap, Cpu, CheckCircle2, Settings } from "lucide-react"

import { cn } from "@/lib/utils"
import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { useStudy, type StudyMode } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"

type ModeOption = {
  id: StudyMode
  icon: typeof GraduationCap
  title: string
  description: string
  duration: string
  accent: "secondary" | "primary"
}

const MODES: ModeOption[] = [
  {
    id: "onboarding-only",
    icon: GraduationCap,
    title: "Onboarding & Fahrt (ohne Tutor)",
    description:
      "Sie durchlaufen das Onboarding und fahren anschließend im Simulator.",
    duration: "Dauer: 45 Min.",
    accent: "secondary",
  },
  {
    id: "onboarding-drive",
    icon: Cpu,
    title: "Onboarding & Fahrt (mit Tutor)",
    description:
      "Vollständiges Programm inklusive begleiteter Fahrt im Simulator.",
    duration: "Dauer: 45 Min.",
    accent: "primary",
  },
]

export default function ModePage() {
  const { mode, setMode } = useStudy()
  const { previous, next } = getAdjacentSteps("mode")

  return (
    <StudyShell
      progress={getStepProgress("mode")}
      topBarActions={
        <button
          type="button"
          className="rounded-full p-2 text-primary transition-colors hover:bg-surface-variant"
          aria-label="Einstellungen"
        >
          <Settings className="size-5" />
        </button>
      }
      footer={
        <StudyFooter
          prevHref={previous?.path}
          nextHref={next?.path}
          nextDisabled={mode === null}
        />
      }
    >
      <div className="mx-auto w-full max-w-5xl space-y-6">
        <div className="space-y-2">
          <h1 className="text-2xl font-bold tracking-tight">
            Willkommen zur Studie zu KI-Tutor für Fahrzeugassistenzsysteme
          </h1>
          <p className="max-w-2xl text-on-surface-variant">
            Bitte wählen Sie den gewünschten Studienmodus aus, um mit dem
            Protokoll fortzufahren. Ihre Auswahl beeinflusst die nachfolgenden
            Testphasen.
          </p>
        </div>

        <div className="grid grid-cols-1 gap-6 md:grid-cols-2">
          {MODES.map((option) => {
            const Icon = option.icon
            const selected = mode === option.id
            return (
              <button
                key={option.id}
                type="button"
                onClick={() => setMode(option.id)}
                className={cn(
                  "group flex cursor-pointer flex-col gap-4 rounded-xl p-6 text-left transition-all duration-300 active:scale-[0.98]",
                  selected
                    ? "border-2 border-primary bg-surface-container-lowest shadow-[0_10px_25px_-5px_rgba(0,107,95,0.1)]"
                    : "border border-outline-variant bg-surface-container-low hover:bg-surface-variant"
                )}
              >
                <span
                  className={cn(
                    "flex size-14 items-center justify-center rounded-full",
                    option.accent === "primary"
                      ? "bg-primary/10 text-primary"
                      : "bg-secondary/10 text-secondary"
                  )}
                >
                  <Icon className="size-7" />
                </span>
                <div className="space-y-2">
                  <h2 className="text-xl font-semibold transition-colors group-hover:text-primary">
                    {option.title}
                  </h2>
                  <p className="text-sm leading-relaxed text-on-surface-variant">
                    {option.description}
                  </p>
                </div>
                <div className="mt-auto flex items-center justify-between border-t border-outline-variant pt-4">
                  <span className="label-caps text-on-surface-variant">
                    {option.duration}
                  </span>
                  <CheckCircle2
                    className={cn(
                      "size-6 text-primary transition-opacity",
                      selected ? "opacity-100" : "opacity-0"
                    )}
                    fill="currentColor"
                    stroke="var(--surface-container-lowest)"
                  />
                </div>
              </button>
            )
          })}
        </div>
      </div>
    </StudyShell>
  )
}

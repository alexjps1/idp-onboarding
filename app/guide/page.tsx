import {
  Brain,
  ShieldCheck,
  TrafficCone,
  Gauge,
  CheckCircle2,
  TriangleAlert,
  Power,
  Ban,
  CirclePlay,
  Car,
} from "lucide-react"

import { cn } from "@/lib/utils"
import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"
import { AccordionItem } from "@/components/study/accordion"

const BASICS = [
  {
    icon: Power,
    title: "Aktivierung",
    text: "Hebel am Lenkrad 2x zu sich ziehen. Bestätigung durch blaues Icon im HUD.",
    tone: "secondary" as const,
  },
  {
    icon: Ban,
    title: "Deaktivierung",
    text: "Bremspedal antippen oder Deaktivierungstaste am Lenkrad drücken.",
    tone: "secondary" as const,
  },
  {
    icon: TriangleAlert,
    title: "Verantwortung",
    text: "Sie bleiben jederzeit voll verantwortlich. Hände müssen am Lenkrad bleiben.",
    tone: "error" as const,
  },
]

function Badge({
  children,
  variant,
}: {
  children: React.ReactNode
  variant: "primary" | "muted"
}) {
  return (
    <span
      className={cn(
        "ml-4 rounded border px-2 py-1 text-[10px] font-bold tracking-wider uppercase",
        variant === "primary"
          ? "border-primary/20 bg-primary/10 text-primary"
          : "border-transparent bg-on-surface-variant/10 text-on-surface-variant"
      )}
    >
      {children}
    </span>
  )
}

export default function GuidePage() {
  const { previous, next } = getAdjacentSteps("guide")

  return (
    <StudyShell
      progress={getStepProgress("guide")}
      footer={
        <StudyFooter
          prevHref={previous?.path}
          nextHref={next?.path}
          nextLabel="Zur Fahrt wechseln"
          nextIcon={<Car />}
          nextAdornment={
            <div className="text-right">
              <p className="label-caps text-on-surface-variant">
                Modus B: Testfahrt
              </p>
              <p className="data-mono text-[10px] tracking-[0.2em] text-primary/60 uppercase">
                Ready to Proceed
              </p>
            </div>
          }
        />
      }
    >
      <div className="relative mx-auto max-w-4xl space-y-12">
        {/* Atmospheric glow */}
        <div className="pointer-events-none fixed inset-0 -z-10 overflow-hidden">
          <div className="absolute -top-[10%] -right-[10%] size-[600px] rounded-full bg-primary/5 blur-[120px]" />
          <div className="absolute -bottom-[5%] left-[10%] size-[400px] rounded-full bg-secondary/5 blur-[100px]" />
        </div>

        {/* Header */}
        <section>
          <h1 className="mb-2 text-[32px] leading-10 font-bold tracking-tight text-primary">
            Dein persönlicher Onboarding-Guide
          </h1>
          <div className="flex items-center gap-2">
            <span className="h-1 w-12 rounded-full bg-primary" />
            <span className="h-1 w-32 rounded-full bg-surface-variant" />
            <p className="ml-4 data-mono text-on-surface-variant">
              Progress: Adaptive Review
            </p>
          </div>
        </section>

        {/* Section 1 — adaptive systems */}
        <section className="space-y-stack-gap">
          <div className="mb-6 flex items-center gap-3">
            <Brain className="size-6 text-secondary" />
            <h2 className="text-2xl font-semibold">
              Abschnitt 1: Adaptive Systeme
            </h2>
          </div>
          <div className="space-y-4">
            <AccordionItem
              icon={<TrafficCone className="size-6" />}
              title="Ampelerkennung"
              badge={<Badge variant="primary">Hoher Erklärungsbedarf</Badge>}
              defaultOpen
              highlight
            >
              <div className="grid grid-cols-1 gap-8 pt-4 md:grid-cols-2">
                <div className="space-y-4">
                  <p className="leading-relaxed text-on-surface-variant">
                    Da Sie in der Selbsteinschätzung angegeben haben, wenig
                    Erfahrung mit assistiertem Fahren an Kreuzungen zu haben, hier
                    die Details:
                  </p>
                  <ul className="space-y-3">
                    <li className="flex items-start gap-3">
                      <CheckCircle2 className="mt-1 size-4 shrink-0 text-primary" />
                      <span className="text-on-surface">
                        Das System erkennt rote und grüne Signalgeber mittels
                        Frontkamera und Lidar.
                      </span>
                    </li>
                    <li className="flex items-start gap-3">
                      <CheckCircle2 className="mt-1 size-4 shrink-0 text-primary" />
                      <span className="text-on-surface">
                        Bei &apos;Gelb&apos; erfolgt eine akustische Warnung zur
                        Übernahmebereitschaft.
                      </span>
                    </li>
                    <li className="flex items-start gap-3">
                      <TriangleAlert className="mt-1 size-4 shrink-0 text-error" />
                      <span className="font-medium text-error">
                        Abbiegepfeile werden in der aktuellen Softwareversion 1.0
                        noch nicht unterstützt.
                      </span>
                    </li>
                  </ul>
                </div>
                {/* Video still */}
                <div className="relative h-48 overflow-hidden rounded-xl border border-outline-variant bg-gradient-to-br from-surface-container-high to-surface-container shadow-sm">
                  <div className="absolute inset-0 bg-primary/5" />
                  <div className="absolute inset-0 flex items-center justify-center">
                    <CirclePlay className="size-12 text-primary drop-shadow" />
                  </div>
                  <span className="absolute bottom-3 left-3 label-caps text-[10px] text-on-surface-variant">
                    HUD · Ampelerkennung
                  </span>
                </div>
              </div>
            </AccordionItem>

            <AccordionItem
              icon={<Gauge className="size-6" />}
              title="Notbremsassistent"
              badge={<Badge variant="muted">Standard Review</Badge>}
            >
              <p className="pt-4 text-on-surface-variant">
                Das AEB-System ist permanent aktiv und greift bei drohenden
                Kollisionen autonom ein. Es erfordert keine zusätzliche
                Konfiguration für Ihre Fahrt.
              </p>
            </AccordionItem>
          </div>
        </section>

        {/* Section 2 — universal basics */}
        <section className="space-y-stack-gap">
          <div className="mb-6 flex items-center gap-3">
            <ShieldCheck className="size-6 text-secondary" />
            <h2 className="text-2xl font-semibold">
              Abschnitt 2: Universelle Grundlagen
            </h2>
          </div>
          <div className="grid grid-cols-1 gap-6 md:grid-cols-3">
            {BASICS.map(({ icon: Icon, title, text, tone }) => (
              <div
                key={title}
                className={cn(
                  "group cursor-pointer rounded-xl border border-outline-variant bg-surface-container-high p-6 transition-all",
                  tone === "error"
                    ? "hover:border-error"
                    : "hover:border-secondary"
                )}
              >
                <div
                  className={cn(
                    "mb-4 flex size-12 items-center justify-center rounded-lg transition-colors",
                    tone === "error"
                      ? "bg-error/10 text-error group-hover:bg-error/20"
                      : "bg-secondary/10 text-secondary group-hover:bg-secondary/20"
                  )}
                >
                  <Icon className="size-7" />
                </div>
                <h3 className="mb-2 text-2xl font-semibold">{title}</h3>
                <p className="text-sm text-on-surface-variant">{text}</p>
              </div>
            ))}
          </div>
        </section>

        <div className="h-12" />
      </div>
    </StudyShell>
  )
}

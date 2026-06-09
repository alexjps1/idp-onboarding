"use client"

import * as React from "react"
import { BookOpen, Car, Loader2, Sparkles, TriangleAlert } from "lucide-react"

import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { ONBOARDING_MODULES } from "@/lib/onboarding-modules"
import { useStudy } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"

type AdaptedSection = {
  id: string
  title: string
  paragraphs: string[]
  omitted?: boolean
}

type AdaptStatus = "loading" | "adapted" | "baseline"

export default function GuidePage() {
  const { previous, next } = getAdjacentSteps("guide")
  const { theory, practice } = useStudy()

  const [sections, setSections] = React.useState<Map<string, AdaptedSection>>(
    new Map()
  )
  const [status, setStatus] = React.useState<AdaptStatus>("loading")

  // Snapshot the ratings once on mount so the fetch isn't refired on every
  // store change. The Fragebogen is already complete by the time we reach here.
  const ratingsRef = React.useRef({ theory, practice })

  React.useEffect(() => {
    const controller = new AbortController()

    async function adapt() {
      const { theory: th, practice: pr } = ratingsRef.current
      const systems = new Set([...Object.keys(th), ...Object.keys(pr)])
      const knowledge: Record<string, { theory?: number; practice?: number }> =
        {}
      systems.forEach((name) => {
        knowledge[name] = { theory: th[name], practice: pr[name] }
      })

      try {
        // Only the Fahrzeugassistenzsysteme are adapted; the fixed intro/outro
        // and safety modules (alwaysKeep) are rendered verbatim and not sent.
        const adaptable = ONBOARDING_MODULES.filter((m) => !m.alwaysKeep)
        const res = await fetch("/api/onboarding", {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify({ modules: adaptable, knowledge }),
          signal: controller.signal,
        })
        if (!res.ok) {
          // 501 (no key) or upstream error → render the baseline as-is.
          setStatus("baseline")
          return
        }
        const data = (await res.json()) as { sections: AdaptedSection[] }
        setSections(new Map(data.sections.map((s) => [s.id, s])))
        setStatus("adapted")
      } catch (err) {
        if ((err as Error).name !== "AbortError") setStatus("baseline")
      }
    }

    void adapt()
    return () => controller.abort()
  }, [])

  return (
    <StudyShell
      progress={getStepProgress("guide")}
      mainClassName="justify-start"
      footer={
        <StudyFooter
          prevHref={previous?.path}
          nextHref={next?.path}
          nextLabel="Zur Fahrt wechseln"
          nextIcon={<Car />}
        />
      }
    >
      <div className="mx-auto flex h-full w-full max-w-3xl flex-col">
        {/* Header */}
        <header className="mb-4 flex items-center gap-3">
          <span className="flex size-10 shrink-0 items-center justify-center rounded-xl bg-primary/10 text-primary">
            <BookOpen className="size-5" />
          </span>
          <div className="flex-1">
            <h1 className="text-2xl font-bold tracking-tight text-on-surface">
              Modulhandbuch
            </h1>
            <p className="text-sm text-on-surface-variant">
              Teilautomatisiertes Fahren – Funktionen der Assistenzsysteme
            </p>
          </div>
          <AdaptBadge status={status} />
        </header>

        {/* Scrollable handbook */}
        <div className="study-scrollbar min-h-0 flex-1 space-y-4 overflow-y-auto pr-2">
          {ONBOARDING_MODULES.map((module, index) => {
            // Safety-critical content is always rendered verbatim.
            const adapted = module.alwaysKeep
              ? undefined
              : sections.get(module.id)

            if (adapted?.omitted) return null

            const paragraphs =
              adapted && adapted.paragraphs.length
                ? adapted.paragraphs
                : module.paragraphs

            return (
              <section
                key={module.id}
                className={
                  module.warning
                    ? "rounded-xl border border-error/40 bg-error/5 p-5"
                    : "rounded-xl border border-outline-variant bg-surface-container-low p-5"
                }
              >
                <div className="mb-3 flex items-center gap-3">
                  <span
                    className={
                      module.warning
                        ? "flex size-7 shrink-0 items-center justify-center rounded-lg bg-error/10 text-error"
                        : "flex size-7 shrink-0 items-center justify-center rounded-lg bg-primary/10 data-mono text-[12px] text-primary"
                    }
                  >
                    {module.warning ? (
                      <TriangleAlert className="size-4" />
                    ) : (
                      String(index + 1).padStart(2, "0")
                    )}
                  </span>
                  <h2 className="text-lg font-semibold text-on-surface">
                    {module.title}
                  </h2>
                </div>
                <div className="space-y-2 text-sm leading-relaxed text-on-surface-variant">
                  {paragraphs.map((text, i) => (
                    <p key={i}>{text}</p>
                  ))}
                  {module.bullets ? (
                    <ul className="list-disc space-y-1 pl-5">
                      {module.bullets.map((bullet) => (
                        <li key={bullet}>{bullet}</li>
                      ))}
                    </ul>
                  ) : null}
                </div>
              </section>
            )
          })}
        </div>
      </div>
    </StudyShell>
  )
}

function AdaptBadge({ status }: { status: AdaptStatus }) {
  if (status === "loading") {
    return (
      <span className="flex items-center gap-2 rounded-full border border-outline-variant bg-surface-container-highest px-3 py-1.5 text-[12px] text-on-surface-variant">
        <Loader2 className="size-3.5 animate-spin" />
        Wird an Ihr Vorwissen angepasst…
      </span>
    )
  }
  if (status === "adapted") {
    return (
      <span className="flex items-center gap-2 rounded-full border border-outline-variant bg-surface-container-highest px-3 py-1.5 text-[12px] text-primary">
        <Sparkles className="size-3.5" />
        An Ihr Vorwissen angepasst
      </span>
    )
  }
  return null
}

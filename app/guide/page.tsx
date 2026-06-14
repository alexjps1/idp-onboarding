"use client"

import * as React from "react"
import { BookOpen, Car, Loader2, Sparkles, TriangleAlert } from "lucide-react"

import { cn } from "@/lib/utils"
import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { ONBOARDING_MODULES } from "@/lib/onboarding-modules"
import { useStudy } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"

type AdaptedSection = {
  id: string
  title: string
  paragraphs: { text: string; gifs?: string[] }[]
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
  const [current, setCurrent] = React.useState(0)

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

  // Resolve the visible sections first: omitted ones are cut entirely, so the
  // roadmap always shows a contiguous 1, 2, 3, … over what actually remains.
  const visibleSections = React.useMemo(
    () =>
      ONBOARDING_MODULES.flatMap((module) => {
        // Safety-critical content is always rendered verbatim.
        const adapted = module.alwaysKeep ? undefined : sections.get(module.id)
        if (adapted?.omitted) return []
        const paragraphs =
          adapted && adapted.paragraphs.length
            ? adapted.paragraphs
            : module.paragraphs
        return [{ module, paragraphs }]
      }),
    [sections]
  )

  // Clamp in case the adaptation removes sections while the user is browsing.
  const index = Math.min(current, visibleSections.length - 1)
  const active = visibleSections[index]
  const isFirst = index === 0
  const isLast = index === visibleSections.length - 1

  return (
    <StudyShell
      progress={getStepProgress("guide")}
      mainClassName="justify-start"
      footer={
        <StudyFooter
          prevHref={isFirst ? previous?.path : undefined}
          onPrev={isFirst ? undefined : () => setCurrent(index - 1)}
          nextHref={isLast ? next?.path : undefined}
          onNext={isLast ? undefined : () => setCurrent(index + 1)}
          nextLabel={isLast ? "Zur Fahrt wechseln" : "Weiter"}
          nextIcon={isLast ? <Car /> : undefined}
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

        {/* Roadmap: one numbered stop per visible section. Already-read
            sections are clickable to jump back; upcoming ones are locked. */}
        <nav aria-label="Module" className="mb-6 flex items-center px-1">
          {visibleSections.map(({ module }, i) => (
            <React.Fragment key={module.id}>
              {i > 0 ? (
                <span
                  className={cn(
                    "h-px flex-1",
                    i <= index ? "bg-primary" : "bg-outline-variant"
                  )}
                />
              ) : null}
              <button
                type="button"
                onClick={() => setCurrent(i)}
                disabled={i > index}
                aria-current={i === index ? "step" : undefined}
                aria-label={module.title}
                title={module.title}
                className={cn(
                  "data-mono flex size-9 shrink-0 items-center justify-center rounded-full border text-[13px] transition-colors",
                  i === index
                    ? "border-primary bg-primary text-on-primary"
                    : i < index
                      ? "border-primary bg-primary/10 text-primary hover:bg-primary/20"
                      : "border-outline-variant bg-surface-container-low text-on-surface-variant"
                )}
              >
                {i + 1}
              </button>
            </React.Fragment>
          ))}
        </nav>

        {/* Only the current section is shown. */}
        {active ? (
          <div className="study-scrollbar min-h-0 flex-1 overflow-y-auto pr-2">
            <section
              key={active.module.id}
              className={
                active.module.warning
                  ? "rounded-xl border border-error/40 bg-error/5 p-6"
                  : "rounded-xl border border-outline-variant bg-surface-container-low p-6"
              }
            >
              <div className="mb-4 flex items-center gap-3">
                <span
                  className={
                    active.module.warning
                      ? "flex size-8 shrink-0 items-center justify-center rounded-lg bg-error/10 text-error"
                      : "data-mono flex size-8 shrink-0 items-center justify-center rounded-lg bg-primary/10 text-[13px] text-primary"
                  }
                >
                  {active.module.warning ? (
                    <TriangleAlert className="size-4" />
                  ) : (
                    index + 1
                  )}
                </span>
                <h2 className="text-xl font-semibold text-on-surface">
                  {active.module.title}
                </h2>
                <span className="data-mono ml-auto text-[12px] text-on-surface-variant">
                  {index + 1} / {visibleSections.length}
                </span>
              </div>
              <div className="space-y-4 text-[15px] leading-relaxed text-on-surface-variant">
                {active.paragraphs.map((para, i) => (
                  <div key={i}>
                    <p>{para.text}</p>
                    {para.gifs && para.gifs.length > 0 ? (
                      <div className="mt-3 flex gap-3">
                        {para.gifs.map((gif) => (
                          <img
                            key={gif}
                            src={`/gifs/${gif}`}
                            alt=""
                            className={cn(
                              "rounded-lg object-contain",
                              para.gifs!.length === 1
                                ? "mx-auto max-h-52"
                                : "max-h-44 min-w-0 flex-1"
                            )}
                          />
                        ))}
                      </div>
                    ) : null}
                  </div>
                ))}
                {active.module.bullets ? (
                  <ul className="list-disc space-y-3 pl-5">
                    {active.module.bullets.map((bullet) => (
                      <li key={bullet.text}>
                        {bullet.text}
                        {bullet.gif ? (
                          <img
                            src={`/gifs/${bullet.gif}`}
                            alt=""
                            className="mt-2 max-h-40 rounded-lg object-contain"
                          />
                        ) : null}
                      </li>
                    ))}
                  </ul>
                ) : null}
              </div>
            </section>
          </div>
        ) : null}
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

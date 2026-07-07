"use client"

import * as React from "react"
import { BookOpen, ClipboardList, Loader2, Sparkles, TriangleAlert } from "lucide-react"

import { cn } from "@/lib/utils"
import { withBasePath } from "@/lib/base-path"
import { getAdjacentSteps } from "@/lib/study-steps"
import { ONBOARDING_MODULES } from "@/lib/onboarding-modules"
import { useStudy } from "@/components/study/study-provider"
import type { AdaptedSection } from "@/lib/study-data"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"
import { Card, CardContent } from "@/components/ui/card"

type AdaptStatus = "loading" | "adapted" | "baseline"

export default function GuidePage() {
  const { mode, theory, practice, setAdaptedModules } = useStudy()
  const { previous, next } = getAdjacentSteps("guide", mode)

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
        const res = await fetch(withBasePath("/api/onboarding"), {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify({ modules: adaptable, knowledge }),
          signal: controller.signal,
        })
        if (!res.ok || !res.body) {
          // 501 (no key) or upstream error → render the baseline as-is.
          setStatus("baseline")
          setAdaptedModules(null, "baseline")
          return
        }

        // The route streams one newline-delimited JSON object per module as it
        // is adapted. We collect all sections silently and only apply them once
        // the full response has been received, so the user sees the loading
        // screen until everything is ready — no flickering chapter swaps.
        const order = new Map(adaptable.map((m, i) => [m.id, i]))
        const collected: AdaptedSection[] = []
        const collect = (section?: AdaptedSection) => {
          if (!section) return
          collected.push(section)
        }

        const reader = res.body.getReader()
        const decoder = new TextDecoder()
        let buffer = ""
        for (;;) {
          const { done, value } = await reader.read()
          if (done) break
          buffer += decoder.decode(value, { stream: true })
          let nl: number
          while ((nl = buffer.indexOf("\n")) !== -1) {
            const line = buffer.slice(0, nl).trim()
            buffer = buffer.slice(nl + 1)
            if (line) collect(parseSection(line))
          }
        }
        if (buffer.trim()) collect(parseSection(buffer.trim()))

        collected.sort(
          (a, b) => (order.get(a.id) ?? 0) - (order.get(b.id) ?? 0)
        )

        // Apply all adapted sections at once so they are immediately available
        // when we flip from the loading screen to the guide content.
        const allSections = new Map<string, AdaptedSection>()
        for (const s of collected) allSections.set(s.id, s)
        setSections(allSections)

        setStatus("adapted")
        setAdaptedModules(collected, "adapted")
      } catch (err) {
        if ((err as Error).name !== "AbortError") {
          setStatus("baseline")
          setAdaptedModules(null, "baseline")
        }
      }
    }

    void adapt()
    return () => controller.abort()
    // Runs once on mount; ratings are snapshotted via ratingsRef and
    // setAdaptedModules is a stable store action.
    // eslint-disable-next-line react-hooks/exhaustive-deps
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

  // Top fade-out that ramps in with scroll: the card only dissolves into the
  // roadmap once the user actually scrolls, so at rest (scrollTop 0) the top
  // edge stays crisp. Capped at 2rem (32px).
  const scrollRef = React.useRef<HTMLDivElement>(null)
  const [fadePx, setFadePx] = React.useState(0)

  // Reset to the top whenever the chapter changes. Scrolling to the top fires
  // onScroll, which zeroes the fade, so no extra state update is needed here.
  React.useEffect(() => {
    scrollRef.current?.scrollTo({ top: 0 })
  }, [index])

  // ── Loading screen ──────────────────────────────────────────────────
  if (status === "loading") {
    return (
      <StudyShell mainClassName="justify-center pb-0">
        <div className="mx-auto flex max-w-lg flex-col items-center gap-8 text-center">
          <div className="relative flex size-20 items-center justify-center">
            {/* Outer pulsing ring */}
            <span className="absolute inset-0 animate-ping rounded-full bg-primary/10" />
            {/* Inner spinner container */}
            <span className="relative flex size-20 items-center justify-center rounded-full bg-primary/10">
              <Loader2 className="size-9 animate-spin text-primary" />
            </span>
          </div>

          <div className="space-y-3">
            <h1 className="text-4xl font-semibold tracking-tight text-foreground">
              Bitte warten
            </h1>
            <p className="text-xl leading-relaxed text-muted-foreground">
              Personalisierte Inhalte werden für Sie vorbereitet&nbsp;…
            </p>
          </div>
        </div>
      </StudyShell>
    )
  }

  // ── Guide content (shown after loading is complete) ─────────────────
  return (
    <StudyShell
      mainClassName="justify-start pb-0"
      footer={
        <StudyFooter
          prevHref={isFirst ? previous?.path : undefined}
          onPrev={isFirst ? undefined : () => setCurrent(index - 1)}
          nextHref={isLast ? next?.path : undefined}
          onNext={isLast ? undefined : () => setCurrent(index + 1)}
          nextLabel={isLast ? "Zum Wissenstest" : "Weiter"}
          nextIcon={isLast ? <ClipboardList /> : undefined}
        />
      }
    >
      <div className="guide-fade-in mx-auto flex h-full w-full max-w-4xl flex-col">
        {/* Header */}
        <header className="mb-4 flex items-center gap-3">
          <span className="flex size-10 shrink-0 items-center justify-center rounded-xl bg-primary/10 text-primary">
            <BookOpen className="size-5" />
          </span>
          <div className="flex-1">
            <h1 className="text-4xl font-bold tracking-tight text-foreground">
              Modulhandbuch
            </h1>
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
                    i <= index ? "bg-primary" : "bg-border"
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
                  "flex size-11 shrink-0 items-center justify-center rounded-full border text-lg font-medium transition-colors",
                  i === index
                    ? "border-primary bg-primary text-primary-foreground"
                    : i < index
                      ? "border-primary bg-primary/10 text-primary hover:bg-primary/20"
                      : "border-border bg-muted text-muted-foreground"
                )}
              >
                {i + 1}
              </button>
            </React.Fragment>
          ))}
        </nav>

        {/* Only the current section is shown. */}
        {active ? (
          // The whole card scrolls as a unit and dissolves into the roadmap
          // above via the top fade mask on this scroll viewport. The card keeps
          // its rounded corners, but since it is taller than the viewport its
          // rounded bottom stays off-screen while scrolling (a straight cut at
          // the bottom bar) and only appears once the true end is reached.
          // Horizontal padding keeps the card's ring from being clipped.
          <div
            ref={scrollRef}
            onScroll={(e) =>
              setFadePx(Math.min(e.currentTarget.scrollTop, 32))
            }
            style={
              fadePx > 0
                ? {
                    maskImage: `linear-gradient(to bottom, transparent, black ${fadePx}px)`,
                    WebkitMaskImage: `linear-gradient(to bottom, transparent, black ${fadePx}px)`,
                  }
                : undefined
            }
            className="study-scrollbar min-h-0 flex-1 overflow-y-auto px-2 pt-2 pb-4"
          >
            <Card
              key={active.module.id}
              className={cn(
                active.module.warning && "bg-destructive/5 ring-destructive/30"
              )}
            >
              <CardContent className="px-10">
                <div className="mb-4 flex items-center gap-3">
                  <span
                    className={
                      active.module.warning
                        ? "flex size-10 shrink-0 items-center justify-center rounded-lg bg-destructive/10 text-destructive"
                        : "flex size-10 shrink-0 items-center justify-center rounded-lg bg-primary/10 text-lg font-medium text-primary"
                    }
                  >
                    {active.module.warning ? (
                      <TriangleAlert className="size-5" />
                    ) : (
                      index + 1
                    )}
                  </span>
                  <h2 className="text-3xl font-semibold text-foreground">
                    {active.module.title}
                  </h2>
                  <span className="ml-auto text-lg text-muted-foreground">
                    {index + 1} / {visibleSections.length}
                  </span>
                </div>
                <div className="space-y-4 text-[22px] leading-relaxed text-muted-foreground">
                  {active.paragraphs.map((para, i) => (
                    <div key={i}>
                      <p>{para.text}</p>
                      {para.gifs && para.gifs.length > 0 ? (
                        <div className="mt-3 flex gap-3">
                          {para.gifs.map((gif) => (
                            <img
                              key={gif}
                              src={withBasePath(`/gifs/${gif}`)}
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
                              src={withBasePath(`/gifs/${bullet.gif}`)}
                              alt=""
                              className="mt-2 max-h-40 rounded-lg object-contain"
                            />
                          ) : null}
                        </li>
                      ))}
                    </ul>
                  ) : null}
                </div>
              </CardContent>
            </Card>
          </div>
        ) : null}
      </div>
    </StudyShell>
  )
}

/** Parses one streamed NDJSON line into a section, ignoring malformed lines. */
function parseSection(line: string): AdaptedSection | undefined {
  try {
    return (JSON.parse(line) as { section?: AdaptedSection }).section
  } catch {
    return undefined
  }
}

function AdaptBadge({ status }: { status: AdaptStatus }) {
  if (status === "loading") {
    return (
      <span className="flex items-center gap-2 rounded-full border bg-muted px-3 py-1.5 text-base text-muted-foreground">
        <Loader2 className="size-4 animate-spin" />
        Wird an Ihr Vorwissen angepasst…
      </span>
    )
  }
  if (status === "adapted") {
    return (
      <span className="flex items-center gap-2 rounded-full border bg-muted px-3 py-1.5 text-base text-primary">
        <Sparkles className="size-4" />
        An Ihr Vorwissen angepasst
      </span>
    )
  }
  return null
}

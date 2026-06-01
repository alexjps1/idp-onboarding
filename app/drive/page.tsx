"use client"

import * as React from "react"
import {
  Music,
  Navigation,
  Phone,
  Sparkles,
  LayoutGrid,
  X,
} from "lucide-react"

import { cn } from "@/lib/utils"
import { getAdjacentSteps } from "@/lib/study-steps"
import { StudyTopBar } from "@/components/study/study-top-bar"
import { StudyFooter } from "@/components/study/study-footer"

const SIDEBAR_APPS = [
  { icon: Music, label: "Medien" },
  { icon: Navigation, label: "Navigation" },
  { icon: Phone, label: "Telefon" },
  { icon: Sparkles, label: "Assistent" },
]

export default function DrivePage() {
  const [assistantOpen, setAssistantOpen] = React.useState(false)
  const { previous, next } = getAdjacentSteps("drive")

  return (
    <div className="cockpit flex h-screen w-screen flex-col overflow-hidden bg-background text-on-surface">
      <StudyTopBar />

      <div className="flex flex-grow overflow-hidden">
        {/* App launcher sidebar */}
        <aside className="z-40 flex w-24 shrink-0 flex-col items-center gap-8 border-r border-outline-variant bg-surface-container-low py-8">
          {SIDEBAR_APPS.map(({ icon: Icon, label }) => {
            const isAssistant = label === "Assistent"
            const active = isAssistant && assistantOpen
            return (
              <button
                key={label}
                type="button"
                aria-label={label}
                aria-pressed={isAssistant ? assistantOpen : undefined}
                onClick={
                  isAssistant
                    ? () => setAssistantOpen((open) => !open)
                    : undefined
                }
                className={cn(
                  "flex size-14 items-center justify-center rounded-2xl transition-all",
                  active
                    ? "bg-primary-container text-on-primary-container shadow-lg shadow-primary/20"
                    : isAssistant
                      ? "text-primary hover:bg-surface-variant/50"
                      : "text-on-surface-variant opacity-40 hover:bg-surface-variant/50"
                )}
              >
                <Icon className="size-7" />
              </button>
            )
          })}
          <button
            type="button"
            aria-label="Alle Apps"
            className="mt-auto flex size-14 items-center justify-center rounded-2xl text-on-surface-variant opacity-40 transition-colors hover:bg-surface-variant/50"
          >
            <LayoutGrid className="size-7" />
          </button>
        </aside>

        {/* Cockpit center */}
        <main className="relative flex flex-grow flex-col items-center justify-center bg-background">
          <div className="flex flex-col items-center gap-12 text-center">
            <div className="flex flex-col items-center">
              <span className="text-[120px] leading-none font-bold tracking-tight text-on-surface">
                100
              </span>
              <span className="mt-2 label-caps tracking-[0.2em] text-on-surface-variant">
                km/h
              </span>
            </div>

            <div className="flex items-center gap-4 rounded-full border border-outline-variant/30 bg-surface-container px-8 py-3">
              <span className="relative flex items-center justify-center">
                <span className="size-2.5 rounded-full bg-primary" />
                <span className="absolute inset-0 animate-ping rounded-full bg-primary opacity-40" />
              </span>
              <span className="label-caps text-[14px] tracking-wider text-primary">
                Tutor aktiv
              </span>
            </div>
          </div>

          {/* Voice assistant popup — circular voice visualisation */}
          {assistantOpen ? (
            <div className="absolute inset-0 z-50 flex flex-col items-center justify-center gap-10 bg-background/70 backdrop-blur-md">
              <button
                type="button"
                onClick={() => setAssistantOpen(false)}
                aria-label="Sprachassistent schließen"
                className="absolute top-8 right-8 flex size-12 items-center justify-center rounded-full bg-surface-container text-on-surface-variant transition-colors hover:bg-surface-variant"
              >
                <X className="size-6" />
              </button>

              {/* Pulsing circle visualiser — tap to end */}
              <button
                type="button"
                onClick={() => setAssistantOpen(false)}
                aria-label="Sprachassistent beenden"
                className="relative flex size-64 items-center justify-center outline-none"
              >
                <span className="absolute inset-0 animate-ping rounded-full bg-primary/15" />
                <span className="absolute inset-6 animate-pulse rounded-full bg-primary/25" />
                <div className="relative flex size-40 items-center justify-center rounded-full bg-primary-container shadow-[0_0_60px_rgba(45,212,191,0.45)] transition-transform hover:scale-105 active:scale-95">
                  <div className="flex h-14 items-end gap-1.5">
                    {[0.1, 0.35, 0.2, 0.5, 0.3].map((delay, i) => (
                      <span
                        key={i}
                        className="wave-bar w-1.5 rounded-full bg-on-primary-container"
                        style={{ animationDelay: `${delay}s` }}
                      />
                    ))}
                  </div>
                </div>
              </button>

              <div className="text-center">
                <p className="label-caps tracking-[0.2em] text-primary">
                  Ich höre zu…
                </p>
                <p className="mt-2 text-lg text-on-surface italic">
                  &quot;Wie funktioniert die Ampelerkennung?&quot;
                </p>
              </div>
            </div>
          ) : null}
        </main>
      </div>

      {/* Action bar — shared study footer for consistency */}
      <StudyFooter prevHref={previous?.path} nextHref={next?.path} />
    </div>
  )
}

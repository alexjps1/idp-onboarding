"use client"

import * as React from "react"
import Link from "next/link"
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
import { StudyButton } from "@/components/study/study-button"

const SIDEBAR_APPS = [
  { icon: Music, label: "Medien", active: false },
  { icon: Navigation, label: "Navigation", active: false },
  { icon: Phone, label: "Telefon", active: false },
  { icon: Sparkles, label: "Assistent", active: true },
]

const SUGGESTIONS = ['"Nächste Ausfahrt?"', '"Ladezeit berechnen"']

export default function DrivePage() {
  const [voiceVisible, setVoiceVisible] = React.useState(true)
  const { previous, next } = getAdjacentSteps("drive")

  return (
    <div className="cockpit flex h-screen w-screen flex-col overflow-hidden bg-background text-on-surface">
      <StudyTopBar />

      <div className="flex flex-grow overflow-hidden">
        {/* App launcher sidebar */}
        <aside className="z-40 flex w-24 shrink-0 flex-col items-center gap-8 border-r border-outline-variant bg-surface-container-low py-8">
          {SIDEBAR_APPS.map(({ icon: Icon, label, active }) => (
            <button
              key={label}
              type="button"
              aria-label={label}
              className={cn(
                "flex size-14 items-center justify-center rounded-2xl transition-all",
                active
                  ? "bg-primary-container text-on-primary-container shadow-lg shadow-primary/20"
                  : "text-on-surface-variant opacity-40 hover:bg-surface-variant/50"
              )}
            >
              <Icon className="size-7" />
            </button>
          ))}
          <button
            type="button"
            aria-label="Alle Apps"
            className="mt-auto flex size-14 items-center justify-center rounded-2xl text-on-surface-variant transition-colors hover:bg-surface-variant"
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
                Teilautomatisiert aktiv
              </span>
            </div>
          </div>

          {/* Voice agent overlay */}
          {voiceVisible ? (
            <div className="absolute bottom-10 left-1/2 w-full max-w-xl -translate-x-1/2 px-4">
              <div className="flex items-center rounded-full border border-primary/10 bg-surface/50 p-2 shadow-2xl backdrop-blur-md">
                <div className="relative flex size-12 shrink-0 items-center justify-center overflow-hidden rounded-full bg-primary-container">
                  <div className="flex h-6 items-end gap-0.5">
                    {[0.1, 0.3, 0.2, 0.5].map((delay, i) => (
                      <span
                        key={i}
                        className="wave-bar w-0.5 rounded-full bg-on-primary-container"
                        style={{ animationDelay: `${delay}s` }}
                      />
                    ))}
                  </div>
                </div>
                <div className="flex-grow px-6">
                  <div className="mb-0.5 label-caps text-[10px] tracking-[0.2em] text-primary">
                    Ich höre zu…
                  </div>
                  <div className="truncate text-on-surface italic">
                    &quot;Wie funktioniert die Ampelerkennung?&quot;
                  </div>
                </div>
                <button
                  type="button"
                  onClick={() => setVoiceVisible(false)}
                  aria-label="Sprachassistent schließen"
                  className="flex size-10 items-center justify-center rounded-full text-on-surface-variant transition-colors hover:bg-surface-variant"
                >
                  <X className="size-5" />
                </button>
              </div>
              <div className="mt-4 flex justify-center gap-3">
                {SUGGESTIONS.map((suggestion) => (
                  <span
                    key={suggestion}
                    className="rounded-full border border-outline-variant/20 bg-surface-container/50 px-3 py-1 label-caps text-[11px] text-on-surface-variant opacity-60"
                  >
                    {suggestion}
                  </span>
                ))}
              </div>
            </div>
          ) : null}
        </main>
      </div>

      {/* Action bar */}
      <footer className="z-50 flex h-20 w-full shrink-0 items-center justify-between border-t border-outline-variant bg-surface-container px-margin-tablet">
        <StudyButton asChild variant="muted">
          <Link href={previous?.path ?? "/"}>Previous</Link>
        </StudyButton>
        <div className="h-1 w-48 overflow-hidden rounded-full bg-surface-variant">
          <div className="h-full w-full bg-primary" />
        </div>
        <StudyButton asChild variant="primary">
          <Link href={next?.path ?? "/"}>Next Phase</Link>
        </StudyButton>
      </footer>
    </div>
  )
}

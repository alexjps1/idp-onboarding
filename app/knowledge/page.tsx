"use client"

import * as React from "react"
import { Brain } from "lucide-react"

import { cn } from "@/lib/utils"
import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"

const QUESTION =
  "Welche Aufgabe behält der Fahrer bei einem SAE Level 2 System primär?"

const OPTIONS = [
  { id: "A", text: "Überwachung des Systems und ständige Bremsbereitschaft." },
  { id: "B", text: "Volle Verantwortung für die Umgebungserfassung." },
  { id: "C", text: "Eingreifen nur bei akustischer Warnung." },
  { id: "D", text: "Das System übernimmt die volle Haftung." },
]

const TOTAL_MODULES = 6
const CURRENT_MODULE = 4

export default function KnowledgePage() {
  const [selected, setSelected] = React.useState<string | null>(null)
  const { previous, next } = getAdjacentSteps("knowledge")

  return (
    <StudyShell
      topBarLabel="Adaptive Quiz"
      progress={getStepProgress("knowledge")}
      mainClassName="flex flex-col items-center"
      footer={
        <StudyFooter
          prevHref={previous?.path}
          nextHref={next?.path}
          nextDisabled={selected === null}
          nextAdornment={
            <div className="hidden flex-col items-center gap-1 md:flex">
              <div className="flex gap-1">
                {Array.from({ length: TOTAL_MODULES }, (_, i) => (
                  <span
                    key={i}
                    className={cn(
                      "size-2 rounded-full",
                      i < CURRENT_MODULE ? "bg-primary" : "bg-outline-variant"
                    )}
                  />
                ))}
              </div>
              <span className="data-mono text-[10px] text-on-surface-variant">
                Module {CURRENT_MODULE}/{TOTAL_MODULES}
              </span>
            </div>
          }
        />
      }
    >
      {/* Adaptive badge */}
      <div className="mb-8 flex items-center gap-2 rounded-full border border-outline-variant bg-surface-container-highest px-4 py-1.5">
        <Brain className="size-[18px] text-primary" />
        <span className="label-caps text-[12px] text-primary">
          Auf dich zugeschnitten
        </span>
      </div>

      {/* Question */}
      <div className="mb-12 w-full max-w-3xl text-center">
        <span className="mb-4 block data-mono text-sm text-on-surface-variant">
          Frage 1 von {TOTAL_MODULES}
        </span>
        <h1 className="text-[32px] leading-tight font-bold tracking-tight text-on-surface">
          {QUESTION}
        </h1>
      </div>

      {/* Answers */}
      <div className="grid w-full max-w-4xl grid-cols-1 gap-6 px-gutter md:grid-cols-2">
        {OPTIONS.map((option) => {
          const isSelected = selected === option.id
          return (
            <button
              key={option.id}
              type="button"
              onClick={() => setSelected(option.id)}
              className={cn(
                "group flex items-start gap-5 rounded-xl border p-6 text-left transition-all duration-300 active:scale-[0.98]",
                isSelected
                  ? "border-primary bg-surface-container-lowest shadow-[0_0_20px_rgba(0,107,95,0.1)]"
                  : "border-outline bg-surface-container hover:border-primary/50"
              )}
            >
              <span
                className={cn(
                  "flex size-8 shrink-0 items-center justify-center rounded-full border-2 transition-all",
                  isSelected
                    ? "border-primary bg-primary"
                    : "border-outline-variant group-hover:border-primary"
                )}
              >
                <span
                  className={cn(
                    "size-4 rounded-full bg-on-primary transition-opacity",
                    isSelected ? "opacity-100" : "opacity-0"
                  )}
                />
              </span>
              <span className="flex flex-col">
                <span className="mb-1 label-caps text-[12px] text-primary">
                  Option {option.id}
                </span>
                <span className="text-lg leading-snug text-on-surface">
                  {option.text}
                </span>
              </span>
            </button>
          )
        })}
      </div>
    </StudyShell>
  )
}

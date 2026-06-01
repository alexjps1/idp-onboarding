"use client"

import * as React from "react"
import { Brain } from "lucide-react"
import { RadioGroup as RadioGroupPrimitive } from "radix-ui"

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

export default function KnowledgePage() {
  const [selected, setSelected] = React.useState<string | null>(null)
  const { previous, next } = getAdjacentSteps("knowledge")

  return (
    <StudyShell
      topBarLabel="Adaptives Quiz"
      progress={getStepProgress("knowledge")}
      mainClassName="items-center"
      footer={
        <StudyFooter
          prevHref={previous?.path}
          nextHref={next?.path}
          nextDisabled={selected === null}
        />
      }
    >
      {/* Adaptive badge */}
      <div className="mb-5 flex items-center gap-2 self-center rounded-full border border-outline-variant bg-surface-container-highest px-4 py-1.5">
        <Brain className="size-[18px] text-primary" />
        <span className="label-caps text-[12px] text-primary">
          Auf dich zugeschnitten
        </span>
      </div>

      {/* Question */}
      <div className="mb-6 w-full max-w-3xl self-center text-center">
        <span className="mb-3 block data-mono text-sm text-on-surface-variant">
          Frage 1 von {TOTAL_MODULES}
        </span>
        <h1 className="text-2xl font-bold tracking-tight text-on-surface">
          {QUESTION}
        </h1>
      </div>

      {/* Answers */}
      <RadioGroupPrimitive.Root
        value={selected ?? undefined}
        onValueChange={setSelected}
        aria-label="Antwortmöglichkeiten"
        className="grid w-full max-w-4xl grid-cols-1 gap-4 self-center md:grid-cols-2"
      >
        {OPTIONS.map((option) => {
          const isSelected = selected === option.id
          return (
            <RadioGroupPrimitive.Item
              key={option.id}
              value={option.id}
              className={cn(
                "group flex items-start gap-5 rounded-xl border p-5 text-left transition-all duration-300 outline-none active:scale-[0.98] focus-visible:ring-2 focus-visible:ring-primary/50",
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
                <span className="text-base leading-snug text-on-surface">
                  {option.text}
                </span>
              </span>
            </RadioGroupPrimitive.Item>
          )
        })}
      </RadioGroupPrimitive.Root>
    </StudyShell>
  )
}

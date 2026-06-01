"use client"

import { RadioGroup as RadioGroupPrimitive } from "radix-ui"

import { cn } from "@/lib/utils"
import { RadioGroupItem } from "@/components/ui/radio-group"
import type { AssistanceSystem } from "@/lib/assistance-systems"

type LikertMatrixProps = {
  /** Ordered captions for the scale, one per radio column. */
  scaleLabels: string[]
  systems: AssistanceSystem[]
  /** Selected value (1-based) per system row index. */
  answers: Record<number, number>
  onChange: (rowIndex: number, value: number) => void
  className?: string
}

/**
 * Survey matrix question: one row per assistance system, each with a single
 * choice across a shared N-point scale. Built on the shadcn/Radix RadioGroup so
 * every row is its own keyboard- and screen-reader-accessible radio group, with
 * the radios aligned beneath the column captions in the header.
 */
export function LikertMatrix({
  scaleLabels,
  systems,
  answers,
  onChange,
  className,
}: LikertMatrixProps) {
  const cols = scaleLabels.length
  const template = {
    gridTemplateColumns: `minmax(200px,1fr) repeat(${cols}, 56px)`,
  }

  return (
    <div
      className={cn(
        "overflow-hidden rounded-xl border border-outline-variant bg-surface-container-low",
        className
      )}
    >
      {/* Column captions */}
      <div
        className="grid items-end gap-1.5 border-b border-outline-variant bg-surface-container px-4 py-3"
        style={template}
      >
        <span className="label-caps text-xs text-on-surface-variant">
          Assistenzsystem
        </span>
        {scaleLabels.map((label) => (
          <span
            key={label}
            className="text-center text-sm leading-tight font-bold text-on-surface"
          >
            {label}
          </span>
        ))}
      </div>

      {/* Rows */}
      {systems.map((system, rowIndex) => (
        <div
          key={system.name}
          className={cn(
            "grid items-center gap-1.5 border-b border-outline-variant px-4 py-3 last:border-0",
            rowIndex % 2 === 1 && "bg-surface-container/40"
          )}
          style={template}
        >
          <div className="pr-3">
            <p className="text-base font-semibold text-on-surface">
              {system.name}
            </p>
            <p className="text-[13px] leading-snug text-on-surface-variant">
              {system.description}
            </p>
          </div>
          <RadioGroupPrimitive.Root
            aria-label={system.name}
            value={
              answers[rowIndex] != null ? String(answers[rowIndex]) : undefined
            }
            onValueChange={(value) => onChange(rowIndex, Number(value))}
            className="grid gap-1.5"
            style={{
              gridColumn: `2 / span ${cols}`,
              gridTemplateColumns: `repeat(${cols}, minmax(0,1fr))`,
            }}
          >
            {scaleLabels.map((label, i) => (
              <div key={label} className="flex justify-center py-1">
                <RadioGroupItem
                  value={String(i + 1)}
                  aria-label={label}
                  className="size-9"
                />
              </div>
            ))}
          </RadioGroupPrimitive.Root>
        </div>
      ))}
    </div>
  )
}

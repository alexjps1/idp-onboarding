"use client"

import { cn } from "@/lib/utils"

type LikertScaleProps = {
  name: string
  value: number | null
  onChange: (value: number) => void
  /** Number of points on the scale. Defaults to a 1–5 scale. */
  points?: number
  className?: string
}

/**
 * Horizontal segmented Likert scale of tappable circles. The selected value
 * fills with the Cyber-Teal primary container and a tactical glow, per the
 * "Matrix Scale" component in the design system.
 */
export function LikertScale({
  name,
  value,
  onChange,
  points = 5,
  className,
}: LikertScaleProps) {
  return (
    <div className={cn("flex justify-center gap-2 lg:gap-4", className)} role="radiogroup">
      {Array.from({ length: points }, (_, i) => i + 1).map((point) => {
        const selected = value === point
        return (
          <label key={point} className="relative cursor-pointer">
            <input
              type="radio"
              name={name}
              value={point}
              checked={selected}
              onChange={() => onChange(point)}
              className="sr-only"
            />
            <span
              className={cn(
                "flex size-12 items-center justify-center rounded-full border data-mono transition-all",
                selected
                  ? "border-primary-container bg-primary-container text-white shadow-[0_0_15px_rgba(45,212,191,0.4)]"
                  : "border-outline text-on-surface-variant hover:border-primary"
              )}
            >
              {point}
            </span>
          </label>
        )
      })}
    </div>
  )
}

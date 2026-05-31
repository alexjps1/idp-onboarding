import { cn } from "@/lib/utils"

type StudyProgressProps = {
  /** Completion fraction between 0 and 1. */
  value: number
  className?: string
}

/**
 * Thin high-contrast progress bar pinned to the top of the content area —
 * the study's "total progress" indicator. Glows in primary teal.
 */
export function StudyProgress({ value, className }: StudyProgressProps) {
  const pct = Math.round(Math.min(Math.max(value, 0), 1) * 100)
  return (
    <div
      className={cn(
        "h-1 w-full bg-surface-container-highest",
        className
      )}
      role="progressbar"
      aria-valuenow={pct}
      aria-valuemin={0}
      aria-valuemax={100}
    >
      <div
        className="h-full bg-primary shadow-[0_0_8px_rgba(0,107,95,0.6)] transition-[width] duration-700 ease-out"
        style={{ width: `${pct}%` }}
      />
    </div>
  )
}

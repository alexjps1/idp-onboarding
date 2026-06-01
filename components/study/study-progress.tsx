import { Progress } from "@/components/ui/progress"

type StudyProgressProps = {
  /** Completion fraction between 0 and 1. */
  value: number
  className?: string
}

/**
 * Thin high-contrast progress bar pinned to the top of the content area —
 * the study's "total progress" indicator. Built on the shadcn Progress
 * component and glows in primary teal.
 */
export function StudyProgress({ value, className }: StudyProgressProps) {
  const pct = Math.round(Math.min(Math.max(value, 0), 1) * 100)
  return <Progress value={pct} className={className} />
}

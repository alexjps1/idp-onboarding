import { cn } from "@/lib/utils"
import { StudyTopBar } from "@/components/study/study-top-bar"
import { StudyProgress } from "@/components/study/study-progress"

type StudyShellProps = {
  participantId?: string
  topBarLabel?: string
  topBarActions?: React.ReactNode
  /** Total-progress fraction (0–1) for the top bar. */
  progress?: number
  /** Bottom navigation bar (usually a <StudyFooter />). */
  footer?: React.ReactNode
  children: React.ReactNode
  /** Extra classes for the scrollable <main> region. */
  mainClassName?: string
  /** Wrapper class (used to opt into the dark cockpit palette). */
  className?: string
}

/**
 * Full-height layout scaffold shared by the onboarding steps: a fixed top app
 * bar with the total-progress indicator, a scrollable content region, and a
 * fixed bottom navigation bar.
 */
export function StudyShell({
  participantId,
  topBarLabel,
  topBarActions,
  progress,
  footer,
  children,
  mainClassName,
  className,
}: StudyShellProps) {
  return (
    <div
      className={cn(
        "flex h-screen w-screen flex-col overflow-hidden bg-background text-on-surface",
        className
      )}
    >
      <StudyTopBar
        participantId={participantId}
        label={topBarLabel}
        actions={topBarActions}
      />
      {progress !== undefined ? <StudyProgress value={progress} /> : null}
      <main
        className={cn(
          "flex flex-1 flex-col justify-center overflow-hidden px-margin-tablet py-6",
          mainClassName
        )}
      >
        {children}
      </main>
      {footer}
    </div>
  )
}

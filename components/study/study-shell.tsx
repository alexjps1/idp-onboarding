import { cn } from "@/lib/utils"
import { StudyTopBar } from "@/components/study/study-top-bar"

type StudyShellProps = {
  participantId?: string
  /** Bottom navigation bar (usually a <StudyFooter />). */
  footer?: React.ReactNode
  children: React.ReactNode
  /** Extra classes for the scrollable <main> region. */
  mainClassName?: string
  /** Wrapper class (used to opt into the dark cockpit palette). */
  className?: string
}

/**
 * Full-height layout scaffold shared by the onboarding steps: a bare
 * participant-id label in the top-left corner, a scrollable content region, and
 * a fixed bottom navigation bar.
 */
export function StudyShell({
  participantId,
  footer,
  children,
  mainClassName,
  className,
}: StudyShellProps) {
  return (
    <div
      className={cn(
        "relative flex h-screen w-screen flex-col overflow-hidden bg-background text-foreground",
        className
      )}
    >
      <StudyTopBar participantId={participantId} />
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

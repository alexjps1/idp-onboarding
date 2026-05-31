import { cn } from "@/lib/utils"

type StudyTopBarProps = {
  participantId?: string
  /** Optional content rendered after the participant id (e.g. a quiz label). */
  label?: string
  /** Optional right-aligned slot (icons, actions). */
  actions?: React.ReactNode
  className?: string
}

/**
 * Fixed top app bar present on every study screen. Shows the pseudonymised
 * participant id in tracked-out monospace caps, matching the prototype.
 */
export function StudyTopBar({
  participantId = "8821",
  label,
  actions,
  className,
}: StudyTopBarProps) {
  return (
    <header
      className={cn(
        "flex h-16 w-full shrink-0 items-center justify-between border-b border-outline-variant bg-surface-container-low px-gutter",
        className
      )}
    >
      <div className="flex items-center gap-4">
        <span className="label-caps text-primary">
          Participant ID: {participantId}
        </span>
        {label ? (
          <>
            <span className="h-4 w-px bg-outline-variant" />
            <span className="text-on-surface-variant">{label}</span>
          </>
        ) : null}
      </div>
      <div className="flex items-center gap-stack-gap">{actions}</div>
    </header>
  )
}

"use client"

import { cn } from "@/lib/utils"
import { useStudy } from "@/components/study/study-provider"

type StudyTopBarProps = {
  /** Override the participant id. Defaults to the value from the study store. */
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
  participantId,
  label,
  actions,
  className,
}: StudyTopBarProps) {
  const { participantId: storeId } = useStudy()
  const id = participantId ?? storeId ?? "—"

  return (
    <header
      className={cn(
        "flex h-16 w-full shrink-0 items-center justify-between border-b border-outline-variant bg-surface-container-low px-gutter",
        className
      )}
    >
      <div className="flex items-center gap-4">
        <span className="label-caps text-primary">Probanden-ID: {id}</span>
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

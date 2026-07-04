"use client"

import { cn } from "@/lib/utils"
import { useStudy } from "@/components/study/study-provider"

type StudyTopBarProps = {
  /** Override the participant id. Defaults to the value from the study store. */
  participantId?: string
  className?: string
}

/**
 * Bare participant-id label at the top-left of a study screen. No bar chrome —
 * just the pseudonymised id in monospace, matching the id shown in the entry
 * dialog. It sits in its own (invisible) block with vertical padding so the
 * content below it keeps some breathing room.
 */
export function StudyTopBar({ participantId, className }: StudyTopBarProps) {
  const { participantId: storeId } = useStudy()
  const id = participantId ?? storeId ?? "—"

  return (
    <div className={cn("shrink-0 px-4 pt-2 pb-2", className)}>
      <span className="font-mono text-sm text-muted-foreground">{id}</span>
    </div>
  )
}

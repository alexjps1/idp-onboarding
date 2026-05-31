import Link from "next/link"
import { ArrowLeft, ArrowRight } from "lucide-react"

import { cn } from "@/lib/utils"
import { StudyButton } from "@/components/study/study-button"

type StudyFooterProps = {
  /** Destination for the "Previous" button. Hidden when omitted. */
  prevHref?: string
  prevLabel?: string
  /** Destination for the "Next Phase" button (link mode). */
  nextHref?: string
  nextLabel?: string
  /** Disables the next button (e.g. until the step is completed). */
  nextDisabled?: boolean
  /** Trailing icon for the next button. Defaults to an arrow. */
  nextIcon?: React.ReactNode
  /** Optional center slot (e.g. module dots, mini progress). */
  center?: React.ReactNode
  /** Optional content rendered left of the next button (e.g. a status label). */
  nextAdornment?: React.ReactNode
  className?: string
}

/**
 * Fixed bottom navigation bar. Mirrors the prototype's Previous / Next Phase
 * controls, with optional center and trailing slots for screen-specific extras.
 */
export function StudyFooter({
  prevHref,
  prevLabel = "Previous",
  nextHref,
  nextLabel = "Next Phase",
  nextDisabled = false,
  nextIcon = <ArrowRight />,
  center,
  nextAdornment,
  className,
}: StudyFooterProps) {
  return (
    <footer
      className={cn(
        "flex h-20 w-full shrink-0 items-center justify-between border-t border-outline-variant bg-surface-container-lowest px-margin-tablet",
        className
      )}
    >
      {prevHref ? (
        <StudyButton asChild variant="outline">
          <Link href={prevHref}>
            <ArrowLeft />
            {prevLabel}
          </Link>
        </StudyButton>
      ) : (
        <span />
      )}

      {center ? <div className="hidden md:flex">{center}</div> : null}

      <div className="flex items-center gap-4">
        {nextAdornment}
        {nextDisabled || !nextHref ? (
          <StudyButton variant="primary" disabled className="opacity-50">
            {nextLabel}
            {nextIcon}
          </StudyButton>
        ) : (
          <StudyButton asChild variant="primary">
            <Link href={nextHref}>
              {nextLabel}
              {nextIcon}
            </Link>
          </StudyButton>
        )}
      </div>
    </footer>
  )
}

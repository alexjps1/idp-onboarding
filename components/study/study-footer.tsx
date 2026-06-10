import Link from "next/link"
import { ArrowLeft, ArrowRight } from "lucide-react"

import { cn } from "@/lib/utils"
import { StudyButton } from "@/components/study/study-button"

type StudyFooterProps = {
  /** Destination for the "Previous" button. Hidden when omitted. */
  prevHref?: string
  /** Click handler for "Previous" (button mode, takes precedence over prevHref). */
  onPrev?: () => void
  prevLabel?: string
  /** Destination for the "Weiter" button (link mode). */
  nextHref?: string
  /** Click handler for "Weiter" (button mode, takes precedence over nextHref). */
  onNext?: () => void
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
  onPrev,
  prevLabel = "Zurück",
  nextHref,
  onNext,
  nextLabel = "Weiter",
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
      {onPrev ? (
        <StudyButton variant="outline" onClick={onPrev}>
          <ArrowLeft />
          {prevLabel}
        </StudyButton>
      ) : prevHref ? (
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
        {!nextDisabled && onNext ? (
          <StudyButton variant="primary" onClick={onNext}>
            {nextLabel}
            {nextIcon}
          </StudyButton>
        ) : !nextDisabled && nextHref ? (
          <StudyButton asChild variant="primary">
            <Link href={nextHref}>
              {nextLabel}
              {nextIcon}
            </Link>
          </StudyButton>
        ) : (
          <StudyButton variant="primary" disabled className="opacity-50">
            {nextLabel}
            {nextIcon}
          </StudyButton>
        )}
      </div>
    </footer>
  )
}

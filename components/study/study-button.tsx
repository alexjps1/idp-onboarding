import * as React from "react"
import { Slot } from "radix-ui"
import { cva, type VariantProps } from "class-variance-authority"

import { cn } from "@/lib/utils"

/**
 * The study's signature action button. Primary = solid Cyber Teal with high
 * contrast text; outline = "ghost" teal-stroked secondary action. Used for the
 * footer navigation and inline actions throughout the flow.
 */
const studyButtonVariants = cva(
  "inline-flex shrink-0 items-center justify-center gap-2 rounded-xl px-8 py-3 text-base font-semibold whitespace-nowrap transition-all outline-none select-none focus-visible:ring-2 focus-visible:ring-primary/50 disabled:pointer-events-none [&_svg]:size-[18px] [&_svg]:shrink-0",
  {
    variants: {
      variant: {
        primary:
          "bg-primary text-on-primary shadow-lg shadow-primary/10 hover:brightness-110 active:scale-[0.98]",
        outline:
          "border border-primary text-primary hover:bg-primary/5 active:scale-[0.98]",
        muted:
          "border border-outline-variant text-on-surface-variant hover:bg-surface-variant",
      },
    },
    defaultVariants: {
      variant: "primary",
    },
  }
)

export type StudyButtonProps = React.ComponentProps<"button"> &
  VariantProps<typeof studyButtonVariants> & {
    asChild?: boolean
  }

export function StudyButton({
  className,
  variant,
  asChild = false,
  ...props
}: StudyButtonProps) {
  const Comp = asChild ? Slot.Root : "button"
  return (
    <Comp
      className={cn(studyButtonVariants({ variant }), className)}
      {...props}
    />
  )
}

export { studyButtonVariants }

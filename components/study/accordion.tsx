"use client"

import * as React from "react"
import { ChevronDown } from "lucide-react"

import { cn } from "@/lib/utils"

type AccordionItemProps = {
  icon: React.ReactNode
  title: string
  /** Small status pill shown after the title. */
  badge?: React.ReactNode
  defaultOpen?: boolean
  /** Highlights the item border in primary when open (high-relevance items). */
  highlight?: boolean
  children: React.ReactNode
}

/**
 * Disclosure panel used in the Onboarding-Guide. Animates its content height
 * and rotates the chevron. Self-contained open/close state per item.
 */
export function AccordionItem({
  icon,
  title,
  badge,
  defaultOpen = false,
  highlight = false,
  children,
}: AccordionItemProps) {
  const [open, setOpen] = React.useState(defaultOpen)

  return (
    <div
      className={cn(
        "overflow-hidden rounded-xl border bg-surface-container transition-colors",
        open && highlight
          ? "border-primary shadow-[0_4px_20px_rgba(0,107,95,0.08)]"
          : "border-outline-variant"
      )}
    >
      <button
        type="button"
        onClick={() => setOpen((value) => !value)}
        aria-expanded={open}
        className="flex w-full items-center justify-between px-6 py-4 transition-colors hover:bg-surface-variant"
      >
        <span className="flex items-center gap-4">
          <span className={highlight ? "text-primary" : "text-on-surface-variant"}>
            {icon}
          </span>
          <span className="text-2xl font-semibold text-on-surface">{title}</span>
          {badge}
        </span>
        <ChevronDown
          className={cn(
            "size-6 shrink-0 text-on-surface-variant transition-transform duration-300",
            open && "rotate-180"
          )}
        />
      </button>
      <div
        className={cn(
          "grid transition-[grid-template-rows] duration-300 ease-out",
          open ? "grid-rows-[1fr]" : "grid-rows-[0fr]"
        )}
      >
        <div className="overflow-hidden">
          <div className="px-6 pb-6">{children}</div>
        </div>
      </div>
    </div>
  )
}

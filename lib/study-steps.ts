/**
 * Ordered definition of the onboarding study flow. A single source of truth for
 * routing ("Next Phase" / "Previous"), progress indication and step labels.
 */
import type { StudyMode } from "@/components/study/study-provider"

export type StudyStep = {
  slug: string
  path: string
  /** Short German title shown in headers / progress. */
  title: string
}

export const STUDY_STEPS: StudyStep[] = [
  {
    slug: "self-assessment-theory",
    path: "/self-assessment/theory",
    title: "Theoretisches Wissen",
  },
  {
    slug: "self-assessment-practice",
    path: "/self-assessment/practice",
    title: "Praktische Erfahrung",
  },
  { slug: "guide", path: "/guide", title: "Onboarding-Guide" },
  { slug: "drive", path: "/drive", title: "Fahrtansicht" },
  { slug: "complete", path: "/complete", title: "Abschluss" },
]

/**
 * The steps for a given run. "onboarding-only" (the /ohnetutor condition) has no
 * tutor and therefore no drive: after the onboarding guide it goes straight to
 * the end screen, so the drive (Fahrtansicht) step is dropped.
 */
export function getStudySteps(mode?: StudyMode | null): StudyStep[] {
  if (mode === "onboarding-only") {
    return STUDY_STEPS.filter((step) => step.slug !== "drive")
  }
  return STUDY_STEPS
}

export function getStepIndex(slug: string, mode?: StudyMode | null): number {
  return getStudySteps(mode).findIndex((step) => step.slug === slug)
}

export function getStep(slug: string): StudyStep | undefined {
  return STUDY_STEPS.find((step) => step.slug === slug)
}

export function getAdjacentSteps(
  slug: string,
  mode?: StudyMode | null
): {
  previous?: StudyStep
  next?: StudyStep
} {
  const steps = getStudySteps(mode)
  const index = steps.findIndex((step) => step.slug === slug)
  return {
    previous: index > 0 ? steps[index - 1] : undefined,
    next: index >= 0 && index < steps.length - 1 ? steps[index + 1] : undefined,
  }
}

/** Progress fraction (0–1) for a given step, used by the top progress bar. */
export function getStepProgress(slug: string, mode?: StudyMode | null): number {
  const steps = getStudySteps(mode)
  const index = steps.findIndex((step) => step.slug === slug)
  if (index < 0) return 0
  return (index + 1) / steps.length
}

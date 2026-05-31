/**
 * Ordered definition of the onboarding study flow. A single source of truth for
 * routing ("Next Phase" / "Previous"), progress indication and step labels.
 */
export type StudyStep = {
  slug: string
  path: string
  /** Short German title shown in headers / progress. */
  title: string
}

export const STUDY_STEPS: StudyStep[] = [
  { slug: "consent", path: "/consent", title: "Einwilligung & Datenschutz" },
  { slug: "mode", path: "/mode", title: "Studienmodus-Auswahl" },
  { slug: "self-assessment", path: "/self-assessment", title: "Selbsteinschätzung" },
  { slug: "knowledge", path: "/knowledge", title: "Wissensfragen" },
  { slug: "guide", path: "/guide", title: "Onboarding-Guide" },
  { slug: "drive", path: "/drive", title: "Fahrtansicht" },
  { slug: "complete", path: "/complete", title: "Abschluss" },
]

export function getStepIndex(slug: string): number {
  return STUDY_STEPS.findIndex((step) => step.slug === slug)
}

export function getStep(slug: string): StudyStep | undefined {
  return STUDY_STEPS.find((step) => step.slug === slug)
}

export function getAdjacentSteps(slug: string): {
  previous?: StudyStep
  next?: StudyStep
} {
  const index = getStepIndex(slug)
  return {
    previous: index > 0 ? STUDY_STEPS[index - 1] : undefined,
    next: index < STUDY_STEPS.length - 1 ? STUDY_STEPS[index + 1] : undefined,
  }
}

/** Progress fraction (0–1) for a given step, used by the top progress bar. */
export function getStepProgress(slug: string): number {
  const index = getStepIndex(slug)
  if (index < 0) return 0
  return (index + 1) / STUDY_STEPS.length
}

"use client"

import { useRouter } from "next/navigation"

import { getAdjacentSteps } from "@/lib/study-steps"
import { useStudy } from "@/components/study/study-provider"
import {
  VehicleWelcome,
  DRIVE_WELCOME_PARAGRAPHS,
} from "@/components/study/vehicle-welcome"

/** Intro copy for the adaptive onboarding conditions (everything but /nurfahrt). */
const ONBOARDING_PARAGRAPHS = [
  "Dieses Tutorial zeigt Ihnen, wie Sie die wichtigsten Assistenzsysteme dieses teilautomatisierten Fahrzeugs sicher und effizient nutzen – kompakt, praxisnah und direkt im Fahrzeug.",
  "Damit Sie nur die Informationen erhalten, die für Sie relevant sind, wird dieses Tutorial an Ihren Wissensstand angepasst. Geben Sie dazu im nächsten Schritt bitte eine kurze Einschätzung ab.",
]

/**
 * Welcome / intro screen shown at the start of the onboarding flow. Introduces
 * the tutorial and hands off to the self-assessment. Pressing "Anpassung
 * starten" stamps the study-begin timestamp (see StudyProvider.markStarted).
 * The drive-only (/nurfahrt) condition has no self-assessment or adaptation, so
 * it shows the same "Willkommen im Fahrzeug" drive lead-in as the drive itself.
 */
export default function WelcomePage() {
  const router = useRouter()
  const { mode, markStarted } = useStudy()
  const { next } = getAdjacentSteps("welcome", mode)

  const isDriveOnly = mode === "drive-only"

  function handleStart() {
    markStarted()
    if (next) router.push(next.path)
  }

  return (
    <VehicleWelcome
      paragraphs={isDriveOnly ? DRIVE_WELCOME_PARAGRAPHS : ONBOARDING_PARAGRAPHS}
      buttonLabel={isDriveOnly ? "Zur Fahrt" : "Anpassung starten"}
      onStart={handleStart}
    />
  )
}

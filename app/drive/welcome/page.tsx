"use client"

import { useRouter } from "next/navigation"

import { getAdjacentSteps } from "@/lib/study-steps"
import { useStudy } from "@/components/study/study-provider"
import {
  VehicleWelcome,
  DRIVE_WELCOME_PARAGRAPHS,
} from "@/components/study/vehicle-welcome"

/**
 * "Willkommen im Fahrzeug" lead-in shown after the post-quiz congratulations,
 * right before the drive. Mirrors the drive-only welcome so both conditions
 * enter the drive with the identical greeting.
 */
export default function DriveWelcomePage() {
  const router = useRouter()
  const { mode } = useStudy()
  const { next } = getAdjacentSteps("drive-welcome", mode)

  function handleStart() {
    if (next) router.push(next.path)
  }

  return (
    <VehicleWelcome
      paragraphs={DRIVE_WELCOME_PARAGRAPHS}
      buttonLabel="Zur Fahrt"
      onStart={handleStart}
    />
  )
}

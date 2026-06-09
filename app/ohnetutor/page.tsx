import { StudyEntry } from "@/components/study/study-entry"

// Starts the study in the "without tutor" mode (Fahrt ohne KI-Tutor).
export default function OhneTutorPage() {
  return <StudyEntry mode="onboarding-only" />
}

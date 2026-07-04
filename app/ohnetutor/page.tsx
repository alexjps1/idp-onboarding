import { StudyEntry } from "@/components/study/study-entry"

// Starts the study in the "without tutor" mode (Fahrt ohne KI-Tutor).
// An optional `?pid=` carries a custom Probanden-ID from the landing page.
export default async function OhneTutorPage({
  searchParams,
}: {
  searchParams: Promise<{ pid?: string }>
}) {
  const { pid } = await searchParams
  return <StudyEntry mode="onboarding-only" pid={pid} />
}

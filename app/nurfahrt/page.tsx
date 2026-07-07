import { StudyEntry } from "@/components/study/study-entry"

// Starts the study in the "drive-only" mode (nur Fahrt, ohne Onboarding).
// An optional `?pid=` carries a custom Probanden-ID from the landing page.
export default async function NurFahrtPage({
  searchParams,
}: {
  searchParams: Promise<{ pid?: string }>
}) {
  const { pid } = await searchParams
  return <StudyEntry mode="drive-only" pid={pid} />
}

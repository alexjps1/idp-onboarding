import { StudyEntry } from "@/components/study/study-entry"

// Starts the study in the "with tutor" mode (begleitete Fahrt mit KI-Tutor).
// An optional `?pid=` carries a custom Probanden-ID from the landing page.
export default async function MitTutorPage({
  searchParams,
}: {
  searchParams: Promise<{ pid?: string }>
}) {
  const { pid } = await searchParams
  return <StudyEntry mode="onboarding-drive" pid={pid} />
}

import Link from "next/link"

// Participants receive a direct link (/mittutor or /ohnetutor). This root page
// is a small fallback so the two entry points are reachable for the study team.
export default function Home() {
  return (
    <div className="flex h-screen w-screen flex-col items-center justify-center gap-8 bg-background px-8 text-on-surface">
      <h1 className="text-center text-2xl font-bold tracking-tight">
        Onboarding-Studie Fahrassistenz
      </h1>
      <div className="flex flex-col gap-4 sm:flex-row">
        <Link
          href="/ohnetutor"
          className="rounded-xl border border-outline-variant bg-surface-container-low px-8 py-4 text-center text-lg font-semibold transition-colors hover:bg-surface-variant"
        >
          Studie ohne Tutor starten
        </Link>
        <Link
          href="/mittutor"
          className="rounded-xl bg-primary px-8 py-4 text-center text-lg font-semibold text-on-primary transition-opacity hover:opacity-90"
        >
          Studie mit Tutor starten
        </Link>
      </div>
    </div>
  )
}

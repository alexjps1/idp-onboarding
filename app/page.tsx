"use client"

import * as React from "react"
import { useRouter } from "next/navigation"

import { PARTICIPANT_ID_PATTERN, isParticipantIdTaken } from "@/lib/participant"

// Participants receive a direct link (/mittutor or /ohnetutor). This root page
// lets the study team assign a Probanden-ID before starting: a custom id (up to
// eight uppercase letters, digits or underscores) or, if left empty, a random
// one generated on the entry screen.
export default function Home() {
  const router = useRouter()
  const [id, setId] = React.useState("")
  const [error, setError] = React.useState<string | null>(null)
  const [checking, setChecking] = React.useState(false)

  function handleChange(event: React.ChangeEvent<HTMLInputElement>) {
    // Auto-uppercase and drop anything outside the allowed charset as they type,
    // so the field can only ever hold a valid id (or be empty).
    const next = event.target.value
      .toUpperCase()
      .replace(/[^A-Z0-9_]/g, "")
      .slice(0, 8)
    setId(next)
    setError(null)
  }

  async function start(route: string) {
    if (checking) return
    // Empty field: hand off without an id — the entry screen generates a random
    // one and shows it in a dialog.
    if (id === "") {
      router.push(route)
      return
    }
    if (!PARTICIPANT_ID_PATTERN.test(id)) {
      setError("Ungültige Probanden-ID.")
      return
    }
    setChecking(true)
    const taken = await isParticipantIdTaken(id)
    setChecking(false)
    if (taken) {
      setError(`Die Probanden-ID „${id}“ wurde bereits verwendet.`)
      return
    }
    router.push(`${route}?pid=${encodeURIComponent(id)}`)
  }

  return (
    <div className="flex h-screen w-screen flex-col items-center justify-center gap-8 bg-background px-8 text-on-surface">
      <h1 className="text-center text-2xl font-bold tracking-tight">
        Onboarding-Studie Fahrassistenz
      </h1>

      <div className="flex w-full max-w-sm flex-col gap-2">
        <label
          htmlFor="participant-id"
          className="label-caps text-on-surface-variant"
        >
          Probanden-ID
        </label>
        <input
          id="participant-id"
          value={id}
          onChange={handleChange}
          autoComplete="off"
          autoCapitalize="characters"
          spellCheck={false}
          placeholder="Leer lassen für zufällige ID"
          className="data-mono rounded-xl border border-outline-variant bg-surface-container-low px-4 py-3 text-center text-lg tracking-widest text-on-surface outline-none focus:border-primary"
        />
        <p className="text-sm text-on-surface-variant">
          Nur Großbuchstaben, Zahlen und Unterstriche, max. 8 Zeichen. Leer
          lassen, um eine zufällige ID zu erzeugen.
        </p>
        {error ? <p className="text-sm text-error">{error}</p> : null}
      </div>

      <div className="flex flex-col gap-4 sm:flex-row">
        <button
          type="button"
          onClick={() => start("/ohnetutor")}
          disabled={checking}
          className="rounded-xl border border-outline-variant bg-surface-container-low px-8 py-4 text-center text-lg font-semibold transition-colors hover:bg-surface-variant disabled:opacity-60"
        >
          Studie ohne Tutor starten
        </button>
        <button
          type="button"
          onClick={() => start("/mittutor")}
          disabled={checking}
          className="rounded-xl bg-primary px-8 py-4 text-center text-lg font-semibold text-on-primary transition-opacity hover:opacity-90 disabled:opacity-60"
        >
          Studie mit Tutor starten
        </button>
      </div>
    </div>
  )
}

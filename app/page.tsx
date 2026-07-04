"use client"

import * as React from "react"
import { useRouter } from "next/navigation"

import { Button } from "@/components/ui/button"
import {
  Card,
  CardContent,
  CardDescription,
  CardFooter,
  CardHeader,
  CardTitle,
} from "@/components/ui/card"
import { Input } from "@/components/ui/input"
import { Label } from "@/components/ui/label"
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
    <div className="flex h-screen w-screen items-center justify-center bg-background p-6">
      <Card className="w-full max-w-2xl">
        <CardHeader>
          <CardTitle>Onboarding-Studie Fahrassistenz</CardTitle>
          <CardDescription>
            Bitte eine Probanden-ID vergeben oder für eine zufällige ID leer
            lassen.
          </CardDescription>
        </CardHeader>

        <CardContent className="flex flex-col gap-3">
          <Label htmlFor="participant-id">Probanden-ID</Label>
          <Input
            id="participant-id"
            value={id}
            onChange={handleChange}
            autoComplete="off"
            autoCapitalize="characters"
            spellCheck={false}
            placeholder="Leer lassen für zufällige ID"
          />
          <p className="text-lg text-muted-foreground">
            Nur Großbuchstaben, Zahlen und Unterstriche, max. 8 Zeichen.
          </p>
          {error ? <p className="text-lg text-destructive">{error}</p> : null}
        </CardContent>

        <CardFooter className="gap-3">
          <Button
            variant="outline"
            size="lg"
            onClick={() => start("/ohnetutor")}
            disabled={checking}
            className="h-14 flex-1 text-xl"
          >
            Studie ohne Tutor starten
          </Button>
          <Button
            size="lg"
            onClick={() => start("/mittutor")}
            disabled={checking}
            className="h-14 flex-1 text-xl"
          >
            Studie mit Tutor starten
          </Button>
        </CardFooter>
      </Card>
    </div>
  )
}

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
import { cn } from "@/lib/utils"
import { PARTICIPANT_ID_PATTERN, isParticipantIdTaken } from "@/lib/participant"
import { REALTIME_TEXT_INPUT } from "@/components/study/use-voice-tutor"

/** The selectable study flows, in display order. */
const FLOW_OPTIONS = [
  {
    route: "/ohnetutor",
    label: "Nur Onboarding",
    description: "Selbsteinschätzung und Onboarding-Guide, ohne Fahrt.",
    disabled: true,
  },
  {
    route: "/nurfahrt",
    label: "Nur Fahrt",
    description: "Direkt in die Fahrtansicht mit KI-Tutor.",
    disabled: false,
  },
  {
    route: "/mittutor",
    label: "Onboarding und Fahrt",
    description: "Kompletter Ablauf: Onboarding und anschließende Fahrt.",
    disabled: false,
  },
] as const

// Participants receive a direct link (/mittutor or /ohnetutor). This root page
// lets the study team assign a Probanden-ID before starting: a custom id (up to
// eight uppercase letters, digits or underscores) or, if left empty, a random
// one generated on the entry screen.
export default function Home() {
  const router = useRouter()
  const [id, setId] = React.useState("")
  const [error, setError] = React.useState<string | null>(null)
  const [checking, setChecking] = React.useState(false)
  const [flowOpen, setFlowOpen] = React.useState(false)

  // Mic-permission gate: the tutor needs microphone access once the run
  // reaches /drive, and requesting it there for the first time risks Safari
  // suppressing the permission prompt if it isn't tied to a fresh tap (see
  // useVoiceTutor's start()). Requesting it here instead, on a real click,
  // means the grant is already in place by the time /drive asks again — that
  // later getUserMedia call resolves instantly with no prompt. In text-input
  // debug mode no real mic is ever used, so the gate is skipped entirely.
  const [micGranted, setMicGranted] = React.useState(REALTIME_TEXT_INPUT)
  const [micRequesting, setMicRequesting] = React.useState(false)
  const [micError, setMicError] = React.useState<string | null>(null)

  async function requestMic() {
    if (micRequesting || micGranted) return
    if (!navigator.mediaDevices?.getUserMedia) {
      setMicError(
        "Mikrofon nur über HTTPS verfügbar – bitte die Seite über https:// öffnen."
      )
      return
    }
    setMicRequesting(true)
    setMicError(null)
    try {
      const stream = await navigator.mediaDevices.getUserMedia({
        audio: true,
      })
      // Only the permission grant is needed here — release the device
      // immediately so nothing keeps the mic reserved until /drive opens it.
      stream.getTracks().forEach((t) => t.stop())
      setMicGranted(true)
    } catch {
      setMicError(
        "Mikrofonzugriff wurde verweigert. Bitte in den Browser-/Systemeinstellungen erlauben und erneut versuchen."
      )
    } finally {
      setMicRequesting(false)
    }
  }

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

          {!REALTIME_TEXT_INPUT ? (
            <div className="mt-3 flex flex-col gap-2 border-t pt-4">
              <Label>Mikrofonzugriff</Label>
              <Button
                type="button"
                variant={micGranted ? "secondary" : "default"}
                size="lg"
                onClick={requestMic}
                disabled={micRequesting || micGranted}
                className="h-14 text-xl"
              >
                {micGranted
                  ? "Mikrofon aktiviert ✓"
                  : micRequesting
                    ? "Warte auf Freigabe…"
                    : "Mikrofon aktivieren"}
              </Button>
              <p className="text-lg text-muted-foreground">
                Vor Studienbeginn muss der Mikrofonzugriff einmal freigegeben
                werden.
              </p>
              {micError ? (
                <p className="text-lg text-destructive">{micError}</p>
              ) : null}
            </div>
          ) : null}
        </CardContent>

        <CardFooter>
          <Button
            size="lg"
            onClick={() => setFlowOpen(true)}
            disabled={checking || !micGranted}
            className="h-14 w-full text-xl"
          >
            Studie starten
          </Button>
        </CardFooter>
      </Card>

      {/* Flow picker — opened by "Studie starten" so the card stays compact and
          on a single screen. Selecting an enabled flow starts it immediately. */}
      {flowOpen ? (
        <div
          className="fixed inset-0 z-50 flex items-center justify-center bg-black/50 p-6 backdrop-blur-sm"
          onClick={() => setFlowOpen(false)}
        >
          <Card
            role="dialog"
            aria-modal="true"
            aria-labelledby="flow-dialog-title"
            className="w-full max-w-lg"
            onClick={(event) => event.stopPropagation()}
          >
            <CardHeader>
              <CardTitle id="flow-dialog-title">Ablauf wählen</CardTitle>
              <CardDescription>
                Welchen Teil der Studie möchten Sie starten?
              </CardDescription>
            </CardHeader>

            <CardContent className="flex flex-col gap-2">
              {FLOW_OPTIONS.map((option) => (
                <button
                  key={option.route}
                  type="button"
                  disabled={option.disabled || checking}
                  onClick={() => start(option.route)}
                  className={cn(
                    "flex flex-col items-start gap-1 rounded-lg border-2 px-5 py-4 text-left transition-colors",
                    option.disabled
                      ? "cursor-not-allowed border-border bg-muted/40 opacity-50"
                      : "border-border hover:border-primary hover:bg-primary/5"
                  )}
                >
                  <span className="flex items-center gap-2 text-xl font-medium">
                    {option.label}
                    {option.disabled ? (
                      <span className="rounded-full bg-muted px-2 py-0.5 text-xs font-normal text-muted-foreground">
                        bald verfügbar
                      </span>
                    ) : null}
                  </span>
                  <span className="text-base text-muted-foreground">
                    {option.description}
                  </span>
                </button>
              ))}
            </CardContent>

            <CardFooter>
              <Button
                variant="outline"
                size="lg"
                onClick={() => setFlowOpen(false)}
                className="h-12 w-full text-lg"
              >
                Abbrechen
              </Button>
            </CardFooter>
          </Card>
        </div>
      ) : null}
    </div>
  )
}

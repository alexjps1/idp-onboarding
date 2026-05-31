"use client"

import * as React from "react"
import { Clock, ShieldCheck, User, RotateCw, Check } from "lucide-react"

import { cn } from "@/lib/utils"
import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { useStudy } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"
import { StudyButton } from "@/components/study/study-button"

const INFO = [
  { icon: Clock, label: "Dauer", value: "Ca. 45 Minuten" },
  { icon: ShieldCheck, label: "Daten", value: "Pseudonymisiert" },
  { icon: User, label: "Leitung", value: "Prof. Dr. Müller" },
]

const CONSENT_PARAGRAPHS: React.ReactNode[] = [
  "Die Teilnahme an dieser Studie zur Untersuchung von SAE Level 2 Fahrassistenzsystemen erfolgt auf freiwilliger Basis. Sie können Ihre Einwilligung jederzeit ohne Angabe von Gründen und ohne Nachteil widerrufen.",
  <>
    <strong>1. Erhebung und Verarbeitung:</strong> Während der Simulation werden
    Fahrzeugdaten (Lenkwinkel, Geschwindigkeit), Blickbewegungsdaten und
    physiologische Parameter (optional) aufgezeichnet.
  </>,
  <>
    <strong>2. Pseudonymisierung:</strong> Alle Daten werden unter einer
    Probanden-ID gespeichert. Eine Verknüpfung Ihrer persönlichen Identität mit
    den Messdaten ist nur befugtem Forschungspersonal möglich.
  </>,
  <>
    <strong>3. Aufbewahrung:</strong> Die Daten werden gemäß den Leitlinien zur
    guten wissenschaftlichen Praxis für einen Zeitraum von 10 Jahren archiviert.
  </>,
  <>
    <strong>4. Ihre Rechte:</strong> Sie haben das Recht auf Auskunft,
    Berichtigung oder Löschung Ihrer Daten, sofern diese noch nicht vollständig
    anonymisiert wurden.
  </>,
  'Die Studie wird im Rahmen des Human-Factors-Projekts "SimDrive SAE-L2" an der Technischen Universität durchgeführt. Bei Rückfragen wenden Sie sich bitte an das wissenschaftliche Personal vor Ort.',
]

export default function ConsentPage() {
  const { participantId, setParticipantId } = useStudy()
  const [consented, setConsented] = React.useState(false)
  const { next } = getAdjacentSteps("consent")

  const id = participantId ?? ""
  const canProceed = consented && id.trim().length > 0

  function generateId() {
    setParticipantId(`PB-${Math.floor(1000 + Math.random() * 9000)}`)
  }

  return (
    <StudyShell
      progress={getStepProgress("consent")}
      footer={
        <StudyFooter
          nextHref={next?.path}
          nextLabel="Next Phase"
          nextDisabled={!canProceed}
        />
      }
    >
      <div className="mx-auto max-w-4xl">
        <div className="mb-4 flex items-center gap-3">
          <span className="h-1 w-12 rounded-full bg-primary" />
          <span className="label-caps tracking-[0.2em] text-primary">
            Schritt 01 / Phase 01
          </span>
        </div>
        <h1 className="mb-8 text-[32px] leading-10 font-bold tracking-tight">
          Einwilligung &amp; Datenschutz
        </h1>

        {/* Study facts */}
        <div className="mb-8 grid grid-cols-1 gap-stack-gap md:grid-cols-3">
          {INFO.map(({ icon: Icon, label, value }) => (
            <div
              key={label}
              className="rounded-xl border border-outline-variant bg-surface-container-low p-5"
            >
              <div className="mb-2 flex items-center gap-3 text-primary">
                <Icon className="size-5" />
                <span className="label-caps text-[14px]">{label}</span>
              </div>
              <p className="text-on-surface">{value}</p>
            </div>
          ))}
        </div>

        {/* Privacy notice */}
        <div className="mb-8 rounded-lg border border-outline-variant bg-surface-container-low p-8 shadow-sm">
          <h2 className="mb-4 text-2xl font-semibold">Datenschutz-Hinweis</h2>
          <div className="study-scrollbar h-64 space-y-4 overflow-y-auto pr-4 text-on-surface-variant">
            {CONSENT_PARAGRAPHS.map((paragraph, i) => (
              <p key={i}>{paragraph}</p>
            ))}
          </div>
        </div>

        {/* Consent + ID */}
        <div className="space-y-stack-gap">
          <label
            className={cn(
              "group flex cursor-pointer items-start gap-4 rounded-xl border bg-surface-container-low p-6 transition-all hover:bg-surface-variant/50 active:scale-[0.99]",
              consented ? "border-primary" : "border-outline-variant"
            )}
          >
            <span
              className={cn(
                "mt-0.5 flex size-6 items-center justify-center rounded border-2 transition-all",
                consented
                  ? "border-primary bg-primary text-on-primary"
                  : "border-outline"
              )}
            >
              {consented ? <Check className="size-4" strokeWidth={3} /> : null}
            </span>
            <input
              type="checkbox"
              className="sr-only"
              checked={consented}
              onChange={(event) => setConsented(event.target.checked)}
            />
            <span className="text-on-surface transition-colors group-hover:text-primary">
              Ich habe die Hinweise gelesen und erkläre mich mit der Teilnahme
              einverstanden.
            </span>
          </label>

          <div className="flex flex-col items-end gap-gutter rounded-xl border border-outline-variant bg-surface-container-low p-6 md:flex-row">
            <div className="w-full flex-1">
              <label
                htmlFor="participant-id"
                className="mb-2 block label-caps text-on-surface-variant"
              >
                Probanden-ID
              </label>
              <input
                id="participant-id"
                type="text"
                value={id}
                onChange={(event) => setParticipantId(event.target.value)}
                placeholder="PB-XXXX"
                className="h-14 w-full rounded-lg border border-outline-variant bg-surface-container-lowest px-5 data-mono text-on-surface shadow-sm outline-none transition-all focus:border-primary focus:ring-1 focus:ring-primary"
              />
            </div>
            <StudyButton
              type="button"
              variant="outline"
              onClick={generateId}
              className="h-14"
            >
              <RotateCw />
              ID generieren
            </StudyButton>
          </div>
        </div>
      </div>
    </StudyShell>
  )
}

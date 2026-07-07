"use client"

import * as React from "react"
import {
  Navigation,
  Music,
  Phone,
  Settings,
  Sparkles,
  Heart,
  MoreVertical,
  Shuffle,
  SkipBack,
  SkipForward,
  Play,
  Pause,
  Repeat,
  ListMusic,
  Signal,
  Bluetooth,
  User,
  Armchair,
  Fan,
  Wind,
  Minus,
  Plus,
  X,
} from "lucide-react"

import Link from "next/link"
import { useRouter } from "next/navigation"
import { ArrowRight, Square, TriangleAlert } from "lucide-react"

import { cn } from "@/lib/utils"
import { withBasePath } from "@/lib/base-path"
import { getAdjacentSteps } from "@/lib/study-steps"
import { useStudy } from "@/components/study/study-provider"
import {
  useVoiceTutor,
  type VoiceTutorStatus,
  REALTIME_TEXT_INPUT,
} from "@/components/study/use-voice-tutor"
import { useAdasMonitor } from "@/components/study/use-adas-monitor"
import { useIntroTrigger } from "@/components/study/use-intro-trigger"
import { useZoneTriggers, type ZoneOutcome } from "@/components/study/use-zone-triggers"
import { useSimulationStart } from "@/components/study/use-simulation-start"

/** Delay before the tutor's one-time self-introduction, in milliseconds. */
const INTRO_DELAY_MS = 15000

/** Delay before the "Fahrt starten" confirm button becomes clickable, in milliseconds. */
const START_CONFIRM_DELAY_MS = 5000

/** Maps a nudge-zone index (0-based, "Stelle 1"–"Stelle 6") to its triggerStates key. */
const ZONE_NUDGE_IDS = [
  "zoneNudge1",
  "zoneNudge2",
  "zoneNudge3",
  "zoneNudge4",
  "zoneNudge5",
  "zoneNudge6",
] as const

const SIDEBAR_APPS = [
  { icon: Navigation, label: "Karte" },
  { icon: Music, label: "Medien" },
  { icon: Phone, label: "Telefon" },
  { icon: Settings, label: "Einstellungen" },
] as const

const STATUS_LABEL: Record<VoiceTutorStatus, string> = {
  idle: "Mikrofon aus",
  connecting: "Verbinde…",
  // Pre-warmed but no conversation yet — indistinguishable from idle for the
  // driver, the overlay isn't even open while this is the status.
  ready: "Mikrofon aus",
  listening: "Ich höre zu…",
  speaking: "Ich höre Sie…",
  responding: "Ich antworte…",
  error: "Fehler",
}

export default function DrivePage() {
  const [assistantOpen, setAssistantOpen] = React.useState(false)
  const [playing, setPlaying] = React.useState(true)
  const [endConfirmOpen, setEndConfirmOpen] = React.useState(false)
  // The drive doesn't run until the participant taps "Fahrt starten": only then
  // do the tutor, its greeting and the proactive triggers become active.
  const [driveStarted, setDriveStarted] = React.useState(false)
  // "Fahrt starten" opens a confirm dialog for the Studienleitung first (this
  // step also cues them to start the SILAB simulation) — its confirm button
  // stays disabled for START_CONFIRM_DELAY_MS.
  const [startConfirmOpen, setStartConfirmOpen] = React.useState(false)
  const [startConfirmEnabled, setStartConfirmEnabled] = React.useState(false)
  const [textDraft, setTextDraft] = React.useState("")
  const [textInputVisible, setTextInputVisible] = React.useState(false)
  const {
    participantId,
    mode,
    theory,
    practice,
    startVoiceConversation,
    appendVoiceMessage,
    setTriggerState,
    markDriveStarted,
    markSimulationStarted,
    markDriveEnded,
  } = useStudy()
  const { next } = getAdjacentSteps("drive", mode)
  const router = useRouter()
  const withTutor = mode !== "onboarding-only"
  // Realtime tutor + proactive triggers only run once the drive has started.
  const driveActive = withTutor && driveStarted
  const tutor = useVoiceTutor({
    onMessage: appendVoiceMessage,
    // The tutor ended the conversation itself (driver asked to stop) — close
    // the overlay; the hook has already torn the session down.
    onEnd: () => setAssistantOpen(false),
  })

  // Open/close the assistant overlay and the mic together. Each open starts a
  // fresh conversation in the study record (the tutor can be opened repeatedly).
  // Side effects run here in the click handler — never inside a setState updater,
  // which React may invoke mid-render (that would update StudyProvider during
  // DrivePage's render and trigger a cross-component setState warning).
  function toggleAssistant() {
    if (assistantOpen) {
      tutor.stop()
      setAssistantOpen(false)
    } else {
      startVoiceConversation("user_initiated")
      void tutor.start()
      setAssistantOpen(true)
    }
  }

  // Proactive trigger: the first time the driving automation is switched on,
  // open the assistant on its own and have it greet (unless already open).
  // Always records the diagnostic outcome to the study session so a missed
  // trigger can be explained from the saved data (see lib/study-data.ts).
  const openAssistantProactively = React.useCallback(
    (outcome: "suppressed" | "fired") => {
      setTriggerState("adasOn", outcome)
      if (outcome !== "fired") return
      setAssistantOpen(true)
      startVoiceConversation("proactive")
      void tutor.start({ proactiveKind: "adas_on", theory, practice })
    },
    [tutor, theory, practice, startVoiceConversation, setTriggerState]
  )

  useAdasMonitor({
    enabled: driveActive,
    onActivate: openAssistantProactively,
    shouldSuppress: () => assistantOpen,
  })

  // Proactive trigger: a one-time self-introduction shortly after the drive
  // view loads, regardless of ADAS state.
  const openAssistantForIntro = React.useCallback(
    (outcome: "suppressed" | "fired") => {
      setTriggerState("intro", outcome)
      if (outcome !== "fired") return
      setAssistantOpen(true)
      startVoiceConversation("proactive_intro")
      void tutor.start({ proactiveKind: "intro" })
    },
    [tutor, startVoiceConversation, setTriggerState]
  )

  useIntroTrigger({
    enabled: driveActive,
    delayMs: INTRO_DELAY_MS,
    onTrigger: openAssistantForIntro,
    shouldSuppress: () => assistantOpen,
  })

  // Proactive triggers: fixed track zones — nudge the driver to turn ADAS on
  // if it's off there, and explain the DHL-van takeover afterwards if ADAS
  // was on beforehand.
  const openAssistantForZoneNudge = React.useCallback(
    (index: number, outcome: ZoneOutcome) => {
      setTriggerState(ZONE_NUDGE_IDS[index], outcome)
      if (outcome !== "fired") return
      setAssistantOpen(true)
      startVoiceConversation("proactive_zone_nudge")
      void tutor.start({ proactiveKind: "zone_nudge" })
    },
    [tutor, startVoiceConversation, setTriggerState]
  )

  const openAssistantForSystemLimit = React.useCallback(
    (outcome: ZoneOutcome) => {
      setTriggerState("systemLimit", outcome)
      if (outcome !== "fired") return
      setAssistantOpen(true)
      startVoiceConversation("proactive_system_limit")
      void tutor.start({ proactiveKind: "system_limit" })
    },
    [tutor, startVoiceConversation, setTriggerState]
  )

  useZoneTriggers({
    enabled: driveActive,
    onZoneNudge: openAssistantForZoneNudge,
    onSystemLimitExplain: openAssistantForSystemLimit,
    shouldSuppress: () => assistantOpen,
  })

  // Records when the simulation itself actually started (first SILAB packet
  // after "Fahrt starten"), distinct from driveStartedAt (the button press).
  useSimulationStart({
    enabled: driveActive,
    onDetected: markSimulationStarted,
  })

  // Pre-warm a muted Realtime connection as soon as the drive view mounts, so
  // opening the assistant later (manually or proactively) can unmute and talk
  // instantly instead of waiting out a fresh WebRTC handshake. Relies on mic
  // permission already having been granted on the entry page.
  React.useEffect(() => {
    // Prewarm regardless of driveStarted: the tutor can be opened (and tried
    // out) before the drive starts, so the connection must be ready then too.
    if (withTutor) tutor.prewarm()
    // Depend on tutor.prewarm (stable for the hook's lifetime), not the whole
    // tutor object — that's a fresh object literal every render and would
    // re-fire this effect (and re-call prewarm) on every render.
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [withTutor, tutor.prewarm])

  // The confirm button in the "Fahrt starten" dialog stays disabled until
  // START_CONFIRM_DELAY_MS after the dialog opens.
  React.useEffect(() => {
    if (!startConfirmOpen) return
    const id = setTimeout(
      () => setStartConfirmEnabled(true),
      START_CONFIRM_DELAY_MS
    )
    return () => clearTimeout(id)
  }, [startConfirmOpen])

  function confirmStartDrive() {
    markDriveStarted()
    setDriveStarted(true)
    setStartConfirmOpen(false)
  }

  function closeAssistant() {
    tutor.stop()
    setAssistantOpen(false)
  }

  const voiceActive =
    tutor.status === "speaking" ||
    tutor.status === "listening" ||
    tutor.status === "responding"

  // Live clock for the car status bar.
  const [time, setTime] = React.useState<string | null>(null)
  React.useEffect(() => {
    const update = () =>
      setTime(
        new Date().toLocaleTimeString("de-DE", {
          hour: "2-digit",
          minute: "2-digit",
        })
      )
    update()
    const id = setInterval(update, 1000)
    return () => clearInterval(id)
  }, [])

  // Guard: the onboarding-only (/ohnetutor) condition has no tutor and no drive.
  // If this page is reached directly in that mode, skip to the end screen.
  React.useEffect(() => {
    if (mode === "onboarding-only") router.replace("/complete")
  }, [mode, router])

  if (mode === "onboarding-only") return null

  return (
    <div className="flex h-screen w-screen flex-col overflow-hidden bg-[#f2f1f2] text-black">
      {/* MyCar infotainment screen */}
      <div className="flex flex-grow flex-col overflow-hidden">
        {/* Car status bar — carries the study chrome (ID + navigation) */}
        <div className="relative flex h-14 shrink-0 items-center border-b border-[#e2e2e2] bg-[#f2f1f2]">
          <div className="flex shrink-0 items-center border-r border-[#e2e2e2] px-5">
            <span className="font-mono text-sm text-muted-foreground">
              {participantId ?? "—"}
            </span>
          </div>
          {/* Before the drive starts this is the warm-up/practice area — label
              it prominently on the left so participants know the tutor can be
              tried out here first. */}
          {!driveStarted ? (
            <span className="ml-5 rounded-full bg-[#d13438] px-5 py-1.5 text-[18px] font-bold uppercase tracking-wide text-white shadow-sm">
              Eingewöhnungsumgebung
            </span>
          ) : null}
          <span className="absolute left-1/2 -translate-x-1/2 text-[15px] tabular-nums text-[#7e7f7f]">
            {time ?? "--:--"}
          </span>
          <div className="ml-auto flex items-center gap-6 px-5 text-[#858686]">
            <Signal className="size-5" />
            <Bluetooth className="size-5" />
            <span className="text-[15px]">LTE</span>
            <User className="size-5" />
            <span className="text-[15px]">18°C</span>

            {/* Drive control: start the drive, then end it (with a warning). */}
            <span className="h-7 w-px bg-[#d8d8d8]" />
            {!driveStarted ? (
              <button
                type="button"
                onClick={() => {
                  setStartConfirmEnabled(false)
                  setStartConfirmOpen(true)
                }}
                className="flex items-center gap-2 rounded-full bg-black px-7 py-2.5 text-[16px] font-semibold text-white shadow-sm transition-colors hover:bg-black/80"
              >
                <Play className="size-5 fill-current" />
                Fahrt starten
              </button>
            ) : (
              <button
                type="button"
                onClick={() => setEndConfirmOpen(true)}
                className="flex items-center gap-2 rounded-full border border-[#d13438]/40 bg-white px-5 py-2 text-[14px] font-medium text-[#d13438] transition-colors hover:bg-[#d13438]/5"
              >
                <Square className="size-4 fill-current" />
                Fahrt beenden
              </button>
            )}
          </div>
        </div>

        <div className="flex flex-grow overflow-hidden">
          {/* App launcher sidebar */}
          <aside className="flex w-28 shrink-0 flex-col items-center gap-4 border-r border-[#e2e2e2] bg-[#f2f1f2] py-6">
            {SIDEBAR_APPS.map(({ icon: Icon, label }) => {
              const isActive = label === "Medien"
              return (
                <button
                  key={label}
                  type="button"
                  aria-label={label}
                  aria-pressed={isActive}
                  className={cn(
                    "flex size-[88px] flex-col items-center justify-center gap-2 rounded-2xl transition-colors",
                    isActive
                      ? "border border-[#e7e7e7] bg-white text-[#1973f7] shadow-[0px_2px_4px_rgba(0,0,0,0.05)]"
                      : "text-[#747273] hover:bg-black/5"
                  )}
                >
                  <Icon className="size-7" />
                  <span className="text-[15px]">{label}</span>
                </button>
              )
            })}

            {/* Tutor — gradient, wired to the voice tutor; available before the
                drive starts too, so it can be tried out. Grays out with an X
                while open. */}
            {withTutor ? (
              <button
                type="button"
                aria-label={assistantOpen ? "Tutor schließen" : "Tutor"}
                aria-pressed={assistantOpen}
                onClick={toggleAssistant}
                className={cn(
                  "flex size-[88px] flex-col items-center justify-center gap-2 rounded-2xl transition-transform",
                  assistantOpen
                    ? "scale-105 bg-[#d8d8d8] text-[#5f5f61] shadow-lg"
                    : "bg-[linear-gradient(146deg,#a953da_7%,#39c9f6_93%)] text-white hover:scale-105"
                )}
              >
                {assistantOpen ? (
                  <X className="size-7" />
                ) : (
                  <Sparkles className="size-7" />
                )}
                <span className="text-[17px] font-semibold">
                  {assistantOpen ? "Schließen" : "Tutor"}
                </span>
              </button>
            ) : null}
          </aside>

          {/* Media player */}
          <main className="relative flex flex-grow items-center justify-center overflow-hidden bg-gradient-to-br from-[#eef1f5] to-[#e3e7ec] p-8">
            {/* Before the drive starts: explain the tutor button (on/off). */}
            {!driveStarted ? (
              <div className="absolute bottom-6 left-6 z-40 max-w-lg rounded-2xl border border-[#e2e2e2] bg-white/95 px-7 py-6 shadow-md">
                <div className="flex items-start gap-4">
                  <span className="flex size-12 shrink-0 items-center justify-center rounded-xl bg-[linear-gradient(146deg,#a953da_7%,#39c9f6_93%)] text-white">
                    <Sparkles className="size-7" />
                  </span>
                  <div>
                    <p className="text-2xl font-semibold text-black">
                      Sprachassistent
                    </p>
                    <p className="mt-1.5 text-xl leading-relaxed text-black/70">
                      Tippen Sie links auf „Tutor“, um den Assistenten zu
                      starten. Mit einem erneuten Tippen auf den Screen beenden
                      Sie ihn wieder. Probieren Sie es gern schon jetzt aus – die
                      Fahrt starten Sie anschließend oben rechts.
                    </p>
                  </div>
                </div>
              </div>
            ) : null}

            <div className="flex w-full max-w-5xl flex-col items-center gap-8 rounded-[40px] bg-white/50 p-8 backdrop-blur-sm">
              <div className="flex w-full items-center gap-8">
                {/* Now-playing controls */}
                <div className="flex flex-1 flex-col gap-8 p-4">
                  <div className="flex items-start gap-6">
                    <Heart className="size-7 text-black/70" />
                    <MoreVertical className="size-7 text-black/70" />
                  </div>

                  <div className="flex flex-col gap-1">
                    <p className="text-[32px] font-semibold leading-tight">
                      Midnight Drive
                    </p>
                    <p className="text-[26px] text-black/80">Neon Avenue</p>
                  </div>

                  <div className="flex flex-col gap-3">
                    {/* Progress */}
                    <div className="relative h-[9px] w-full rounded-full bg-[#d8d8e1]">
                      <div className="h-full w-[42%] rounded-full bg-[#0070ff]" />
                      <span className="absolute left-[42%] top-1/2 size-6 -translate-x-1/2 -translate-y-1/2 rounded-full bg-[#0070ff]" />
                    </div>
                    <div className="flex justify-between text-[20px] text-black/60">
                      <span>1:28</span>
                      <span>-2:42</span>
                    </div>

                    {/* Transport */}
                    <div className="mt-2 flex items-center justify-between">
                      <Shuffle className="size-8 text-black/80" />
                      <SkipBack className="size-9 fill-black/80 text-black/80" />
                      <button
                        type="button"
                        aria-label={playing ? "Pause" : "Wiedergabe"}
                        onClick={() => setPlaying((p) => !p)}
                        className="flex size-20 items-center justify-center rounded-full bg-white shadow-md transition-transform hover:scale-105"
                      >
                        {playing ? (
                          <Pause className="size-9 fill-black text-black" />
                        ) : (
                          <Play className="size-9 fill-black text-black" />
                        )}
                      </button>
                      <SkipForward className="size-9 fill-black/80 text-black/80" />
                      <Repeat className="size-8 text-black/80" />
                    </div>
                  </div>
                </div>

                {/* Album art */}
                <div className="relative aspect-[3/4] w-[300px] shrink-0 overflow-hidden rounded-3xl shadow-[0px_4px_12px_rgba(0,0,0,0.25)]">
                  <img
                    src={withBasePath("/neon-avenue.png")}
                    alt="Neon Avenue"
                    className="absolute inset-0 size-full object-cover"
                  />
                  <div className="absolute inset-0 bg-black/5" />
                  <p className="absolute bottom-12 left-1/2 -translate-x-1/2 text-[20px] font-semibold tracking-[4px] text-white drop-shadow">
                    NEON AVENUE
                  </p>
                </div>
              </div>

              {/* Queue */}
              <button
                type="button"
                className="flex items-center gap-3 rounded-full bg-white px-6 py-3 shadow-[0px_4px_18px_rgba(0,0,0,0.1)] transition-transform hover:scale-105"
              >
                <ListMusic className="size-7 text-[#5f5f61]" />
                <span className="text-[22px] text-[#5f5f61]">Warteschlange</span>
              </button>
            </div>

            {/* Voice assistant overlay */}
            {assistantOpen ? (
              <div className="absolute inset-0 z-50 flex flex-col items-center justify-center gap-6 bg-white/70 px-10 backdrop-blur-md">
                <button
                  type="button"
                  onClick={closeAssistant}
                  aria-label="Sprachassistent schließen"
                  className="absolute right-8 top-8 flex size-12 items-center justify-center rounded-full bg-white text-black/60 shadow transition-colors hover:bg-black/5"
                >
                  <X className="size-6" />
                </button>

                {!tutor.currentGif ? (
                  /* ── Big orb (no GIF shown) ── */
                  <>
                    <button
                      type="button"
                      onClick={closeAssistant}
                      aria-label="Sprachassistent schließen"
                      className="relative flex size-44 cursor-pointer items-center justify-center"
                    >
                      {voiceActive ? (
                        <>
                          <span className="absolute inset-0 animate-ping rounded-full bg-[#a953da]/15" />
                          <span className="absolute inset-4 animate-pulse rounded-full bg-[#39c9f6]/25" />
                        </>
                      ) : null}
                      <div
                        className={cn(
                          "relative flex size-28 items-center justify-center rounded-full bg-[linear-gradient(146deg,#a953da_7%,#39c9f6_93%)] transition-all",
                          voiceActive
                            ? "shadow-[0_0_60px_rgba(169,83,218,0.45)]"
                            : "opacity-70"
                        )}
                      >
                        <div className="flex h-10 items-end gap-1">
                          {[0.1, 0.35, 0.2, 0.5, 0.3].map((delay, i) => (
                            <span
                              key={i}
                              className={cn(
                                "w-1 rounded-full bg-white",
                                tutor.status === "speaking" ||
                                  tutor.status === "responding"
                                  ? "wave-bar"
                                  : "h-2 opacity-60"
                              )}
                              style={{ animationDelay: `${delay}s` }}
                            />
                          ))}
                        </div>
                      </div>
                    </button>
                    <div className="w-full text-center">
                      <p
                        className={cn(
                          "label-caps text-2xl tracking-[0.2em]",
                          tutor.status === "error" ? "text-error" : "text-[#a953da]"
                        )}
                      >
                        {STATUS_LABEL[tutor.status]}
                      </p>
                      {tutor.error ? (
                        <p className="mt-2 text-base text-error">{tutor.error}</p>
                      ) : null}
                      {tutor.transcript ? (
                        <p className="mt-2 text-3xl italic text-black/60">
                          &quot;{tutor.transcript}&quot;
                        </p>
                      ) : null}
                      {tutor.answer ? (
                        <p className="mt-4 text-3xl leading-relaxed text-black/70">
                          {tutor.answer}
                        </p>
                      ) : null}
                    </div>
                  </>
                ) : (
                  /* ── Bubble + GIF layout (agent has replied) ── */
                  <>
                    {/* Single persistent bubble — no key so it's never remounted */}
                    <div className="slide-up-anim w-full">
                      {tutor.transcript ? (
                        <p className="mb-4 text-right text-3xl italic text-black/60">
                          &quot;{tutor.transcript}&quot;
                        </p>
                      ) : null}

                      <div className="flex items-center gap-6 rounded-2xl bg-white px-7 py-6 shadow-lg">
                        {/* Mini orb */}
                        <div className="relative shrink-0">
                          {voiceActive ? (
                            <span className="absolute inset-0 animate-ping rounded-full bg-[#a953da]/20" />
                          ) : null}
                          <div className="relative flex size-12 items-center justify-center rounded-full bg-[linear-gradient(146deg,#a953da_7%,#39c9f6_93%)]">
                            <div className="flex h-6 items-end gap-1">
                              {[0.1, 0.35, 0.2, 0.5, 0.3].map((delay, i) => (
                                <span
                                  key={i}
                                  className={cn(
                                    "w-1 rounded-full bg-white",
                                    tutor.status === "speaking" ||
                                      tutor.status === "responding"
                                      ? "wave-bar"
                                      : "h-2 opacity-60"
                                  )}
                                  style={{ animationDelay: `${delay}s` }}
                                />
                              ))}
                            </div>
                          </div>
                        </div>

                        {/* Answer + status */}
                        <div className="min-w-0 flex-1">
                          <p className="text-3xl leading-relaxed text-black/80">
                            {tutor.answer}
                          </p>
                          {tutor.error ? (
                            <p className="mt-1 text-[18px] text-error">{tutor.error}</p>
                          ) : null}
                          <p
                            className={cn(
                              "mt-3 text-2xl font-medium uppercase tracking-[0.15em]",
                              tutor.status === "error" ? "text-error" : "text-[#a953da]"
                            )}
                          >
                            {STATUS_LABEL[tutor.status]}
                          </p>
                        </div>
                      </div>
                    </div>

                    {/* GIF — keyed so it animates in whenever it changes */}
                    {tutor.currentGif ? (
                      <img
                        key={tutor.currentGif}
                        src={withBasePath(`/gifs/${tutor.currentGif}`)}
                        alt=""
                        className="slide-down-anim max-h-96 max-w-2xl rounded-2xl object-contain shadow-md"
                      />
                    ) : null}
                  </>
                )}
              </div>
            ) : null}
          </main>
        </div>

        {/* Climate bar */}
        <div className="flex h-16 shrink-0 items-center justify-between border-t border-[#e2e2e2] bg-[#f2f1f2] px-8 text-[#6c6c6c]">
          <div className="flex items-center gap-5">
            <Minus className="size-6" />
            <span className="text-2xl">21.0°</span>
            <Plus className="size-6" />
            <span className="mx-3 h-9 w-px bg-[#d8d8d8]" />
            <Armchair className="size-7" />
          </div>
          <div className="flex items-center gap-8">
            <Fan className="size-7" />
            <span className="h-9 w-px bg-[#d8d8d8]" />
            <Wind className="size-7" />
          </div>
          <div className="flex items-center gap-5">
            <Armchair className="size-7" />
            <span className="mx-3 h-9 w-px bg-[#d8d8d8]" />
            <Minus className="size-6" />
            <span className="text-2xl">22.0°</span>
            <Plus className="size-6" />
          </div>
        </div>
      </div>

      {/* Debug text input — invisible unless hovered; hidden during screenshots */}
      {REALTIME_TEXT_INPUT ? (
        <div className="fixed bottom-5 right-5 z-[70] flex flex-col items-end gap-2">
          {textInputVisible ? (
            <form
              onSubmit={(e) => {
                e.preventDefault()
                const text = textDraft.trim()
                if (!text) return
                tutor.sendText(text)
                setTextDraft("")
                setTextInputVisible(false)
              }}
              className="flex items-center gap-2"
            >
              <input
                autoFocus
                type="text"
                value={textDraft}
                onChange={(e) => setTextDraft(e.target.value)}
                onKeyDown={(e) => {
                  if (e.key === "Escape") setTextInputVisible(false)
                }}
                placeholder="Nachricht eingeben…"
                disabled={tutor.status === "idle" || tutor.status === "connecting" || tutor.status === "responding"}
                className="w-72 rounded-full border border-black/10 bg-white/90 px-4 py-2 text-[13px] text-black shadow-lg placeholder:text-black/30 focus:outline-none disabled:opacity-40"
              />
              <button
                type="submit"
                disabled={!textDraft.trim() || tutor.status === "idle" || tutor.status === "connecting" || tutor.status === "responding"}
                className="rounded-full bg-black/70 px-4 py-2 text-[13px] text-white transition-opacity disabled:opacity-30"
              >
                Senden
              </button>
            </form>
          ) : (
            <button
              type="button"
              onClick={() => setTextInputVisible(true)}
              className="text-[12px] text-transparent transition-colors duration-200 hover:text-gray-400 select-none"
            >
              Texteingabe zeigen
            </button>
          )}
        </div>
      ) : null}

      {/* Short warning before ending the drive */}
      {endConfirmOpen && next ? (
        <div
          className="fixed inset-0 z-[60] flex items-center justify-center bg-black/40 px-8 backdrop-blur-sm"
          onClick={() => setEndConfirmOpen(false)}
        >
          <div
            role="dialog"
            aria-modal="true"
            aria-labelledby="end-confirm-title"
            className="w-full max-w-md rounded-3xl bg-white p-8 shadow-2xl"
            onClick={(e) => e.stopPropagation()}
          >
            <div className="flex items-center gap-3">
              <span className="flex size-11 shrink-0 items-center justify-center rounded-full bg-[#d13438]/10 text-[#d13438]">
                <TriangleAlert className="size-6" />
              </span>
              <h2
                id="end-confirm-title"
                className="text-2xl font-semibold text-black"
              >
                Fahrt beenden?
              </h2>
            </div>
            <p className="mt-3 text-base text-black/60">
              Die Fahrt wird beendet und kann nicht fortgesetzt werden. Sie
              gelangen anschließend zum Abschluss der Studie.
            </p>
            <div className="mt-8 flex justify-end gap-3">
              <button
                type="button"
                onClick={() => setEndConfirmOpen(false)}
                className="rounded-full border border-[#d8d8d8] bg-white px-6 py-2.5 text-[15px] text-[#5f5f61] transition-colors hover:bg-black/5"
              >
                Abbrechen
              </button>
              <Link
                href={next.path}
                onClick={() => markDriveEnded()}
                className="flex items-center gap-1.5 rounded-full bg-[#d13438] px-6 py-2.5 text-[15px] font-medium text-white transition-colors hover:bg-[#b52b2f]"
              >
                Fahrt beenden
                <ArrowRight className="size-4" />
              </Link>
            </div>
          </div>
        </div>
      ) : null}

      {/* Confirm before leaving the Eingewöhnungsumgebung — cues the
          Studienleitung to start SILAB only once this is confirmed. */}
      {startConfirmOpen ? (
        <div
          className="fixed inset-0 z-[60] flex items-center justify-center bg-black/40 px-8 backdrop-blur-sm"
          onClick={() => setStartConfirmOpen(false)}
        >
          <div
            role="dialog"
            aria-modal="true"
            aria-labelledby="start-confirm-title"
            className="w-full max-w-md rounded-3xl bg-white p-8 shadow-2xl"
            onClick={(e) => e.stopPropagation()}
          >
            <div className="flex items-center gap-3">
              <span className="flex size-11 shrink-0 items-center justify-center rounded-full bg-black/5 text-black">
                <TriangleAlert className="size-6" />
              </span>
              <h2
                id="start-confirm-title"
                className="text-2xl font-semibold text-black"
              >
                Fahrt starten?
              </h2>
            </div>
            <p className="mt-3 text-base text-black/60">
              Dieser Schritt darf nur von der Studienleitung durchgeführt
              werden. Für Studienleitung: Bitte die SILAB Simulation nur erst
              starten, nachdem der Button unten gedrückt wird.
            </p>
            <div className="mt-8 flex justify-end gap-3">
              <button
                type="button"
                onClick={() => setStartConfirmOpen(false)}
                className="rounded-full border border-[#d8d8d8] bg-white px-6 py-2.5 text-[15px] text-[#5f5f61] transition-colors hover:bg-black/5"
              >
                Abbrechen
              </button>
              <button
                type="button"
                disabled={!startConfirmEnabled}
                onClick={confirmStartDrive}
                className="flex items-center gap-2 rounded-full bg-black px-6 py-2.5 text-[15px] font-medium text-white transition-colors hover:bg-black/80 disabled:cursor-not-allowed disabled:opacity-40"
              >
                <Play className="size-4 fill-current" />
                Fahrt starten
              </button>
            </div>
          </div>
        </div>
      ) : null}
    </div>
  )
}

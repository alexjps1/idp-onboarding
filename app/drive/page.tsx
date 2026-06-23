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
import { ArrowLeft, ArrowRight } from "lucide-react"

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

const SIDEBAR_APPS = [
  { icon: Navigation, label: "Karte" },
  { icon: Music, label: "Medien" },
  { icon: Phone, label: "Telefon" },
  { icon: Settings, label: "Einstellungen" },
] as const

const STATUS_LABEL: Record<VoiceTutorStatus, string> = {
  idle: "Mikrofon aus",
  connecting: "Verbinde…",
  listening: "Ich höre zu…",
  speaking: "Ich höre Sie…",
  responding: "Ich antworte…",
  error: "Fehler",
}

export default function DrivePage() {
  const [assistantOpen, setAssistantOpen] = React.useState(false)
  const [playing, setPlaying] = React.useState(true)
  const [endConfirmOpen, setEndConfirmOpen] = React.useState(false)
  const [textDraft, setTextDraft] = React.useState("")
  const [textInputVisible, setTextInputVisible] = React.useState(false)
  const { previous, next } = getAdjacentSteps("drive")
  const {
    participantId,
    mode,
    theory,
    practice,
    startVoiceConversation,
    appendVoiceMessage,
  } = useStudy()
  const withTutor = mode !== "onboarding-only"
  const tutor = useVoiceTutor({ onMessage: appendVoiceMessage })

  // Open/close the assistant overlay and the mic together. Each open starts a
  // fresh conversation in the study record (the tutor can be opened repeatedly).
  function toggleAssistant() {
    setAssistantOpen((open) => {
      const nextOpen = !open
      if (nextOpen) {
        startVoiceConversation("user_initiated")
        void tutor.start()
      } else {
        tutor.stop()
      }
      return nextOpen
    })
  }

  // Proactive trigger: the first time the driving automation is switched on,
  // open the assistant on its own and have it greet (unless already open).
  const openAssistantProactively = React.useCallback(() => {
    setAssistantOpen(true)
    startVoiceConversation("proactive")
    void tutor.start({ proactive: true, theory, practice })
  }, [tutor, theory, practice, startVoiceConversation])

  useAdasMonitor({
    enabled: withTutor,
    onActivate: openAssistantProactively,
    shouldSuppress: () => assistantOpen,
  })

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

  return (
    <div className="flex h-screen w-screen flex-col overflow-hidden bg-[#f2f1f2] text-black">
      {/* MyCar infotainment screen */}
      <div className="flex flex-grow flex-col overflow-hidden">
        {/* Car status bar — carries the study chrome (ID + navigation) */}
        <div className="relative flex h-14 shrink-0 items-center border-b border-[#e2e2e2] bg-[#f2f1f2]">
          <div className="flex shrink-0 items-center gap-3 border-r border-[#e2e2e2] px-5">
            <span className="flex size-8 items-center justify-center rounded-full bg-gradient-to-br from-[#1973f7] to-[#39c9f6] text-white">
              <Navigation className="size-4 fill-white" />
            </span>
            <span className="text-[15px] whitespace-nowrap">
              Probanden-ID:{" "}
              <span className="font-bold">{participantId ?? "—"}</span>
            </span>
          </div>
          <span className="absolute left-1/2 -translate-x-1/2 text-[15px] tabular-nums text-[#7e7f7f]">
            {time ?? "--:--"}
          </span>
          <div className="ml-auto flex items-center gap-6 px-5 text-[#858686]">
            <Signal className="size-5" />
            <Bluetooth className="size-5" />
            <span className="text-[15px]">LTE</span>
            <User className="size-5" />
            <span className="text-[15px]">18°C</span>

            {/* Study navigation */}
            <span className="h-7 w-px bg-[#d8d8d8]" />
            {previous ? (
              <Link
                href={previous.path}
                className="flex items-center gap-1.5 rounded-full border border-[#d8d8d8] bg-white px-4 py-1.5 text-[14px] text-[#5f5f61] transition-colors hover:bg-black/5"
              >
                <ArrowLeft className="size-4" />
                Zurück
              </Link>
            ) : null}
            {next ? (
              <button
                type="button"
                onClick={() => setEndConfirmOpen(true)}
                className="flex items-center gap-1.5 rounded-full bg-[#1973f7] px-4 py-1.5 text-[14px] font-medium text-white transition-colors hover:bg-[#1565d8]"
              >
                Weiter
                <ArrowRight className="size-4" />
              </button>
            ) : null}
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

            {/* Assistent — gradient, wired to the voice tutor (mit-Tutor only) */}
            {withTutor ? (
              <button
                type="button"
                aria-label="Assistent"
                aria-pressed={assistantOpen}
                onClick={toggleAssistant}
                className={cn(
                  "flex size-[88px] flex-col items-center justify-center gap-2 rounded-2xl text-white transition-transform",
                  "bg-[linear-gradient(146deg,#a953da_7%,#39c9f6_93%)]",
                  assistantOpen
                    ? "scale-105 shadow-lg shadow-[#a953da]/30"
                    : "hover:scale-105"
                )}
              >
                <Sparkles className="size-7" />
                <span className="text-[15px] font-semibold">Assistent</span>
              </button>
            ) : null}
          </aside>

          {/* Media player */}
          <main className="relative flex flex-grow items-center justify-center overflow-hidden bg-gradient-to-br from-[#eef1f5] to-[#e3e7ec] p-8">
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
                      className="relative flex size-64 cursor-pointer items-center justify-center"
                    >
                      {voiceActive ? (
                        <>
                          <span className="absolute inset-0 animate-ping rounded-full bg-[#a953da]/15" />
                          <span className="absolute inset-6 animate-pulse rounded-full bg-[#39c9f6]/25" />
                        </>
                      ) : null}
                      <div
                        className={cn(
                          "relative flex size-40 items-center justify-center rounded-full bg-[linear-gradient(146deg,#a953da_7%,#39c9f6_93%)] transition-all",
                          voiceActive
                            ? "shadow-[0_0_60px_rgba(169,83,218,0.45)]"
                            : "opacity-70"
                        )}
                      >
                        <div className="flex h-14 items-end gap-1.5">
                          {[0.1, 0.35, 0.2, 0.5, 0.3].map((delay, i) => (
                            <span
                              key={i}
                              className={cn(
                                "w-1.5 rounded-full bg-white",
                                tutor.status === "speaking" ||
                                  tutor.status === "responding"
                                  ? "wave-bar"
                                  : "h-3 opacity-60"
                              )}
                              style={{ animationDelay: `${delay}s` }}
                            />
                          ))}
                        </div>
                      </div>
                    </button>
                    <div className="max-w-xl text-center">
                      <p
                        className={cn(
                          "label-caps tracking-[0.2em]",
                          tutor.status === "error" ? "text-error" : "text-[#a953da]"
                        )}
                      >
                        {STATUS_LABEL[tutor.status]}
                      </p>
                      {tutor.error ? (
                        <p className="mt-2 text-sm text-error">{tutor.error}</p>
                      ) : null}
                      {tutor.transcript ? (
                        <p className="mt-2 text-lg italic text-black/60">
                          &quot;{tutor.transcript}&quot;
                        </p>
                      ) : null}
                      {tutor.answer ? (
                        <p className="mt-4 text-base leading-relaxed text-black/70">
                          {tutor.answer}
                        </p>
                      ) : null}
                    </div>
                  </>
                ) : (
                  /* ── Bubble + GIF layout (agent has replied) ── */
                  <>
                    {/* Single persistent bubble — no key so it's never remounted */}
                    <div className="slide-up-anim w-full max-w-2xl">
                      {tutor.transcript ? (
                        <p className="mb-4 text-right text-[17px] italic text-black/60">
                          &quot;{tutor.transcript}&quot;
                        </p>
                      ) : null}

                      <div className="flex items-center gap-6 rounded-2xl bg-white px-7 py-6 shadow-lg">
                        {/* Mini orb */}
                        <div className="relative shrink-0">
                          {voiceActive ? (
                            <span className="absolute inset-0 animate-ping rounded-full bg-[#a953da]/20" />
                          ) : null}
                          <div className="relative flex size-16 items-center justify-center rounded-full bg-[linear-gradient(146deg,#a953da_7%,#39c9f6_93%)]">
                            <div className="flex h-8 items-end gap-1">
                              {[0.1, 0.35, 0.2, 0.5, 0.3].map((delay, i) => (
                                <span
                                  key={i}
                                  className={cn(
                                    "w-1 rounded-full bg-white",
                                    tutor.status === "speaking" ||
                                      tutor.status === "responding"
                                      ? "wave-bar"
                                      : "h-3 opacity-60"
                                  )}
                                  style={{ animationDelay: `${delay}s` }}
                                />
                              ))}
                            </div>
                          </div>
                        </div>

                        {/* Answer + status */}
                        <div className="min-w-0 flex-1">
                          <p className="text-[17px] leading-relaxed text-black/80">
                            {tutor.answer}
                          </p>
                          {tutor.error ? (
                            <p className="mt-1 text-[16px] text-error">{tutor.error}</p>
                          ) : null}
                          <p
                            className={cn(
                              "mt-3 text-[12px] font-medium uppercase tracking-[0.15em]",
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

      {/* "Studie beenden?" confirmation before the final step */}
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
            <h2
              id="end-confirm-title"
              className="text-2xl font-semibold text-black"
            >
              Studie beenden?
            </h2>
            <p className="mt-2 text-base text-black/60">
              Möchten Sie die Fahrtansicht verlassen und zum Abschluss der
              Studie fortfahren?
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
                className="flex items-center gap-1.5 rounded-full bg-[#1973f7] px-6 py-2.5 text-[15px] font-medium text-white transition-colors hover:bg-[#1565d8]"
              >
                Studie beenden
                <ArrowRight className="size-4" />
              </Link>
            </div>
          </div>
        </div>
      ) : null}
    </div>
  )
}

"use client"

import * as React from "react"

import { saveSession, INITIAL_TRIGGER_STATES, INITIAL_QUIZ } from "@/lib/study-data"
import type {
  AdaptStatus,
  AdaptedSection,
  ProactiveTriggerState,
  ProactiveTriggerStates,
  QuizAnswer,
  QuizRecord,
  StudySession,
  VoiceConversation,
  VoiceConversationTrigger,
  VoiceMessage,
} from "@/lib/study-data"

export type StudyMode = "onboarding-only" | "drive-only" | "onboarding-drive"

/** Self-assessment ratings (1–7 scale) keyed by assistance-system name. */
export type Ratings = Record<string, number>

type StudyState = {
  participantId: string | null
  mode: StudyMode | null
  /**
   * ISO timestamp of when the participant began the study — set when they press
   * the welcome-screen button ("Anpassung starten", or "Zur Fahrt" in the
   * drive-only flow; see StudyProvider.markStarted). Every mode passes through
   * the welcome screen, so this is always stamped there.
   */
  startedAt: string | null
  /**
   * ISO timestamp of when the participant finished the onboarding — set when
   * they press "OK" on the post-quiz congratulations screen, right before the
   * drive (see StudyProvider.markOnboardingEnded).
   */
  onboardingEndedAt: string | null
  /**
   * ISO timestamp of when the participant pressed "Fahrt starten" on /drive,
   * leaving the Eingewöhnungsumgebung. This is the UI action, not the
   * simulation itself starting — see simulationStartedAt for that (see
   * StudyProvider.markDriveStarted).
   */
  driveStartedAt: string | null
  /**
   * ISO timestamp of the first SILAB packet received after driveStartedAt —
   * i.e. when the simulation itself actually started (see
   * StudyProvider.markSimulationStarted / use-simulation-start.ts).
   */
  simulationStartedAt: string | null
  /**
   * ISO timestamp of when the participant confirmed "Fahrt beenden" on /drive,
   * right before leaving for the study's closing screen (see
   * StudyProvider.markDriveEnded).
   */
  driveEndedAt: string | null
  /** Theoretical-knowledge ratings from the self-assessment Fragebogen. */
  theory: Ratings
  /** Practical-experience ratings from the self-assessment Fragebogen. */
  practice: Ratings
  /** Whether the guide personalised the modules or fell back to the baseline. */
  adaptStatus: AdaptStatus | null
  /** The modules as adapted to the participant's prior knowledge (null = baseline). */
  adaptedModules: AdaptedSection[] | null
  /** The post-onboarding knowledge-check quiz (timestamps + answers). */
  quiz: QuizRecord
  /** One entry per time the voice tutor was opened during the drive. */
  voiceConversations: VoiceConversation[]
  /** Diagnostic state of each proactive trigger over the drive (see ProactiveTriggerState). */
  triggerStates: ProactiveTriggerStates
}

type StudyContextValue = StudyState & {
  setParticipantId: (id: string | null) => void
  setMode: (mode: StudyMode | null) => void
  /** Stamp the study-begin time (the welcome screen's "Anpassung starten"). */
  markStarted: () => void
  /** Stamp the onboarding-end time (the post-quiz congratulations "OK"). */
  markOnboardingEnded: () => void
  /** Stamp the drive-start time ("Fahrt starten", leaving the Eingewöhnungsumgebung). */
  markDriveStarted: () => void
  /** Stamp the simulation-start time (first SILAB packet after markDriveStarted). */
  markSimulationStarted: (at: string) => void
  /** Stamp the drive-end time (confirming "Fahrt beenden" in the dialog). */
  markDriveEnded: () => void
  setTheory: (system: string, value: number) => void
  setPractice: (system: string, value: number) => void
  setAdaptedModules: (
    sections: AdaptedSection[] | null,
    status: AdaptStatus
  ) => void
  /** Begin the quiz: stamps the start time and clears any prior answers. */
  startQuiz: () => void
  recordQuizAnswer: (answer: QuizAnswer) => void
  /** Stamp the quiz end time (after the last question is answered). */
  finishQuiz: () => void
  startVoiceConversation: (trigger?: VoiceConversationTrigger) => void
  appendVoiceMessage: (message: VoiceMessage) => void
  setTriggerState: (
    id: keyof ProactiveTriggerStates,
    state: ProactiveTriggerState
  ) => void
  reset: () => void
}

const STORAGE_KEY = "research-monitor-study"
const SERVER_SNAPSHOT: StudyState = {
  participantId: null,
  mode: null,
  startedAt: null,
  onboardingEndedAt: null,
  driveStartedAt: null,
  simulationStartedAt: null,
  driveEndedAt: null,
  theory: {},
  practice: {},
  adaptStatus: null,
  adaptedModules: null,
  quiz: INITIAL_QUIZ,
  voiceConversations: [],
  triggerStates: INITIAL_TRIGGER_STATES,
}

const StudyContext = React.createContext<StudyContextValue | null>(null)

/**
 * Tiny external store backing the study state. Persists to localStorage and is
 * read through useSyncExternalStore, which keeps server/client snapshots stable
 * and avoids setState-in-effect hydration churn. Every mutation also mirrors the
 * full record to the server (debounced) so the study data survives the browser.
 */
function createStudyStore() {
  let snapshot: StudyState | null = null
  const listeners = new Set<() => void>()
  let saveTimer: ReturnType<typeof setTimeout> | null = null

  function load(): StudyState {
    try {
      const raw = window.localStorage.getItem(STORAGE_KEY)
      if (!raw) return SERVER_SNAPSHOT
      const parsed = JSON.parse(raw) as Partial<StudyState>
      return {
        participantId: parsed.participantId ?? null,
        mode: parsed.mode ?? null,
        startedAt: parsed.startedAt ?? null,
        onboardingEndedAt: parsed.onboardingEndedAt ?? null,
        driveStartedAt: parsed.driveStartedAt ?? null,
        simulationStartedAt: parsed.simulationStartedAt ?? null,
        driveEndedAt: parsed.driveEndedAt ?? null,
        theory: parsed.theory ?? {},
        practice: parsed.practice ?? {},
        adaptStatus: parsed.adaptStatus ?? null,
        adaptedModules: parsed.adaptedModules ?? null,
        quiz: parsed.quiz ?? INITIAL_QUIZ,
        voiceConversations: parsed.voiceConversations ?? [],
        triggerStates: { ...INITIAL_TRIGGER_STATES, ...parsed.triggerStates },
      }
    } catch {
      return SERVER_SNAPSHOT
    }
  }

  function getSnapshot(): StudyState {
    if (snapshot === null) snapshot = load()
    return snapshot
  }

  // Mirror the latest snapshot to the server, debounced so a burst of updates
  // (e.g. streamed voice turns) collapses into one write. Only once a
  // participant id exists — nothing is persisted on the landing page.
  function scheduleSave() {
    if (typeof window === "undefined") return
    if (saveTimer) clearTimeout(saveTimer)
    saveTimer = setTimeout(() => {
      saveTimer = null
      const snap = getSnapshot()
      if (!snap.participantId) return
      void saveSession(snap as StudySession)
    }, 800)
  }

  function set(partial: Partial<StudyState>) {
    snapshot = { ...getSnapshot(), ...partial }
    try {
      window.localStorage.setItem(STORAGE_KEY, JSON.stringify(snapshot))
    } catch {
      // Ignore quota / privacy-mode write failures — state still lives in memory.
    }
    listeners.forEach((listener) => listener())
    scheduleSave()
  }

  return {
    getSnapshot,
    getServerSnapshot: () => SERVER_SNAPSHOT,
    subscribe(listener: () => void) {
      listeners.add(listener)
      return () => listeners.delete(listener)
    },
    setParticipantId: (participantId: string | null) =>
      set({ participantId }),
    setMode: (mode: StudyMode | null) => set({ mode }),
    markStarted: () => set({ startedAt: new Date().toISOString() }),
    markOnboardingEnded: () =>
      set({ onboardingEndedAt: new Date().toISOString() }),
    markDriveStarted: () => set({ driveStartedAt: new Date().toISOString() }),
    markSimulationStarted: (at: string) => set({ simulationStartedAt: at }),
    markDriveEnded: () => set({ driveEndedAt: new Date().toISOString() }),
    setTheory: (system: string, value: number) =>
      set({ theory: { ...getSnapshot().theory, [system]: value } }),
    setPractice: (system: string, value: number) =>
      set({ practice: { ...getSnapshot().practice, [system]: value } }),
    setAdaptedModules: (
      adaptedModules: AdaptedSection[] | null,
      adaptStatus: AdaptStatus
    ) => set({ adaptedModules, adaptStatus }),
    startQuiz: () =>
      set({
        quiz: { startedAt: new Date().toISOString(), endedAt: null, answers: [] },
      }),
    recordQuizAnswer: (answer: QuizAnswer) =>
      set({
        quiz: {
          ...getSnapshot().quiz,
          answers: [...getSnapshot().quiz.answers, answer],
        },
      }),
    finishQuiz: () =>
      set({
        quiz: { ...getSnapshot().quiz, endedAt: new Date().toISOString() },
      }),
    startVoiceConversation: (
      trigger: VoiceConversationTrigger = "user_initiated"
    ) =>
      set({
        voiceConversations: [
          ...getSnapshot().voiceConversations,
          { trigger, startedAt: new Date().toISOString(), messages: [] },
        ],
      }),
    appendVoiceMessage: (message: VoiceMessage) => {
      const conversations = getSnapshot().voiceConversations
      if (conversations.length === 0) {
        // Defensive: a message arrived before a conversation was started.
        set({
          voiceConversations: [
            { trigger: "user_initiated", startedAt: message.at, messages: [message] },
          ],
        })
        return
      }
      const last = conversations[conversations.length - 1]
      set({
        voiceConversations: [
          ...conversations.slice(0, -1),
          { ...last, messages: [...last.messages, message] },
        ],
      })
    },
    setTriggerState: (
      id: keyof ProactiveTriggerStates,
      triggerState: ProactiveTriggerState
    ) =>
      set({
        triggerStates: {
          ...getSnapshot().triggerStates,
          [id]: { state: triggerState, at: new Date().toISOString() },
        },
      }),
    reset: () =>
      set({
        participantId: null,
        mode: null,
        startedAt: null,
        onboardingEndedAt: null,
        driveStartedAt: null,
        simulationStartedAt: null,
        driveEndedAt: null,
        theory: {},
        practice: {},
        adaptStatus: null,
        adaptedModules: null,
        quiz: INITIAL_QUIZ,
        voiceConversations: [],
        triggerStates: INITIAL_TRIGGER_STATES,
      }),
  }
}

const store = createStudyStore()

export function StudyProvider({ children }: { children: React.ReactNode }) {
  const state = React.useSyncExternalStore(
    store.subscribe,
    store.getSnapshot,
    store.getServerSnapshot
  )

  const value = React.useMemo<StudyContextValue>(
    () => ({
      ...state,
      setParticipantId: store.setParticipantId,
      setMode: store.setMode,
      markStarted: store.markStarted,
      markOnboardingEnded: store.markOnboardingEnded,
      markDriveStarted: store.markDriveStarted,
      markSimulationStarted: store.markSimulationStarted,
      markDriveEnded: store.markDriveEnded,
      setTheory: store.setTheory,
      setPractice: store.setPractice,
      setAdaptedModules: store.setAdaptedModules,
      startQuiz: store.startQuiz,
      recordQuizAnswer: store.recordQuizAnswer,
      finishQuiz: store.finishQuiz,
      startVoiceConversation: store.startVoiceConversation,
      appendVoiceMessage: store.appendVoiceMessage,
      setTriggerState: store.setTriggerState,
      reset: store.reset,
    }),
    [state]
  )

  return <StudyContext.Provider value={value}>{children}</StudyContext.Provider>
}

export function useStudy(): StudyContextValue {
  const context = React.useContext(StudyContext)
  if (!context) {
    throw new Error("useStudy must be used within a StudyProvider")
  }
  return context
}

"use client"

import * as React from "react"

import { saveSession } from "@/lib/study-data"
import type {
  AdaptStatus,
  AdaptedSection,
  StudySession,
  VoiceConversation,
  VoiceConversationTrigger,
  VoiceMessage,
} from "@/lib/study-data"

export type StudyMode = "onboarding-only" | "onboarding-drive"

/** Self-assessment ratings (1–7 scale) keyed by assistance-system name. */
export type Ratings = Record<string, number>

type StudyState = {
  participantId: string | null
  mode: StudyMode | null
  /** ISO timestamp of when the participant id was first assigned. */
  startedAt: string | null
  /** Theoretical-knowledge ratings from the self-assessment Fragebogen. */
  theory: Ratings
  /** Practical-experience ratings from the self-assessment Fragebogen. */
  practice: Ratings
  /** Whether the guide personalised the modules or fell back to the baseline. */
  adaptStatus: AdaptStatus | null
  /** The modules as adapted to the participant's prior knowledge (null = baseline). */
  adaptedModules: AdaptedSection[] | null
  /** One entry per time the voice tutor was opened during the drive. */
  voiceConversations: VoiceConversation[]
}

type StudyContextValue = StudyState & {
  setParticipantId: (id: string | null) => void
  setMode: (mode: StudyMode | null) => void
  setTheory: (system: string, value: number) => void
  setPractice: (system: string, value: number) => void
  setAdaptedModules: (
    sections: AdaptedSection[] | null,
    status: AdaptStatus
  ) => void
  startVoiceConversation: (trigger?: VoiceConversationTrigger) => void
  appendVoiceMessage: (message: VoiceMessage) => void
  reset: () => void
}

const STORAGE_KEY = "research-monitor-study"
const SERVER_SNAPSHOT: StudyState = {
  participantId: null,
  mode: null,
  startedAt: null,
  theory: {},
  practice: {},
  adaptStatus: null,
  adaptedModules: null,
  voiceConversations: [],
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
        theory: parsed.theory ?? {},
        practice: parsed.practice ?? {},
        adaptStatus: parsed.adaptStatus ?? null,
        adaptedModules: parsed.adaptedModules ?? null,
        voiceConversations: parsed.voiceConversations ?? [],
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
      set(
        participantId && !getSnapshot().startedAt
          ? { participantId, startedAt: new Date().toISOString() }
          : { participantId }
      ),
    setMode: (mode: StudyMode | null) => set({ mode }),
    setTheory: (system: string, value: number) =>
      set({ theory: { ...getSnapshot().theory, [system]: value } }),
    setPractice: (system: string, value: number) =>
      set({ practice: { ...getSnapshot().practice, [system]: value } }),
    setAdaptedModules: (
      adaptedModules: AdaptedSection[] | null,
      adaptStatus: AdaptStatus
    ) => set({ adaptedModules, adaptStatus }),
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
    reset: () =>
      set({
        participantId: null,
        mode: null,
        startedAt: null,
        theory: {},
        practice: {},
        adaptStatus: null,
        adaptedModules: null,
        voiceConversations: [],
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
      setTheory: store.setTheory,
      setPractice: store.setPractice,
      setAdaptedModules: store.setAdaptedModules,
      startVoiceConversation: store.startVoiceConversation,
      appendVoiceMessage: store.appendVoiceMessage,
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

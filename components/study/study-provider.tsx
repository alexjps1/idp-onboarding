"use client"

import * as React from "react"

export type StudyMode = "onboarding-only" | "onboarding-drive"

type StudyState = {
  participantId: string | null
  mode: StudyMode | null
}

type StudyContextValue = StudyState & {
  setParticipantId: (id: string | null) => void
  setMode: (mode: StudyMode | null) => void
  reset: () => void
}

const STORAGE_KEY = "research-monitor-study"
const SERVER_SNAPSHOT: StudyState = { participantId: null, mode: null }

const StudyContext = React.createContext<StudyContextValue | null>(null)

/**
 * Tiny external store backing the study state. Persists to localStorage and is
 * read through useSyncExternalStore, which keeps server/client snapshots stable
 * and avoids setState-in-effect hydration churn.
 */
function createStudyStore() {
  let snapshot: StudyState | null = null
  const listeners = new Set<() => void>()

  function load(): StudyState {
    try {
      const raw = window.localStorage.getItem(STORAGE_KEY)
      if (!raw) return SERVER_SNAPSHOT
      const parsed = JSON.parse(raw) as Partial<StudyState>
      return {
        participantId: parsed.participantId ?? null,
        mode: parsed.mode ?? null,
      }
    } catch {
      return SERVER_SNAPSHOT
    }
  }

  function getSnapshot(): StudyState {
    if (snapshot === null) snapshot = load()
    return snapshot
  }

  function set(partial: Partial<StudyState>) {
    snapshot = { ...getSnapshot(), ...partial }
    try {
      window.localStorage.setItem(STORAGE_KEY, JSON.stringify(snapshot))
    } catch {
      // Ignore quota / privacy-mode write failures — state still lives in memory.
    }
    listeners.forEach((listener) => listener())
  }

  return {
    getSnapshot,
    getServerSnapshot: () => SERVER_SNAPSHOT,
    subscribe(listener: () => void) {
      listeners.add(listener)
      return () => listeners.delete(listener)
    },
    setParticipantId: (participantId: string | null) => set({ participantId }),
    setMode: (mode: StudyMode | null) => set({ mode }),
    reset: () => set({ participantId: null, mode: null }),
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

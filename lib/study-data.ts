/**
 * Shared types and the client-side save helper for the per-participant study
 * record. Everything a participant produces — questionnaire ratings, the modules
 * the guide adapted to their prior knowledge, and the full voice-tutor
 * conversation log — is collected into a single {@link StudySession} that the
 * store mirrors to the server (one JSON file per participant) for later analysis.
 */

import { withBasePath } from "@/lib/base-path"
import type { StudyMode, Ratings } from "@/components/study/study-provider"

/** A single completed turn in a voice-tutor conversation. */
export type VoiceMessage = {
  role: "user" | "assistant"
  text: string
  /** ISO timestamp of when the turn completed. */
  at: string
}

/**
 * Why a voice conversation was started. "user_initiated" = the participant
 * tapped the assistant button; "proactive" = the assistant opened itself when
 * the driving automation was first switched on (see use-adas-monitor).
 */
export type VoiceConversationTrigger = "user_initiated" | "proactive"

/**
 * One run of the voice tutor. The participant can open and close the assistant
 * multiple times per drive; each open starts a fresh conversation.
 */
export type VoiceConversation = {
  trigger: VoiceConversationTrigger
  /** ISO timestamp of when the assistant was opened. */
  startedAt: string
  messages: VoiceMessage[]
}

/** A module section after the guide adapted it to the participant's knowledge. */
export type AdaptedSection = {
  id: string
  title: string
  paragraphs: { text: string; gifs?: string[] }[]
  omitted?: boolean
}

/** Whether the guide content was personalised or fell back to the baseline. */
export type AdaptStatus = "adapted" | "baseline"

/** The complete record persisted per participant. */
export type StudySession = {
  participantId: string
  mode: StudyMode | null
  startedAt: string | null
  theory: Ratings
  practice: Ratings
  adaptStatus: AdaptStatus | null
  adaptedModules: AdaptedSection[] | null
  voiceConversations: VoiceConversation[]
}

/**
 * Mirror the current session to the server. Best-effort: failures are logged but
 * never thrown, so a missing/slow backend can never block the study flow.
 */
export async function saveSession(session: StudySession): Promise<void> {
  try {
    await fetch(withBasePath("/api/study-data"), {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(session),
      keepalive: true,
    })
  } catch (err) {
    console.error("Failed to save study session", err)
  }
}

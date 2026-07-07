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
 * the driving automation was first switched on (see use-adas-monitor);
 * "proactive_intro" = the one-time self-introduction shortly after the drive
 * view loads (see use-intro-trigger); "proactive_zone_nudge" /
 * "proactive_system_limit" = the fixed-zone triggers on the track (see
 * use-zone-triggers).
 */
export type VoiceConversationTrigger =
  | "user_initiated"
  | "proactive"
  | "proactive_intro"
  | "proactive_zone_nudge"
  | "proactive_system_limit"

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

/**
 * Diagnostic state of one proactive trigger over the course of a drive, so a
 * "why didn't it fire" report can be answered from the saved session data
 * instead of live logs. Semantics per trigger, decided the moment its
 * condition (zone entry / timer elapsed / ADAS transition) is first met:
 * - "waiting": condition not yet met.
 * - "detected": condition met, but no tutor action was needed (ADAS already
 *   on for a zone nudge; ADAS was off beforehand for the system-limit
 *   explanation — never used by "intro"/"adas_on", which always need action
 *   once met).
 * - "suppressed": condition met, action needed, but the assistant was already
 *   open — dropped permanently, never retried (see use-adas-monitor.ts,
 *   use-intro-trigger.ts, use-zone-triggers.ts).
 * - "fired": condition met, action needed, tutor opened and spoke.
 */
export type ProactiveTriggerState = "waiting" | "detected" | "suppressed" | "fired"

/** A trigger's current state plus when it got there (null while still "waiting"). */
export type ProactiveTriggerEntry = {
  state: ProactiveTriggerState
  /** ISO timestamp of when this state was reached; null while still "waiting". */
  at: string | null
}

/** One entry per proactive trigger tracked over the drive (see ProactiveTriggerState). */
export type ProactiveTriggerStates = {
  intro: ProactiveTriggerEntry
  adasOn: ProactiveTriggerEntry
  zoneNudge1: ProactiveTriggerEntry
  zoneNudge2: ProactiveTriggerEntry
  zoneNudge3: ProactiveTriggerEntry
  zoneNudge4: ProactiveTriggerEntry
  zoneNudge5: ProactiveTriggerEntry
  zoneNudge6: ProactiveTriggerEntry
  systemLimit: ProactiveTriggerEntry
}

const WAITING_ENTRY: ProactiveTriggerEntry = { state: "waiting", at: null }

export const INITIAL_TRIGGER_STATES: ProactiveTriggerStates = {
  intro: WAITING_ENTRY,
  adasOn: WAITING_ENTRY,
  zoneNudge1: WAITING_ENTRY,
  zoneNudge2: WAITING_ENTRY,
  zoneNudge3: WAITING_ENTRY,
  zoneNudge4: WAITING_ENTRY,
  zoneNudge5: WAITING_ENTRY,
  zoneNudge6: WAITING_ENTRY,
  systemLimit: WAITING_ENTRY,
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

/** A single answered quiz question. */
export type QuizAnswer = {
  /** Category key of the question (see lib/quiz-questions.ts). */
  category: string
  /** Index of the question within the flat QUIZ_QUESTIONS list. */
  questionIndex: number
  /** Index of the option the participant selected. */
  selectedIndex: number
  correct: boolean
}

/** The post-onboarding knowledge-check quiz, with begin/end timestamps. */
export type QuizRecord = {
  /** ISO timestamp of when the quiz was opened. */
  startedAt: string | null
  /** ISO timestamp of when the last question was answered. */
  endedAt: string | null
  answers: QuizAnswer[]
}

export const INITIAL_QUIZ: QuizRecord = {
  startedAt: null,
  endedAt: null,
  answers: [],
}

/** The complete record persisted per participant. */
export type StudySession = {
  participantId: string
  mode: StudyMode | null
  startedAt: string | null
  /**
   * ISO timestamp of when the participant finished the onboarding — set when
   * they press "OK" on the post-quiz congratulations screen, right before the
   * drive. Null for the drive-only condition, which has no onboarding.
   */
  onboardingEndedAt: string | null
  /**
   * ISO timestamp of when the participant pressed "Fahrt starten" on /drive,
   * leaving the Eingewöhnungsumgebung (the pre-drive practice phase where the
   * tutor can be tried manually with no proactive triggers and the car isn't
   * driving yet). Null until that point. This is the UI action, not the
   * simulation itself starting — see simulationStartedAt for that. See
   * StudyProvider.markDriveStarted.
   */
  driveStartedAt: string | null
  /**
   * ISO timestamp of the first SILAB packet received at /api/silab-ingest
   * after driveStartedAt — i.e. when the simulation itself actually started,
   * as opposed to driveStartedAt (when the participant pressed the button).
   * Null until observed (and always null in SILAB_COMMUNICATION_MODE="tcp",
   * which has no push/receivedAt concept). See
   * StudyProvider.markSimulationStarted / use-simulation-start.ts.
   */
  simulationStartedAt: string | null
  /**
   * ISO timestamp of when the participant ended the drive — set when they
   * confirm "Fahrt beenden" in the confirmation dialog on /drive, right before
   * navigating to the study's closing screen. Null until confirmed. See
   * StudyProvider.markDriveEnded.
   */
  driveEndedAt: string | null
  theory: Ratings
  practice: Ratings
  adaptStatus: AdaptStatus | null
  adaptedModules: AdaptedSection[] | null
  quiz: QuizRecord
  voiceConversations: VoiceConversation[]
  triggerStates: ProactiveTriggerStates
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

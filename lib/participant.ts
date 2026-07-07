/**
 * Participant-ID handling for the study.
 *
 * An id is either typed by the Studienleiter on the landing page or generated
 * automatically. The allowed shape is up to eight characters of uppercase
 * letters, digits and underscores — the same pattern the server enforces before
 * writing a `data/sessions/<id>.json` file, which also blocks path traversal.
 * Auto-generated ids carry a `RAND` prefix so they are recognisable as such.
 */

import { withBasePath } from "@/lib/base-path"

/** Allowed participant-id shape: uppercase letters, digits, underscore, max 8. */
export const PARTICIPANT_ID_PATTERN = /^[A-Z0-9_]{1,8}$/

/**
 * Returns a randomly generated id such as `RAND0042`. The `RAND` prefix marks
 * it as auto-generated (as opposed to a custom id typed by the study lead).
 */
export function generateParticipantId(): string {
  const digits = Math.floor(Math.random() * 10000)
    .toString()
    .padStart(4, "0")
  return `RAND${digits}`
}

/** Whether a session file already exists on the server for this id. */
export async function isParticipantIdTaken(id: string): Promise<boolean> {
  try {
    const res = await fetch(
      withBasePath(`/api/study-data?id=${encodeURIComponent(id)}`),
      { cache: "no-store" }
    )
    if (!res.ok) return false
    const data = (await res.json()) as { exists?: boolean }
    return data.exists === true
  } catch {
    // If the check fails (offline etc.) don't block the run; treat the id as free.
    return false
  }
}

/**
 * Generates a random id that isn't already in use. Falls back to the last
 * candidate after a bounded number of attempts so an exhausted pool can never
 * hang the study — collisions are effectively impossible at the expected
 * participant count.
 */
export async function generateUniqueParticipantId(): Promise<string> {
  for (let attempt = 0; attempt < 50; attempt++) {
    const candidate = generateParticipantId()
    if (!(await isParticipantIdTaken(candidate))) return candidate
  }
  return generateParticipantId()
}

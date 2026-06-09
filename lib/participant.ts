/**
 * Participant-ID generation for the study. The id is derived from a time
 * component (base36 of the current timestamp), which is effectively unique per
 * participant since two people don't start in the same millisecond.
 */

/** Returns a time-based id such as `PB-LXK3F`. */
export function generateParticipantId(): string {
  const time = Date.now().toString(36).toUpperCase().slice(-5)
  return `PB-${time}`
}

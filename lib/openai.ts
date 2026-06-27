/**
 * Server-side OpenAI configuration. Kept tiny and dependency-free — the two
 * API routes call the REST endpoints directly with fetch, so there is no SDK
 * to wire up. All values come from environment variables (see .env.example).
 */

const OPENAI_BASE_URL = "https://api.openai.com/v1"

export const OPENAI_TRANSCRIPTION_MODEL =
  process.env.OPENAI_TRANSCRIPTION_MODEL ?? "gpt-4o-mini-transcribe"

export const OPENAI_CONTENT_MODEL =
  process.env.OPENAI_CONTENT_MODEL ?? "gpt-5-mini"

export const OPENAI_REALTIME_MODEL =
  process.env.OPENAI_REALTIME_MODEL ?? "gpt-realtime"

export const OPENAI_REALTIME_VOICE =
  process.env.OPENAI_REALTIME_VOICE ?? "cedar"

/**
 * Returns the configured API key, or null when only the dummy placeholder is
 * present. Routes use this to fail loudly (501) instead of sending a doomed
 * request to OpenAI during local prototyping.
 */
export function getOpenAIKey(): string | null {
  const key = process.env.OPENAI_API_KEY?.trim()
  if (!key || key.startsWith("sk-dummy")) return null
  return key
}

export { OPENAI_BASE_URL }

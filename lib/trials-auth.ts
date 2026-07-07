import { createHash } from "node:crypto"

/**
 * Password gate for /trials (the participant session data viewer) and its
 * /api/trials backing route. Not a full auth system — one shared password
 * for the study team — but enforced server-side on the API route itself,
 * not just the page's UI, so the data is genuinely unreachable without it
 * (a client-side-only check would be bypassable with a direct request).
 *
 * The auth cookie carries a hash of the password, not the password itself,
 * so a client can't fabricate a valid cookie without ever having supplied
 * the real password through POST /api/trials/auth.
 *
 * The password comes from TRIALS_PASSWORD (see .env.local/.env.example) —
 * never hardcoded. If it isn't configured, every check below fails closed
 * (nobody is ever authorized) rather than falling back to some guessable
 * default.
 */
export const TRIALS_AUTH_COOKIE = "trials_auth"

function getConfiguredPassword(): string | null {
  const password = process.env.TRIALS_PASSWORD?.trim()
  return password ? password : null
}

export function isCorrectPassword(password: string): boolean {
  const configured = getConfiguredPassword()
  return configured !== null && password === configured
}

/** The cookie value to issue after a correct password, or null if TRIALS_PASSWORD isn't configured. */
export function getAuthToken(): string | null {
  const configured = getConfiguredPassword()
  if (configured === null) return null
  return createHash("sha256").update(configured).digest("hex")
}

/** Parses the Cookie header and checks it carries a valid trials-auth token. */
export function isAuthorized(request: Request): boolean {
  const validToken = getAuthToken()
  if (validToken === null) return false

  const header = request.headers.get("cookie") ?? ""
  for (const part of header.split(";")) {
    const eq = part.indexOf("=")
    if (eq === -1) continue
    const name = part.slice(0, eq).trim()
    const value = part.slice(eq + 1).trim()
    if (name === TRIALS_AUTH_COOKIE) return value === validToken
  }
  return false
}

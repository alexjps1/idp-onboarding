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
 */
const TRIALS_PASSWORD = "idpsose2026"

export const TRIALS_AUTH_COOKIE = "trials_auth"

export const TRIALS_AUTH_TOKEN = createHash("sha256")
  .update(TRIALS_PASSWORD)
  .digest("hex")

export function isCorrectPassword(password: string): boolean {
  return password === TRIALS_PASSWORD
}

/** Parses the Cookie header and checks it carries a valid trials-auth token. */
export function isAuthorized(request: Request): boolean {
  const header = request.headers.get("cookie") ?? ""
  for (const part of header.split(";")) {
    const eq = part.indexOf("=")
    if (eq === -1) continue
    const name = part.slice(0, eq).trim()
    const value = part.slice(eq + 1).trim()
    if (name === TRIALS_AUTH_COOKIE) return value === TRIALS_AUTH_TOKEN
  }
  return false
}

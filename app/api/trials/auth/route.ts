import { NextResponse } from "next/server"

import {
  TRIALS_AUTH_COOKIE,
  TRIALS_AUTH_TOKEN,
  isCorrectPassword,
} from "@/lib/trials-auth"

export const runtime = "nodejs"

/**
 * Verifies the /trials password and, if correct, sets the auth cookie that
 * GET /api/trials requires. The cookie is httpOnly (unreadable/unforgeable
 * from client JS) and secure (HTTPS only, which this app always runs under).
 */
export async function POST(request: Request) {
  const body = (await request.json().catch(() => null)) as {
    password?: string
  } | null

  if (!body?.password || !isCorrectPassword(body.password)) {
    return NextResponse.json(
      { ok: false, error: "Falsches Passwort." },
      { status: 401 }
    )
  }

  const res = NextResponse.json({ ok: true })
  res.cookies.set(TRIALS_AUTH_COOKIE, TRIALS_AUTH_TOKEN, {
    httpOnly: true,
    secure: true,
    sameSite: "strict",
    path: "/",
    maxAge: 60 * 60 * 12, // 12h
  })
  return res
}

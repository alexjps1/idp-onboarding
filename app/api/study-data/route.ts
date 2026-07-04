import { NextResponse } from "next/server"
import { access, mkdir, writeFile } from "node:fs/promises"
import path from "node:path"

import type { StudySession } from "@/lib/study-data"
import { PARTICIPANT_ID_PATTERN } from "@/lib/participant"

// Node runtime: we write the collected study record to the local filesystem.
export const runtime = "nodejs"

const SESSIONS_DIR = path.join(process.cwd(), "data", "sessions")

// Participant ids look like "RAND0042" or a custom "PROBAND1"; the shared
// pattern (uppercase letters, digits, underscore, max 8) also guarantees the id
// can never be used to escape the sessions directory (path traversal).
const PARTICIPANT_ID = PARTICIPANT_ID_PATTERN

/**
 * Existence check used at claim time: the landing page verifies a custom id is
 * free before a run starts, and random-id generation retries on collision. This
 * enforces "no reuse" without touching the per-change POST below, which must
 * keep overwriting a session's own file as the run progresses.
 */
export async function GET(request: Request) {
  const id = new URL(request.url).searchParams.get("id")
  if (!id || !PARTICIPANT_ID.test(id)) {
    return NextResponse.json(
      { error: "Missing or invalid 'id'." },
      { status: 400 }
    )
  }

  try {
    await access(path.join(SESSIONS_DIR, `${id}.json`))
    return NextResponse.json({ exists: true })
  } catch {
    return NextResponse.json({ exists: false })
  }
}

/**
 * Upsert one participant's study record. The client sends the full snapshot on
 * every change, so the file always reflects the latest state — later saves in
 * the same run simply overwrite the earlier file for that id.
 */
export async function POST(request: Request) {
  const session = (await request
    .json()
    .catch(() => null)) as StudySession | null

  const id = session?.participantId
  if (!id || !PARTICIPANT_ID.test(id)) {
    return NextResponse.json(
      { error: "Missing or invalid 'participantId'." },
      { status: 400 }
    )
  }

  const record = { ...session, updatedAt: new Date().toISOString() }

  try {
    await mkdir(SESSIONS_DIR, { recursive: true })
    await writeFile(
      path.join(SESSIONS_DIR, `${id}.json`),
      JSON.stringify(record, null, 2),
      "utf8"
    )
  } catch (err) {
    console.error("Failed to write study session", err)
    return NextResponse.json({ error: "Failed to persist session." }, { status: 500 })
  }

  return NextResponse.json({ ok: true })
}

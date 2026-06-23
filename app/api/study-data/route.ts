import { NextResponse } from "next/server"
import { mkdir, writeFile } from "node:fs/promises"
import path from "node:path"

import type { StudySession } from "@/lib/study-data"

// Node runtime: we write the collected study record to the local filesystem.
export const runtime = "nodejs"

const SESSIONS_DIR = path.join(process.cwd(), "data", "sessions")

// Participant ids look like "PB-LXK3F"; anything else is rejected so the id can
// never be used to escape the sessions directory (path traversal).
const PARTICIPANT_ID = /^[A-Z0-9-]{1,64}$/

/**
 * Upsert one participant's study record. The client sends the full snapshot on
 * every change, so the file always reflects the latest state — re-runs simply
 * overwrite the previous file for that id.
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

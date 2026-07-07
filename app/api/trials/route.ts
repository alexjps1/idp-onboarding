import { NextResponse } from "next/server"
import { readdir, readFile, stat } from "node:fs/promises"
import path from "node:path"

import { isAuthorized } from "@/lib/trials-auth"

export const runtime = "nodejs"
// Prevent Next from caching the response so the viewer always gets fresh data.
export const dynamic = "force-dynamic"

const SESSIONS_DIR = path.join(process.cwd(), "data", "sessions")

/** Safely check whether a path exists. */
async function exists(p: string): Promise<boolean> {
  try {
    await stat(p)
    return true
  } catch {
    return false
  }
}

/**
 * GET /api/trials          → list all participant IDs + last-modified times
 * GET /api/trials?id=X     → return the full JSON for participant X
 */
export async function GET(request: Request) {
  if (!isAuthorized(request)) {
    return NextResponse.json({ error: "Unauthorized" }, { status: 401 })
  }

  const url = new URL(request.url)
  const id = url.searchParams.get("id")

  if (!(await exists(SESSIONS_DIR))) {
    return NextResponse.json(id ? { error: "Not found" } : { trials: [] }, {
      status: id ? 404 : 200,
    })
  }

  // ── Single trial ────────────────────────────────────────────────────
  if (id) {
    // Basic path-traversal guard: strip anything that isn't alphanumeric / underscore.
    const safe = id.replace(/[^A-Za-z0-9_]/g, "")
    const file = path.join(SESSIONS_DIR, `${safe}.json`)
    if (!(await exists(file))) {
      return NextResponse.json({ error: "Not found" }, { status: 404 })
    }
    const raw = await readFile(file, "utf8")
    const data = JSON.parse(raw)
    const { mtimeMs } = await stat(file)
    return NextResponse.json({ id: safe, data, updatedAt: mtimeMs })
  }

  // ── List all trials ─────────────────────────────────────────────────
  const entries = await readdir(SESSIONS_DIR)
  const trials = await Promise.all(
    entries
      .filter((f) => f.endsWith(".json"))
      .map(async (f) => {
        const id = f.replace(/\.json$/, "")
        const { mtimeMs } = await stat(path.join(SESSIONS_DIR, f))
        return { id, updatedAt: mtimeMs }
      })
  )

  // Sort newest first so the most recent trial is at the top.
  trials.sort((a, b) => b.updatedAt - a.updatedAt)

  return NextResponse.json({ trials })
}

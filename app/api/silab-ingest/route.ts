import { NextResponse } from "next/server"
import {
  setPushedState,
  type AdasState,
  type CarState,
} from "@/lib/silab-state"

export const runtime = "nodejs"
export const dynamic = "force-dynamic"

/**
 * Receives the ADAS + car state SilabServer.java pushes every 500ms (see
 * pushState()/makeSimStateMessage() in silab_config/java/SilabServer.java).
 * Runs over plain HTTP on purpose: the JVM bundled with SILAB can't
 * complete a TLS handshake with this server.
 *
 * The shared secret only filters out stray/bot requests hitting a public
 * endpoint - the payload isn't confidential, so a plain string comparison
 * is enough; it must match INGEST_SECRET in SilabServer.java exactly.
 */
export async function POST(req: Request) {
  let body: { secret?: string; adas?: unknown; trf?: unknown }
  try {
    body = await req.json()
  } catch {
    return NextResponse.json(
      { success: false, error: "invalid JSON" },
      { status: 400 }
    )
  }

  if (body.secret !== process.env.SILAB_INGEST_SECRET) {
    return NextResponse.json({ success: false }, { status: 401 })
  }

  if (typeof body.adas !== "object" || body.adas === null) {
    return NextResponse.json(
      { success: false, error: "missing adas" },
      { status: 400 }
    )
  }
  if (typeof body.trf !== "object" || body.trf === null) {
    return NextResponse.json(
      { success: false, error: "missing trf" },
      { status: 400 }
    )
  }

  setPushedState(body.adas as Partial<AdasState>, body.trf as Partial<CarState>)
  return NextResponse.json({ success: true })
}

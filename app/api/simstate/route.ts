import { NextResponse } from "next/server"
import {
  getSilabState,
  getPushedReceivedAt,
  DEFAULT_ADAS,
  DEFAULT_TRF,
} from "@/lib/silab-state"

export const runtime = "nodejs"
// Every poll must hit SILAB live; never serve a cached simulation state.
export const dynamic = "force-dynamic"

/**
 * Reports the current SILAB simulation state - ADAS automation status plus
 * the ego car's speed/position - via whichever channel
 * SILAB_COMMUNICATION_MODE selects ("api": read what SilabServer.java last
 * pushed to /api/silab-ingest, "tcp": poll FS-SCENERY directly). See
 * lib/silab-state.ts for the branching logic.
 *
 * Never throws: any failure (no connection, timeout, stale/missing push
 * data) resolves to default/zeroed state with an `error` field, so the
 * client poll can treat it as "no change".
 *
 * Also always includes `receivedAt` — the server-side time of the most
 * recent /api/silab-ingest push (null in "tcp" mode, or if none yet) — so a
 * client can detect "a new packet just arrived" independent of adas/trf
 * (see use-simulation-start.ts).
 */
export async function GET() {
  const receivedAt = getPushedReceivedAt()
  try {
    const state = await getSilabState()
    return NextResponse.json({ ...state, receivedAt })
  } catch (err) {
    return NextResponse.json({
      adas: DEFAULT_ADAS,
      trf: DEFAULT_TRF,
      receivedAt,
      error: err instanceof Error ? err.message : "unknown error",
    })
  }
}

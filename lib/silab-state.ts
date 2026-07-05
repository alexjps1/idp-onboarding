import net from "node:net"

export type AdasState = {
  active: boolean
  automationActive: number
  automationStandstill: number
  available: boolean
  availability: number
}

export type CarState = {
  speed: number
  acceleration: number
  refPoint: { x: number; y: number; z: number }
  yaw: number
  pitch: number
  roll: number
}

export type SilabState = {
  adas: AdasState
  trf: CarState
}

export const DEFAULT_ADAS: AdasState = {
  active: false,
  automationActive: 0,
  automationStandstill: 0,
  available: false,
  availability: 0,
}

export const DEFAULT_TRF: CarState = {
  speed: 0,
  acceleration: 0,
  refPoint: { x: 0, y: 0, z: 0 },
  yaw: 0,
  pitch: 0,
  roll: 0,
}

const DEFAULT_ADDR = "10.152.238.2:4200"
const ETX = "" // SILAB terminates each TCP response with this byte.
const TCP_TIMEOUT_MS = 1500 // Must stay well under the 2s client poll interval.

// Data pushed by SilabServer.java's pushState() (see /api/silab-ingest),
// held only in memory - this is a single long-running Node process
// (next.config.js output: "standalone"), not a serverless function, so a
// module-level variable is a fine place for this.
const STALE_AFTER_MS = 3000
let pushed: { adas: AdasState; trf: CarState; receivedAt: number } | null = null

export function setPushedState(adas: Partial<AdasState>, trf: Partial<CarState>) {
  pushed = {
    adas: { ...DEFAULT_ADAS, ...adas },
    trf: { ...DEFAULT_TRF, ...trf },
    receivedAt: Date.now(),
  }
}

/**
 * Returns the current SILAB state via whichever channel
 * SILAB_COMMUNICATION_MODE selects:
 *  - "tcp": poll FS-SCENERY directly over its TCP socket (SILAB_ADDR),
 *    sending the "simstate" command (see SilabServer.java's ClientHandler).
 *  - "api" (default): return whatever SilabServer.java last pushed to
 *    /api/silab-ingest, as long as it's not older than STALE_AFTER_MS.
 *
 * Throws on any failure (no connection, timeout, no data yet, stale data) -
 * callers should catch this and fall back to default/zeroed state.
 */
export async function getSilabState(): Promise<SilabState> {
  if (process.env.SILAB_COMMUNICATION_MODE === "tcp") {
    return queryTcp()
  }

  if (!pushed) {
    throw new Error("no data received yet from SILAB")
  }
  if (Date.now() - pushed.receivedAt > STALE_AFTER_MS) {
    throw new Error(`SILAB data is stale (older than ${STALE_AFTER_MS}ms)`)
  }
  return { adas: pushed.adas, trf: pushed.trf }
}

function queryTcp(): Promise<SilabState> {
  const addr = process.env.SILAB_ADDR ?? DEFAULT_ADDR
  const [host, portStr] = addr.split(":")
  const port = Number(portStr)

  return new Promise((resolve, reject) => {
    const socket = net.createConnection({ host, port })
    socket.setTimeout(TCP_TIMEOUT_MS)

    let buf = ""
    let settled = false
    const finish = (run: () => void) => {
      if (settled) return
      settled = true
      socket.destroy()
      run()
    }

    socket.on("connect", () => socket.write("simstate\n"))
    socket.on("data", (chunk) => {
      buf += chunk.toString("utf8")
      const etx = buf.indexOf(ETX)
      if (etx === -1) return // wait for the full, terminated message
      try {
        const msg = JSON.parse(buf.slice(0, etx)) as {
          adas?: Partial<AdasState>
          trf?: Partial<CarState>
        }
        finish(() =>
          resolve({
            adas: { ...DEFAULT_ADAS, ...msg.adas },
            trf: { ...DEFAULT_TRF, ...msg.trf },
          })
        )
      } catch {
        finish(() => reject(new Error("invalid JSON from SILAB")))
      }
    })
    socket.on("timeout", () => finish(() => reject(new Error("SILAB timeout"))))
    socket.on("error", (e) => finish(() => reject(e)))
    socket.on("close", () =>
      finish(() => reject(new Error("SILAB closed connection without a response")))
    )
  })
}

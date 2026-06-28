import { NextResponse } from "next/server"
import net from "node:net"

export const runtime = "nodejs"
// Every poll must hit SILAB live; never serve a cached automation state.
export const dynamic = "force-dynamic"

const DEFAULT_ADDR = "10.152.238.2:4200"
const ETX = "" // SILAB terminates each response with this byte.
const TIMEOUT_MS = 1500 // Must stay well under the 2s client poll interval.

/**
 * Reports the current driving-automation (ADAS) state from the SILAB TCP
 * server. Opens a short-lived connection, sends "automation", and reads the
 * ETX-terminated JSON response (see SilabServer.java makeAutomationMessage).
 *
 * Never throws: any connection/parse failure resolves to { active: false } with
 * an `error` field, so the 2-second client poll can treat it as "no change".
 */
export async function GET() {
  const addr = process.env.SILAB_ADDR ?? DEFAULT_ADDR
  const [host, portStr] = addr.split(":")
  const port = Number(portStr)

  try {
    const active = await queryAutomation(host, port)
    return NextResponse.json({ active })
  } catch (err) {
    return NextResponse.json({
      active: false,
      error: err instanceof Error ? err.message : "unknown error",
    })
  }
}

function queryAutomation(host: string, port: number): Promise<boolean> {
  return new Promise((resolve, reject) => {
    const socket = net.createConnection({ host, port })
    socket.setTimeout(TIMEOUT_MS)

    let buf = ""
    let settled = false
    const finish = (run: () => void) => {
      if (settled) return
      settled = true
      socket.destroy()
      run()
    }

    socket.on("connect", () => socket.write("automation\n"))
    socket.on("data", (chunk) => {
      buf += chunk.toString("utf8")
      const etx = buf.indexOf(ETX)
      if (etx === -1) return // wait for the full, terminated message
      try {
        const msg = JSON.parse(buf.slice(0, etx)) as {
          data?: { active?: boolean }
        }
        finish(() => resolve(Boolean(msg.data?.active)))
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

/**
 * Fixed rectangular zones on the SILAB driving track, used to trigger
 * proactive tutor moments based on the ego car's refPoint (see
 * components/study/use-zone-triggers.ts).
 */

export type Zone = { x1: number; y1: number; x2: number; y2: number }

/** Axis-aligned point-in-rectangle test; corner order in a Zone doesn't matter. */
export function pointInZone(x: number, y: number, zone: Zone): boolean {
  const minX = Math.min(zone.x1, zone.x2)
  const maxX = Math.max(zone.x1, zone.x2)
  const minY = Math.min(zone.y1, zone.y2)
  const maxY = Math.max(zone.y1, zone.y2)
  return x >= minX && x <= maxX && y >= minY && y <= maxY
}

/**
 * "Stelle 1"–"Stelle 6" — entering one of these with ADAS off nudges the
 * driver to turn it on (checked once, at first entry, per zone).
 */
export const ADAS_NUDGE_ZONES: Zone[] = [
  { x1: 500, y1: -30, x2: 800, y2: 30 },
  { x1: 2200, y1: -700, x2: 2400, y2: -760 },
  { x1: 2700, y1: -1100, x2: 2900, y2: -1400 },
  { x1: 3500, y1: -3100, x2: 3200, y2: -3400 },
  { x1: 1700, y1: -4400, x2: 1400, y2: -4600 },
  { x1: 2000, y1: -2100, x2: 2300, y2: -2200 },
]

/** Shortly before the parked DHL van — snapshot whether ADAS was on. */
export const SYSTEM_LIMIT_ZONE_BEFORE: Zone = {
  x1: 3100,
  y1: -3800,
  x2: 2800,
  y2: -4100,
}

/** Shortly after the DHL van — explain the takeover, if ADAS was on before. */
export const SYSTEM_LIMIT_ZONE_AFTER: Zone = {
  x1: 3000,
  y1: -4000,
  x2: 2700,
  y2: -4300,
}

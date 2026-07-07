"use client"

import * as React from "react"
import { FileJson2, Loader2, RefreshCw, User } from "lucide-react"

import { cn } from "@/lib/utils"
import { withBasePath } from "@/lib/base-path"
import { ScrollArea } from "@/components/ui/scroll-area"
import { Badge } from "@/components/ui/badge"
import { Button } from "@/components/ui/button"
import {
  Card,
  CardContent,
  CardDescription,
  CardFooter,
  CardHeader,
  CardTitle,
} from "@/components/ui/card"
import { Input } from "@/components/ui/input"
import { Label } from "@/components/ui/label"

/** How often (ms) the viewer polls for data changes. */
const POLL_INTERVAL = 5_000

type TrialEntry = { id: string; updatedAt: number }

// ── Data-fetching hooks ───────────────────────────────────────────────────────

/** Minimal SWR-style hook: fetches on mount, exposes refetch, tracks loading. */
function useTrials() {
  const [trials, setTrials] = React.useState<TrialEntry[]>([])
  const [loading, setLoading] = React.useState(true)
  const [lastRefresh, setLastRefresh] = React.useState<Date | null>(null)
  // Set on a 401 from the (password-gated) API — the viewer must render
  // nothing but the password prompt while this is true.
  const [unauthorized, setUnauthorized] = React.useState(false)

  const refetch = React.useCallback(async () => {
    try {
      const res = await fetch(withBasePath("/api/trials"))
      if (res.status === 401) {
        setUnauthorized(true)
        return
      }
      if (!res.ok) return
      setUnauthorized(false)
      const json = (await res.json()) as { trials: TrialEntry[] }
      setTrials(json.trials)
      setLastRefresh(new Date())
    } catch {
      // Ignore.
    } finally {
      setLoading(false)
    }
  }, [])

  return { trials, loading, lastRefresh, unauthorized, refetch } as const
}

function useTrialData() {
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  const [data, setData] = React.useState<any>(null)
  const [loading, setLoading] = React.useState(false)
  const timestampRef = React.useRef<number>(0)

  const refetch = React.useCallback(async (id: string) => {
    try {
      setLoading(true)
      const res = await fetch(withBasePath(`/api/trials?id=${id}`))
      if (!res.ok) {
        setData(null)
        return
      }
      // eslint-disable-next-line @typescript-eslint/no-explicit-any
      const json = (await res.json()) as { id: string; data: any; updatedAt: number }
      timestampRef.current = json.updatedAt
      setData(json.data)
    } catch {
      setData(null)
    } finally {
      setLoading(false)
    }
  }, [])

  /** Silent poll — only updates state if the file changed. */
  const poll = React.useCallback(async (id: string) => {
    try {
      const res = await fetch(withBasePath(`/api/trials?id=${id}`))
      if (!res.ok) return
      // eslint-disable-next-line @typescript-eslint/no-explicit-any
      const json = (await res.json()) as { id: string; data: any; updatedAt: number }
      if (json.updatedAt !== timestampRef.current) {
        timestampRef.current = json.updatedAt
        setData(json.data)
      }
    } catch {
      // Ignore.
    }
  }, [])

  const clear = React.useCallback(() => {
    setData(null)
    timestampRef.current = 0
  }, [])

  return { data, loading, refetch, poll, clear } as const
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Password gate — shown instead of the viewer until POST /api/trials/auth
// succeeds. GET /api/trials itself enforces this server-side, so this is
// the UI for that, not the actual protection.
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

function PasswordGate({ onSuccess }: { onSuccess: () => void }) {
  const [password, setPassword] = React.useState("")
  const [error, setError] = React.useState<string | null>(null)
  const [submitting, setSubmitting] = React.useState(false)

  return (
    <div className="flex h-screen w-screen items-center justify-center bg-background p-6">
      <Card className="w-full max-w-sm">
        <form
          onSubmit={(e) => {
            e.preventDefault()
            setSubmitting(true)
            setError(null)
            void (async () => {
              try {
                const res = await fetch(withBasePath("/api/trials/auth"), {
                  method: "POST",
                  headers: { "Content-Type": "application/json" },
                  body: JSON.stringify({ password }),
                })
                if (res.ok) {
                  onSuccess()
                } else {
                  setError("Falsches Passwort.")
                }
              } catch {
                setError("Verbindungsfehler. Bitte erneut versuchen.")
              } finally {
                setSubmitting(false)
              }
            })()
          }}
        >
          <CardHeader>
            <CardTitle>Trial Viewer</CardTitle>
            <CardDescription>
              Bitte Passwort eingeben, um die Probandendaten einzusehen.
            </CardDescription>
          </CardHeader>
          <CardContent className="flex flex-col gap-2">
            <Label htmlFor="trials-password">Passwort</Label>
            <Input
              id="trials-password"
              type="password"
              autoFocus
              autoComplete="off"
              value={password}
              onChange={(e) => {
                setPassword(e.target.value)
                setError(null)
              }}
            />
            {error ? <p className="text-sm text-destructive">{error}</p> : null}
          </CardContent>
          <CardFooter>
            <Button
              type="submit"
              disabled={submitting || !password}
              className="w-full"
            >
              {submitting ? "Prüfe…" : "Anmelden"}
            </Button>
          </CardFooter>
        </form>
      </Card>
    </div>
  )
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Page
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

export default function TrialsPage() {
  const {
    trials,
    loading,
    lastRefresh,
    unauthorized,
    refetch: refetchTrials,
  } = useTrials()
  const {
    data,
    loading: dataLoading,
    refetch: refetchTrial,
    poll: pollTrial,
    clear: clearData,
  } = useTrialData()
  const [selectedId, setSelectedId] = React.useState<string | null>(null)

  // ── Initial load (ref == null pattern satisfies react-hooks/refs) ──
  const didInit = React.useRef<boolean | null>(null)
  if (didInit.current == null) {
    didInit.current = true
    void refetchTrials()
  }

  // ── Selection handler (event-driven, not effect-driven) ─────────────
  function handleSelect(id: string) {
    setSelectedId(id)
    void refetchTrial(id)
  }

  // ── Polling (interval — allowed to call setState in the callback) ───
  React.useEffect(() => {
    const interval = setInterval(() => {
      void refetchTrials()
      if (selectedId) void pollTrial(selectedId)
    }, POLL_INTERVAL)
    return () => clearInterval(interval)
  }, [selectedId, refetchTrials, pollTrial])

  // Derive: if the selected trial disappeared from the list, deselect.
  const selectionValid =
    !selectedId || trials.length === 0 || trials.some((t) => t.id === selectedId)
  const effectiveId = selectionValid ? selectedId : null

  // Clear stale data when selection becomes invalid.
  if (!selectionValid && selectedId) {
    // This is a render-time state correction (synchronous, no effect needed).
    setSelectedId(null)
    clearData()
  }

  // Nothing below this point ever renders — no sidebar, no data, not even an
  // empty-state — until the password is verified server-side. GET
  // /api/trials itself refuses to return data without it; this is just the
  // UI for that gate, not a substitute for it.
  if (loading) {
    return (
      <div className="flex h-screen w-screen items-center justify-center bg-background">
        <Loader2 className="size-6 animate-spin text-muted-foreground" />
      </div>
    )
  }
  if (unauthorized) {
    return <PasswordGate onSuccess={() => void refetchTrials()} />
  }

  return (
    <div className="flex h-screen w-screen flex-col overflow-hidden bg-background text-foreground">
      {/* Top bar */}
      <header className="flex h-14 shrink-0 items-center justify-between border-b bg-card px-6">
        <div className="flex items-center gap-3">
          <FileJson2 className="size-5 text-primary" />
          <h1 className="text-base font-semibold tracking-tight">
            Trial Viewer
          </h1>
          <Badge variant="outline" className="text-[11px]">
            {trials.length} Probanden
          </Badge>
        </div>
        <div className="flex items-center gap-3">
          {lastRefresh ? (
            <span className="text-[11px] text-muted-foreground">
              Aktualisiert{" "}
              {lastRefresh.toLocaleTimeString("de-DE", {
                hour: "2-digit",
                minute: "2-digit",
                second: "2-digit",
              })}
            </span>
          ) : null}
          <button
            type="button"
            onClick={() => {
              void refetchTrials()
              if (effectiveId) void refetchTrial(effectiveId)
            }}
            className="flex size-8 items-center justify-center rounded-lg text-muted-foreground transition-colors hover:bg-muted hover:text-foreground"
            title="Jetzt aktualisieren"
          >
            <RefreshCw className="size-4" />
          </button>
        </div>
      </header>

      <div className="flex min-h-0 flex-1">
        {/* ── Sidebar ──────────────────────────────────────────────── */}
        <aside className="flex w-72 shrink-0 flex-col border-r bg-card">
          <div className="px-4 pt-4 pb-2">
            <p className="text-[11px] font-medium uppercase tracking-wider text-muted-foreground">
              Probanden
            </p>
          </div>
          <ScrollArea className="flex-1 overflow-hidden">
            <div className="space-y-0.5 px-2 pb-4">
              {loading ? (
                <div className="flex items-center justify-center py-12">
                  <Loader2 className="size-5 animate-spin text-muted-foreground" />
                </div>
              ) : trials.length === 0 ? (
                <p className="px-2 py-8 text-center text-sm text-muted-foreground">
                  Noch keine Daten vorhanden.
                </p>
              ) : (
                trials.map((trial) => (
                  <button
                    key={trial.id}
                    type="button"
                    onClick={() => handleSelect(trial.id)}
                    className={cn(
                      "flex w-full items-center gap-3 rounded-lg px-3 py-2.5 text-left text-sm transition-colors",
                      trial.id === effectiveId
                        ? "bg-primary text-primary-foreground"
                        : "text-foreground hover:bg-muted"
                    )}
                  >
                    <User className="size-4 shrink-0 opacity-60" />
                    <div className="min-w-0 flex-1">
                      <p className="truncate font-mono text-[13px] font-medium">
                        {trial.id}
                      </p>
                      <p
                        className={cn(
                          "text-[11px]",
                          trial.id === effectiveId
                            ? "text-primary-foreground/70"
                            : "text-muted-foreground"
                        )}
                      >
                        {new Date(trial.updatedAt).toLocaleString("de-DE", {
                          day: "2-digit",
                          month: "2-digit",
                          hour: "2-digit",
                          minute: "2-digit",
                        })}
                      </p>
                    </div>
                  </button>
                ))
              )}
            </div>
          </ScrollArea>
        </aside>

        {/* ── Content ──────────────────────────────────────────────── */}
        <main className="flex min-w-0 flex-1 flex-col">
          {effectiveId ? (
            <>
              <div className="flex h-12 shrink-0 items-center gap-3 border-b px-6">
                <h2 className="font-mono text-sm font-semibold">
                  {effectiveId}
                </h2>
                <span className="text-[11px] text-muted-foreground">
                  {effectiveId}.json
                </span>
                {dataLoading ? (
                  <Loader2 className="ml-auto size-3.5 animate-spin text-muted-foreground" />
                ) : null}
              </div>
              <ScrollArea className="flex-1 overflow-hidden">
                <div className="p-6">
                  {data != null ? (
                    <JsonNode value={data} depth={0} />
                  ) : dataLoading ? (
                    <div className="flex items-center justify-center py-20">
                      <Loader2 className="size-6 animate-spin text-muted-foreground" />
                    </div>
                  ) : (
                    <p className="text-sm text-muted-foreground">
                      Datei konnte nicht geladen werden.
                    </p>
                  )}
                </div>
              </ScrollArea>
            </>
          ) : (
            <div className="flex flex-1 flex-col items-center justify-center gap-4 text-center">
              <div className="flex size-16 items-center justify-center rounded-2xl bg-muted">
                <FileJson2 className="size-7 text-muted-foreground" />
              </div>
              <div className="space-y-1">
                <p className="text-sm font-medium text-foreground">
                  Kein Proband ausgewählt
                </p>
                <p className="text-[13px] text-muted-foreground">
                  Wählen Sie links einen Probanden aus, um dessen Daten
                  einzusehen.
                </p>
              </div>
            </div>
          )}
        </main>
      </div>
    </div>
  )
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Generic, recursive JSON renderer
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

// eslint-disable-next-line @typescript-eslint/no-explicit-any
function JsonNode({ value, depth }: { value: any; depth: number }) {
  if (value === null) return <span className="text-muted-foreground">null</span>

  if (typeof value === "boolean") {
    return (
      <span className={value ? "text-emerald-600" : "text-rose-500"}>
        {String(value)}
      </span>
    )
  }

  if (typeof value === "number") {
    return <span className="text-sky-600 dark:text-sky-400">{value}</span>
  }

  if (typeof value === "string") {
    // Long strings get a softer treatment.
    if (value.length > 120) {
      return (
        <span className="text-foreground/80">
          &quot;<span className="break-words">{value}</span>&quot;
        </span>
      )
    }
    return (
      <span className="text-amber-700 dark:text-amber-400">
        &quot;{value}&quot;
      </span>
    )
  }

  if (Array.isArray(value)) {
    return <JsonArray items={value} depth={depth} />
  }

  if (typeof value === "object") {
    return <JsonObject obj={value} depth={depth} />
  }

  return <span>{String(value)}</span>
}

function JsonObject({
  obj,
  depth,
}: {
  obj: Record<string, unknown>
  depth: number
}) {
  const entries = Object.entries(obj)
  const [collapsed, setCollapsed] = React.useState(depth >= 3)

  if (entries.length === 0) {
    return <span className="text-muted-foreground">{"{}"}</span>
  }

  return (
    <div>
      <button
        type="button"
        onClick={() => setCollapsed(!collapsed)}
        className="inline-flex items-center gap-1 rounded px-1 py-0.5 text-[11px] font-medium text-muted-foreground transition-colors hover:bg-muted hover:text-foreground"
      >
        <span className="inline-block w-3 text-center">
          {collapsed ? "▸" : "▾"}
        </span>
        <span className="font-mono">{"{"}</span>
        {collapsed ? (
          <span>
            {entries.length} {entries.length === 1 ? "Feld" : "Felder"}
          </span>
        ) : null}
        {collapsed ? <span className="font-mono">{"}"}</span> : null}
      </button>

      {!collapsed ? (
        <div className="ml-4 border-l border-border/60 pl-4">
          {entries.map(([key, val], i) => (
            <div
              key={key}
              className={cn("py-1", i < entries.length - 1 && "border-b border-border/30")}
            >
              <span className="mr-2 font-mono text-[13px] font-semibold text-foreground/90">
                {key}
              </span>
              <span className="mr-2 text-muted-foreground">:</span>
              <JsonNode value={val} depth={depth + 1} />
            </div>
          ))}
          <span className="text-[11px] font-mono text-muted-foreground">
            {"}"}
          </span>
        </div>
      ) : null}
    </div>
  )
}

function JsonArray({ items, depth }: { items: unknown[]; depth: number }) {
  const [collapsed, setCollapsed] = React.useState(
    depth >= 3 && items.length > 3
  )

  if (items.length === 0) {
    return <span className="text-muted-foreground">{"[]"}</span>
  }

  // Compact rendering for arrays of primitives.
  const allPrimitive = items.every(
    (v) => v === null || typeof v !== "object"
  )
  if (allPrimitive && items.length <= 10) {
    return (
      <span className="font-mono text-[13px]">
        {"["}
        {items.map((item, i) => (
          <React.Fragment key={i}>
            {i > 0 ? <span className="text-muted-foreground">, </span> : null}
            <JsonNode value={item} depth={depth + 1} />
          </React.Fragment>
        ))}
        {"]"}
      </span>
    )
  }

  return (
    <div>
      <button
        type="button"
        onClick={() => setCollapsed(!collapsed)}
        className="inline-flex items-center gap-1 rounded px-1 py-0.5 text-[11px] font-medium text-muted-foreground transition-colors hover:bg-muted hover:text-foreground"
      >
        <span className="inline-block w-3 text-center">
          {collapsed ? "▸" : "▾"}
        </span>
        <span className="font-mono">{"["}</span>
        {collapsed ? (
          <span>
            {items.length} {items.length === 1 ? "Element" : "Elemente"}
          </span>
        ) : null}
        {collapsed ? <span className="font-mono">{"]"}</span> : null}
      </button>

      {!collapsed ? (
        <div className="ml-4 border-l border-border/60 pl-4">
          {items.map((item, i) => (
            <div
              key={i}
              className={cn("py-1", i < items.length - 1 && "border-b border-border/30")}
            >
              <span className="mr-2 font-mono text-[11px] text-muted-foreground">
                {i}
              </span>
              <JsonNode value={item} depth={depth + 1} />
            </div>
          ))}
          <span className="text-[11px] font-mono text-muted-foreground">
            {"]"}
          </span>
        </div>
      ) : null}
    </div>
  )
}

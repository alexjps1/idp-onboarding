import * as React from "react"
import { BookOpen, Car, TriangleAlert } from "lucide-react"

import { getStepProgress, getAdjacentSteps } from "@/lib/study-steps"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"

type Module = {
  title: string
  body: React.ReactNode
  /** Marks the safety chapter so it is visually emphasised. */
  warning?: boolean
}

const MODULES: Module[] = [
  {
    title: "Aktivierung",
    body: (
      <>
        <p>
          Der Status der Automation wird durch das Automationssymbol im Display
          angezeigt. Erscheint das Symbol grau, ist das teilautomatisierte
          Fahren <strong>nicht</strong> verfügbar.
        </p>
        <p>
          Wenn das Automationssymbol weiß im Display aufleuchtet, ist das
          teilautomatisierte Fahren verfügbar.
        </p>
        <p>
          Bei Bedingungen, wie zum Beispiel schlechtem Wetter, kann es unter
          Umständen nicht verfügbar sein.
        </p>
        <p>
          Drücken Sie die „Aktivierungstaste“, um das teilautomatisierte Fahren
          zu aktivieren.
        </p>
        <p>
          Bei erfolgreicher Aktivierung leuchtet das Automationssymbol grün im
          Display auf. Zudem leuchten die Lenkradlichter grün.
        </p>
        <p>
          Es sind nun <strong>alle</strong> Fahrerassistenzsysteme aktiv und das
          Fahrzeug fährt <strong>teilautomatisiert</strong>. Richten Sie Ihren
          Blick weiterhin auf die Straße und nehmen Sie die Füße von den Pedalen.
          Ihre Hände können Sie während der automatisierten Fahrt vom Lenkrad
          nehmen oder am Lenkrad belassen, ohne zu lenken.
        </p>
      </>
    ),
  },
  {
    title: "Verkehrszeichenassistent",
    body: (
      <>
        <p>Das Fahrzeug erkennt Tempolimits.</p>
        <p>
          Das erkannte Tempolimit wird im Display angezeigt. Bei einem neuen
          Tempolimit wird die erkannte Geschwindigkeit automatisch übernommen.
        </p>
        <p>
          Drücken Sie den Hebel nach oben oder unten, um die Geschwindigkeit
          individuell zu erhöhen (oben) oder zu verringern (unten).
        </p>
        <p>
          Ihre individuell eingestellte Geschwindigkeit wird im Display
          angezeigt.
        </p>
      </>
    ),
  },
  {
    title: "Abstandsregeltempomat",
    body: (
      <>
        <p>
          Das Fahrzeug hält den Abstand zum Vorderfahrzeug automatisch. Es bremst
          oder beschleunigt, falls nötig.
        </p>
        <p>
          Drücken Sie die Abstandstasten, um den Abstand zum Vorderfahrzeug
          individuell zu erhöhen (rechts) oder zu verringern (links).
        </p>
        <p>
          Der individuell eingestellte Abstand wird im Display symbolisch
          angezeigt. Die Striche vor dem Fahrzeug visualisieren den Abstand – je
          mehr Striche, desto größer der eingestellte Abstand.
        </p>
      </>
    ),
  },
  {
    title: "Ampelerkennung",
    body: (
      <>
        <p>
          Das Fahrzeug erkennt Ampeln und bremst bei roten Ampeln automatisch bis
          zum Stillstand ab.
        </p>
        <p>
          Im Stillstand müssen Sie übernehmen und manuell anfahren. Das
          teilautomatisierte Fahren kann wieder aktiviert werden, sobald das
          Symbol weiß im Display aufleuchtet.
        </p>
      </>
    ),
  },
  {
    title: "Spurführungsassistent",
    body: (
      <>
        <p>
          Das Fahrzeug hält automatisch die Spur, wenn das teilautomatisierte
          Fahren aktiv ist.
        </p>
        <p>
          Automatische Spurwechsel sind nicht möglich. Deaktivieren Sie das
          teilautomatisierte Fahren durch Drücken der Aktivierungstaste, um einen
          Spurwechsel manuell auszuführen.
        </p>
      </>
    ),
  },
  {
    title: "Notbremsassistent",
    body: (
      <>
        <p>
          Das Fahrzeug erkennt Hindernisse. Bevor es zum Zusammenstoß mit einem
          Hindernis, einer Person oder einem weiteren Fahrzeug kommt, bremst das
          Fahrzeug bis zum Stillstand ab.
        </p>
        <p>
          Im Stillstand müssen Sie übernehmen und manuell anfahren. Das
          teilautomatisierte Fahren kann wieder aktiviert werden, sobald das
          Symbol weiß im Display aufleuchtet.
        </p>
      </>
    ),
  },
  {
    title: "Deaktivierung",
    body: (
      <>
        <p>
          Drücken Sie die Aktivierungstaste erneut, um das teilautomatisierte
          Fahren zu beenden.
        </p>
        <p>
          Es wird auch beendet, wenn Sie manuell lenken oder das Bremspedal
          drücken.
        </p>
        <p>
          Bei erfolgreicher Deaktivierung erlöschen die Lenkradlichter und das
          Automationssymbol im Display erscheint wieder weiß.
        </p>
      </>
    ),
  },
  {
    title: "Risiken und Verantwortung",
    warning: true,
    body: (
      <>
        <p>
          Das teilautomatisierte Fahren entbindet Sie nicht von der
          Verantwortung als Fahrer*in. Es funktioniert in den meisten Fällen sehr
          gut, kann jedoch nicht alle Fahrsituationen abdecken. Kommt das System
          an seine Grenzen, warnt es Sie und fordert zur Übernahme auf.
        </p>
        <p>
          Es kann jedoch vorkommen, dass das Fahrzeug Fehler macht, ohne vorher
          zu warnen. Achten Sie deshalb immer auf den Verkehr und die Umgebung.
          Sie müssen jederzeit sofort eingreifen können. Wir zeigen Ihnen hier
          einige Beispiele möglicher Fehler:
        </p>
        <ul className="list-disc space-y-1 pl-5">
          <li>Das Fahrzeug erkennt einen Kreisverkehr nicht und lenkt falsch.</li>
          <li>Das Fahrzeug erkennt die Fahrspur nicht wegen einer Baustelle.</li>
          <li>Das Fahrzeug bremst bei einer roten Ampel nicht ab.</li>
          <li>
            Das Fahrzeug erkennt beim Spurwechsel umliegende Fahrzeuge nicht.
          </li>
        </ul>
      </>
    ),
  },
]

export default function GuidePage() {
  const { previous, next } = getAdjacentSteps("guide")

  return (
    <StudyShell
      progress={getStepProgress("guide")}
      mainClassName="justify-start"
      footer={
        <StudyFooter
          prevHref={previous?.path}
          nextHref={next?.path}
          nextLabel="Zur Fahrt wechseln"
          nextIcon={<Car />}
        />
      }
    >
      <div className="mx-auto flex h-full w-full max-w-3xl flex-col">
        {/* Header */}
        <header className="mb-4 flex items-center gap-3">
          <span className="flex size-10 shrink-0 items-center justify-center rounded-xl bg-primary/10 text-primary">
            <BookOpen className="size-5" />
          </span>
          <div>
            <h1 className="text-2xl font-bold tracking-tight text-on-surface">
              Modulhandbuch
            </h1>
            <p className="text-sm text-on-surface-variant">
              Teilautomatisiertes Fahren – Funktionen der Assistenzsysteme
            </p>
          </div>
        </header>

        {/* Scrollable handbook */}
        <div className="study-scrollbar min-h-0 flex-1 space-y-4 overflow-y-auto pr-2">
          {MODULES.map((module, index) => (
            <section
              key={module.title}
              className={
                module.warning
                  ? "rounded-xl border border-error/40 bg-error/5 p-5"
                  : "rounded-xl border border-outline-variant bg-surface-container-low p-5"
              }
            >
              <div className="mb-3 flex items-center gap-3">
                <span
                  className={
                    module.warning
                      ? "flex size-7 shrink-0 items-center justify-center rounded-lg bg-error/10 text-error"
                      : "flex size-7 shrink-0 items-center justify-center rounded-lg bg-primary/10 data-mono text-[12px] text-primary"
                  }
                >
                  {module.warning ? (
                    <TriangleAlert className="size-4" />
                  ) : (
                    String(index + 1).padStart(2, "0")
                  )}
                </span>
                <h2 className="text-lg font-semibold text-on-surface">
                  {module.title}
                </h2>
              </div>
              <div className="space-y-2 text-sm leading-relaxed text-on-surface-variant [&_strong]:font-semibold [&_strong]:text-on-surface">
                {module.body}
              </div>
            </section>
          ))}
        </div>
      </div>
    </StudyShell>
  )
}

/**
 * Plain-text baseline content for the onboarding guide. This is the source the
 * LLM adapts (shortens/omits when the participant already knows a system,
 * expands and simplifies when they don't) and also the fallback rendered when
 * no OpenAI key is configured. Kept as plain strings so it can be sent to the
 * model and re-rendered without parsing JSX.
 *
 * `system` links a module to a rated self-assessment system (see
 * ASSISTANCE_SYSTEMS) so the per-system knowledge level can drive adaptation.
 * Modules without a `system` are general; `alwaysKeep` modules (e.g. safety)
 * are never shortened or omitted.
 */
export type OnboardingModule = {
  id: string
  title: string
  paragraphs: string[]
  /** Extra bullet points (e.g. failure examples) kept alongside paragraphs. */
  bullets?: string[]
  /** Name of the matching ASSISTANCE_SYSTEMS entry, if any. */
  system?: string
  warning?: boolean
  /**
   * Rendered verbatim and never sent to the LLM. Used for the fixed intro/outro
   * (Aktivierung, Deaktivierung) and safety content (Risiken). Only the
   * Fahrzeugassistenzsysteme in between are adapted to the participant's
   * Fragebogen ratings.
   */
  alwaysKeep?: boolean
}

export const ONBOARDING_MODULES: OnboardingModule[] = [
  {
    id: "aktivierung",
    title: "Aktivierung",
    alwaysKeep: true,
    paragraphs: [
      "Der Status der Automation wird durch das Automationssymbol im Display angezeigt. Erscheint das Symbol grau, ist das teilautomatisierte Fahren nicht verfügbar.",
      "Wenn das Automationssymbol weiß im Display aufleuchtet, ist das teilautomatisierte Fahren verfügbar.",
      "Bei Bedingungen, wie zum Beispiel schlechtem Wetter, kann es unter Umständen nicht verfügbar sein.",
      "Drücken Sie die „Aktivierungstaste“, um das teilautomatisierte Fahren zu aktivieren.",
      "Bei erfolgreicher Aktivierung leuchtet das Automationssymbol grün im Display auf. Zudem leuchten die Lenkradlichter grün.",
      "Es sind nun alle Fahrerassistenzsysteme aktiv und das Fahrzeug fährt teilautomatisiert. Richten Sie Ihren Blick weiterhin auf die Straße und nehmen Sie die Füße von den Pedalen. Ihre Hände können Sie während der automatisierten Fahrt vom Lenkrad nehmen oder am Lenkrad belassen, ohne zu lenken.",
    ],
  },
  {
    id: "verkehrszeichenassistent",
    title: "Verkehrszeichenassistent",
    system: "Verkehrszeichenassistent",
    paragraphs: [
      "Das Fahrzeug erkennt Tempolimits.",
      "Das erkannte Tempolimit wird im Display angezeigt. Bei einem neuen Tempolimit wird die erkannte Geschwindigkeit automatisch übernommen.",
      "Drücken Sie den Hebel nach oben oder unten, um die Geschwindigkeit individuell zu erhöhen (oben) oder zu verringern (unten).",
      "Ihre individuell eingestellte Geschwindigkeit wird im Display angezeigt.",
    ],
  },
  {
    id: "abstandsregeltempomat",
    title: "Abstandsregeltempomat",
    system: "Abstandsregeltempomat",
    paragraphs: [
      "Das Fahrzeug hält den Abstand zum Vorderfahrzeug automatisch. Es bremst oder beschleunigt, falls nötig.",
      "Drücken Sie die Abstandstasten, um den Abstand zum Vorderfahrzeug individuell zu erhöhen (rechts) oder zu verringern (links).",
      "Der individuell eingestellte Abstand wird im Display symbolisch angezeigt. Die Striche vor dem Fahrzeug visualisieren den Abstand – je mehr Striche, desto größer der eingestellte Abstand.",
    ],
  },
  {
    id: "ampelerkennung",
    title: "Ampelerkennung",
    system: "Ampelerkennung",
    paragraphs: [
      "Das Fahrzeug erkennt Ampeln und bremst bei roten Ampeln automatisch bis zum Stillstand ab.",
      "Im Stillstand müssen Sie übernehmen und manuell anfahren. Das teilautomatisierte Fahren kann wieder aktiviert werden, sobald das Symbol weiß im Display aufleuchtet.",
    ],
  },
  {
    id: "spurfuehrungsassistent",
    title: "Spurführungsassistent",
    system: "Spurführungsassistent",
    paragraphs: [
      "Das Fahrzeug hält automatisch die Spur, wenn das teilautomatisierte Fahren aktiv ist.",
      "Automatische Spurwechsel sind nicht möglich. Deaktivieren Sie das teilautomatisierte Fahren durch Drücken der Aktivierungstaste, um einen Spurwechsel manuell auszuführen.",
    ],
  },
  {
    id: "notbremsassistent",
    title: "Notbremsassistent",
    system: "Notbremsassistent",
    paragraphs: [
      "Das Fahrzeug erkennt Hindernisse. Bevor es zum Zusammenstoß mit einem Hindernis, einer Person oder einem weiteren Fahrzeug kommt, bremst das Fahrzeug bis zum Stillstand ab.",
      "Im Stillstand müssen Sie übernehmen und manuell anfahren. Das teilautomatisierte Fahren kann wieder aktiviert werden, sobald das Symbol weiß im Display aufleuchtet.",
    ],
  },
  {
    id: "deaktivierung",
    title: "Deaktivierung",
    alwaysKeep: true,
    paragraphs: [
      "Drücken Sie die Aktivierungstaste erneut, um das teilautomatisierte Fahren zu beenden.",
      "Es wird auch beendet, wenn Sie manuell lenken oder das Bremspedal drücken.",
      "Bei erfolgreicher Deaktivierung erlöschen die Lenkradlichter und das Automationssymbol im Display erscheint wieder weiß.",
    ],
  },
  {
    id: "risiken",
    title: "Risiken und Verantwortung",
    warning: true,
    alwaysKeep: true,
    paragraphs: [
      "Das teilautomatisierte Fahren entbindet Sie nicht von der Verantwortung als Fahrer*in. Es funktioniert in den meisten Fällen sehr gut, kann jedoch nicht alle Fahrsituationen abdecken. Kommt das System an seine Grenzen, warnt es Sie und fordert zur Übernahme auf.",
      "Es kann jedoch vorkommen, dass das Fahrzeug Fehler macht, ohne vorher zu warnen. Achten Sie deshalb immer auf den Verkehr und die Umgebung. Sie müssen jederzeit sofort eingreifen können. Wir zeigen Ihnen hier einige Beispiele möglicher Fehler:",
    ],
    bullets: [
      "Das Fahrzeug erkennt einen Kreisverkehr nicht und lenkt falsch.",
      "Das Fahrzeug erkennt die Fahrspur nicht wegen einer Baustelle.",
      "Das Fahrzeug bremst bei einer roten Ampel nicht ab.",
      "Das Fahrzeug erkennt beim Spurwechsel umliegende Fahrzeuge nicht.",
    ],
  },
]

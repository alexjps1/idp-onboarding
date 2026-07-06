/**
 * Baseline content for the onboarding guide. The LLM adapts non-alwaysKeep
 * modules to each participant's prior knowledge level. alwaysKeep modules are
 * rendered verbatim. This file is also the fallback when no OpenAI key is set.
 *
 * `system` links a module to a rated self-assessment system so the per-system
 * knowledge level can drive adaptation. `gifFolder` overrides the folder used
 * to look up available GIFs when it differs from the module id.
 */

export type OnboardingParagraph = {
  text: string
  /** 1–3 paths relative to /public/gifs/. Each must be referenced in the text
   *  with a matching [GIF1]/[GIF2]/[GIF3] placeholder (see app/api/onboarding/
   *  route.ts, which resolves these to (unten)/(links)/(rechts)/(Mitte) for
   *  LLM-adapted modules — this baseline text is rendered verbatim for
   *  alwaysKeep modules and used as source material for adapted ones). */
  gifs?: string[]
}

export type OnboardingModule = {
  id: string
  title: string
  paragraphs: OnboardingParagraph[]
  /** Bullet items, each with an optional illustrating GIF. */
  bullets?: { text: string; gif?: string }[]
  system?: string
  warning?: boolean
  alwaysKeep?: boolean
  /** GIF catalog folder name when it differs from the module id. */
  gifFolder?: string
}

export const ONBOARDING_MODULES: OnboardingModule[] = [
  {
    id: "aktivierung",
    title: "Aktivierung",
    alwaysKeep: true,
    paragraphs: [
      {
        text: "Der Status der Automation wird durch das Automationssymbol im Display angezeigt. Erscheint das Symbol grau, ist das teilautomatisierte Fahren nicht verfügbar.",
        gifs: ["aktivierung-deaktivierung/symbol-grau-nicht-verfuegbar.gif"],
      },
      {
        text: "Wenn das Automationssymbol weiß im Display aufleuchtet, ist das teilautomatisierte Fahren verfügbar.",
        gifs: ["aktivierung-deaktivierung/symbol-weiss-verfuegbar.gif"],
      },
      {
        text: "Bei Bedingungen, wie zum Beispiel schlechtem Wetter, kann es unter Umständen nicht verfügbar sein.",
      },
      {
        text: "Drücken Sie die „Aktivierungstaste“, um das teilautomatisierte Fahren zu aktivieren.",
        gifs: ["aktivierung-deaktivierung/aktivierungstaste.gif"],
      },
      {
        text: "Bei erfolgreicher Aktivierung leuchtet das Automationssymbol grün im Display auf.",
        gifs: ["aktivierung-deaktivierung/symbol-gruen-aktiviert.gif"],
      },
      {
        text: "Zudem leuchten die Lenkradlichter grün.",
        gifs: ["aktivierung-deaktivierung/lenkradlichter-gruen.gif"],
      },
      {
        text: "Es sind nun alle Fahrerassistenzsysteme aktiv und das Fahrzeug fährt teilautomatisiert. Richten Sie Ihren Blick weiterhin auf die Straße und nehmen Sie die Füße von den Pedalen (rechts). Ihre Hände können Sie während der automatisierten Fahrt vom Lenkrad nehmen oder am Lenkrad belassen, ohne zu lenken (links).",
        gifs: [
          "aktivierung-deaktivierung/haende-nicht-auf-lenkrad.jpg",
          "aktivierung-deaktivierung/fuesse-nicht-auf-pedalen.gif",
        ],
      },
    ],
  },
  {
    id: "verkehrszeichenassistent",
    title: "Verkehrszeichenassistent",
    system: "Verkehrszeichenassistent",
    paragraphs: [
      {
        text: "Das Fahrzeug erkennt Tempolimits.",
        gifs: ["verkehrszeichenassistent/schilderkennung-tempolimit.gif"],
      },
      {
        text: "Das erkannte Tempolimit wird im Display angezeigt. Bei einem neuen Tempolimit wird die erkannte Geschwindigkeit automatisch übernommen.",
        gifs: ["verkehrszeichenassistent/tempolimit-display.gif"],
      },
      {
        text: "Drücken Sie den Hebel nach oben oder unten, um die Geschwindigkeit individuell zu erhöhen (oben) oder zu verringern (unten).",
        gifs: ["verkehrszeichenassistent/geschwindigkeit-anpassen-hebel.gif"],
      },
      {
        text: "Ihre individuell eingestellte Geschwindigkeit wird im Display angezeigt.",
        gifs: ["verkehrszeichenassistent/custom-geschwindigkeit-display.gif"],
      },
    ],
  },
  {
    id: "abstandsregeltempomat",
    title: "Abstandsregeltempomat",
    system: "Abstandsregeltempomat",
    paragraphs: [
      {
        text: "Das Fahrzeug hält den Abstand zum Vorderfahrzeug automatisch. Es bremst oder beschleunigt, falls nötig.",
        gifs: ["abstandsregeltempomat/abstandsregelung-automatisch.gif"],
      },
      {
        text: "Drücken Sie die Abstandstasten, um den Abstand zum Vorderfahrzeug individuell zu erhöhen (rechts) oder zu verringern (links).",
        gifs: ["abstandsregeltempomat/abstand-anpassen-tasten.gif"],
      },
      {
        text: "Der individuell eingestellte Abstand wird im Display symbolisch angezeigt. Die Striche vor dem Fahrzeug visualisieren den Abstand – je mehr Striche, desto größer der eingestellte Abstand.",
        gifs: ["abstandsregeltempomat/abstand-display.gif"],
      },
    ],
  },
  {
    id: "ampelerkennung",
    title: "Ampelerkennung",
    system: "Ampelerkennung",
    paragraphs: [
      {
        text: "Das Fahrzeug erkennt Ampeln und bremst bei roten Ampeln automatisch bis zum Stillstand ab.",
        gifs: ["ampelerkennung/rotlicht-erkennung-bremsung.gif"],
      },
      {
        text: "Im Stillstand müssen Sie übernehmen und manuell anfahren. Das teilautomatisierte Fahren kann wieder aktiviert werden, sobald das Symbol weiß im Display aufleuchtet.",
        gifs: ["ampelerkennung/stillstand-manuelle-uebernahme.gif"],
      },
    ],
  },
  {
    id: "spurfuehrungsassistent",
    title: "Spurführungsassistent",
    system: "Spurführungsassistent",
    gifFolder: "spurhaltungsassistent",
    paragraphs: [
      {
        text: "Das Fahrzeug hält automatisch die Spur, wenn das teilautomatisierte Fahren aktiv ist.",
        gifs: ["spurhaltungsassistent/spurhaltung-automatisch.gif"],
      },
      {
        text: "Automatische Spurwechsel sind nicht möglich. Drücken Sie die Aktivierungstaste [GIF1], um das teilautomatisierte Fahren zu deaktivieren und den Spurwechsel manuell auszuführen [GIF2].",
        gifs: [
          "aktivierung-deaktivierung/aktivierungstaste.gif",
          "spurhaltungsassistent/spurwechsel-manuell-deaktivierung.gif",
        ],
      },
    ],
  },
  {
    id: "notbremsassistent",
    title: "Notbremsassistent",
    system: "Notbremsassistent",
    paragraphs: [
      {
        text: "Das Fahrzeug erkennt Hindernisse. Bevor es zum Zusammenstoß mit einem Hindernis, einer Person oder einem weiteren Fahrzeug kommt, bremst das Fahrzeug bis zum Stillstand ab.",
        gifs: ["notbremsassistent/hindernis-erkennung-vollbremsung.gif"],
      },
      {
        text: "Im Stillstand müssen Sie übernehmen und manuell anfahren. Das teilautomatisierte Fahren kann wieder aktiviert werden, sobald das Symbol weiß im Display aufleuchtet.",
        gifs: ["notbremsassistent/notbremsung-stillstand-uebernahme.gif"],
      },
    ],
  },
  {
    id: "deaktivierung",
    title: "Deaktivierung",
    alwaysKeep: true,
    paragraphs: [
      {
        text: "Drücken Sie die Aktivierungstaste erneut, um das teilautomatisierte Fahren zu beenden.",
        gifs: ["aktivierung-deaktivierung/aktivierungstaste.gif"],
      },
      {
        text: "Es wird auch beendet, wenn Sie manuell lenken (links) oder das Bremspedal drücken (rechts).",
        gifs: [
          "spurhaltungsassistent/spurwechsel-manuell-deaktivierung.gif",
          "aktivierung-deaktivierung/deaktivieren-durch-bremspedal.gif",
        ],
      },
      {
        text: "Bei erfolgreicher Deaktivierung erlöschen die Lenkradlichter und das Automationssymbol im Display erscheint wieder weiß.",
        gifs: ["aktivierung-deaktivierung/deaktiviert-display.gif"],
      },
    ],
  },
  {
    id: "risiken",
    title: "Risiken und Verantwortung",
    warning: true,
    alwaysKeep: true,
    paragraphs: [
      {
        text: "Das teilautomatisierte Fahren entbindet Sie nicht von der Verantwortung als Fahrer*in. Es funktioniert in den meisten Fällen sehr gut, kann jedoch nicht alle Fahrsituationen abdecken. Kommt das System an seine Grenzen, warnt es Sie und fordert zur Übernahme auf.",
        gifs: ["risiken/uebernahme-aufforderung.gif"],
      },
      {
        text: "Es kann jedoch vorkommen, dass das Fahrzeug Fehler macht, ohne vorher zu warnen. Achten Sie deshalb immer auf den Verkehr und die Umgebung. Sie müssen jederzeit sofort eingreifen können. Wir zeigen Ihnen hier einige Beispiele möglicher Fehler:",
      },
    ],
    bullets: [
      {
        text: "Das Fahrzeug erkennt einen Kreisverkehr nicht und lenkt falsch.",
        gif: "risiken/fehler-kreisverkehr.gif",
      },
      {
        text: "Das Fahrzeug erkennt die Fahrspur nicht wegen einer Baustelle.",
        gif: "risiken/fehler-baustelle-spur.gif",
      },
      {
        text: "Das Fahrzeug bremst bei einer roten Ampel nicht ab.",
        gif: "risiken/fehler-rotlicht-nicht-erkannt.gif",
      },
      {
        text: "Das Fahrzeug erkennt beim Spurwechsel umliegende Fahrzeuge nicht.",
        gif: "risiken/fehler-spurwechsel-fahrzeuge.gif",
      },
    ],
  },
]

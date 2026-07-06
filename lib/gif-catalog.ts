/**
 * Catalog of GIFs available to the voice tutor.
 *
 * Each entry's `name` is the path relative to /public/gifs/ and doubles as
 * the enum value passed in show_gif tool calls.
 */

export type GifEntry = {
  name: string
  description: string
}

export const GIF_CATALOG: GifEntry[] = [
  // ── Verkehrszeichenassistent ───────────────────────────────────────────────
  {
    name: "verkehrszeichenassistent/schilderkennung-tempolimit.gif",
    description:
      "Vogelperspektive auf einen weißen BMW, der sich einem Tempolimit-80-Schild nähert. Zeigt, wie die Frontkamera des Fahrzeugs ein Tempolimit-Verkehrszeichen erkennt.",
  },
  {
    name: "verkehrszeichenassistent/tempolimit-display.gif",
    description:
      "Kombiinstrument des BMW zeigt das aktuell geltende Tempolimit als Verkehrszeichen-Symbol im Display an. Das erkannte Schild wird dem Fahrer sichtbar gemacht.",
  },
  {
    name: "verkehrszeichenassistent/geschwindigkeit-anpassen-hebel.gif",
    description:
      "Nahaufnahme des Lenkradstockhebels im BMW-Innenraum. Zeigt, wie der Fahrer mit dem Hebel die angezeigte Geschwindigkeitsempfehlung des Verkehrszeichenassistenten bestätigt oder anpasst.",
  },
  {
    name: "verkehrszeichenassistent/custom-geschwindigkeit-display.gif",
    description:
      "Kombiinstrument zeigt eine individuell eingestellte Wunschgeschwindigkeit, die der Fahrer auf Basis des erkannten Tempolimits gesetzt hat.",
  },

  // ── Ampelerkennung ─────────────────────────────────────────────────────────
  {
    name: "ampelerkennung/rotlicht-erkennung-bremsung.gif",
    description:
      "Vogelperspektive auf einen weißen BMW, der auf einer leeren Straße auf eine rote Ampel zufährt. Verdeutlicht die Erkennung einer roten Ampel durch das Kamerasystem.",
  },
  {
    name: "ampelerkennung/stillstand-manuelle-uebernahme.gif",
    description:
      "Das Fahrzeug steht an einer Ampel. Sobald die Ampel auf Grün wechselt, fordert das System den Fahrer zur manuellen Übernahme und zum Anfahren auf.",
  },

  // ── Notbremsassistent ──────────────────────────────────────────────────────
  {
    name: "notbremsassistent/hindernis-erkennung-vollbremsung.gif",
    description:
      "Das System erkennt ein plötzliches Hindernis auf der Fahrbahn und leitet automatisch eine Vollbremsung ein. Das Fahrzeug kommt schnell zum Stillstand.",
  },
  {
    name: "notbremsassistent/notbremsung-stillstand-uebernahme.gif",
    description:
      "Kombiinstrument nach einer automatischen Notbremsung: zeigt 0 km/h, ein Tempolimit-40-Symbol und die Meldung 'Automation deaktiviert'. Das System hat vollständig angehalten und der Fahrer muss manuell übernehmen.",
  },

  // ── Spurhaltungsassistent ──────────────────────────────────────────────────
  {
    name: "spurhaltungsassistent/spurhaltung-automatisch.gif",
    description:
      "Vogelperspektive auf einen weißen BMW, der geradeaus in seiner Fahrspur fährt. Illustriert das automatische Spurhalten des Systems innerhalb der Fahrbahnmarkierungen.",
  },
  {
    name: "spurhaltungsassistent/spurwechsel-manuell-deaktivierung.gif",
    description:
      "Cartoon-Illustration von Händen am BMW-Lenkrad. Zeigt, wie der Fahrer bei einem gewollten Spurwechsel das Lenkrad selbst übernimmt, was das System temporär deaktiviert.",
  },

  // ── Abstandsregeltempomat ──────────────────────────────────────────────────
  {
    name: "abstandsregeltempomat/abstandsregelung-automatisch.gif",
    description:
      "Vogelperspektive: ein weißer BMW folgt einem grauen Fahrzeug auf der Autobahn. Das System hält automatisch den eingestellten Sicherheitsabstand zum Vordermann.",
  },
  {
    name: "abstandsregeltempomat/abstand-anpassen-tasten.gif",
    description:
      "Nahaufnahme der Lenkradtasten zur Einstellung des Folgeabstands. Zeigt, wie der Fahrer per Tastendruck den gewünschten Abstand zum vorausfahrenden Fahrzeug vergrößert oder verkleinert.",
  },
  {
    name: "abstandsregeltempomat/abstand-display.gif",
    description:
      "Kombiinstrument zeigt den eingestellten Folgeabstand sowie das vorausfahrende Fahrzeug als Symbol an. Der Fahrer sieht den aktuell aktiven Abstandsparameter.",
  },

  // ── Aktivierung & Deaktivierung ────────────────────────────────────────────
  {
    name: "aktivierung-deaktivierung/aktivierungstaste.gif",
    description:
      "Nahaufnahme der Aktivierungstaste am BMW-Lenkrad. Zeigt, wie der Fahrer mit einem Knopfdruck ein Assistenzsystem einschaltet.",
  },
  {
    name: "aktivierung-deaktivierung/symbol-grau-nicht-verfuegbar.gif",
    description:
      "Graues Dashboard-Symbol: Das Assistenzsystem ist aktuell nicht verfügbar, z. B. weil die Umgebungsbedingungen (Tempo, Straßenmarkierungen) nicht erfüllt sind.",
  },
  {
    name: "aktivierung-deaktivierung/symbol-weiss-verfuegbar.gif",
    description:
      "Weißes Dashboard-Symbol: Das Assistenzsystem ist verfügbar und einsatzbereit, aber noch nicht aktiviert.",
  },
  {
    name: "aktivierung-deaktivierung/symbol-gruen-aktiviert.gif",
    description:
      "Grünes Dashboard-Symbol: Das Assistenzsystem ist aktiv und übernimmt die Steuerung des Fahrzeugs.",
  },
  {
    name: "aktivierung-deaktivierung/lenkradlichter-gruen.gif",
    description:
      "BMW-Lenkrad mit grün leuchtenden Steuertasten. Die grüne Beleuchtung zeigt dem Fahrer physisch am Lenkrad an, dass ein Assistenzsystem aktiv ist.",
  },
  {
    name: "aktivierung-deaktivierung/deaktiviert-display.gif",
    description:
      "Kombiinstrument mit grünem Hintergrund, das den Systemstatus nach einer Deaktivierung anzeigt. Illustriert, wie die Abschaltung eines Assistenzsystems im Fahrzeugdisplay rückgemeldet wird.",
  },
  {
    name: "aktivierung-deaktivierung/fuesse-nicht-auf-pedalen.gif",
    description:
      "Illustration von Füßen, die nicht auf den Pedalen liegen. Zeigt die korrekte Fahrerhaltung bei aktivem Assistenzsystem: Füße sollen frei von Gas- und Bremspedal bleiben.",
  },
  {
    name: "aktivierung-deaktivierung/deaktivieren-durch-bremspedal.gif",
    description:
      "Illustration eines Fußes, der das Bremspedal betätigt. Zeigt, dass das Drücken des Bremspedals ein aktives Assistenzsystem sofort deaktiviert.",
  },
  {
    name: "aktivierung-deaktivierung/haende-nicht-auf-lenkrad.jpg",
    description:
      "Cartoon-Illustration von Händen, die in der Nähe, aber nicht auf dem BMW-Lenkrad sind. Zeigt, dass der Fahrer bei aktivem System das Lenkrad nicht festhalten muss, aber jederzeit bereit sein sollte zu übernehmen.",
  },

  // ── Risiken & Systemgrenzen ────────────────────────────────────────────────
  {
    name: "risiken/uebernahme-aufforderung.gif",
    description:
      "Kombiinstrument mit grünem Hintergrund zeigt bei 40 km/h die Meldung 'System nicht verfügbar, bitte übernehmen!' sowie ein Lenkrad-mit-Händen-Symbol. Das System fordert den Fahrer zur sofortigen manuellen Übernahme auf.",
  },
  {
    name: "risiken/fehler-kreisverkehr.gif",
    description:
      "Vogelperspektive auf einen weißen BMW, der in einen Kreisverkehr einfährt. Illustriert eine Systemgrenze: Spurhaltungs- und Navigationssysteme können bei der komplexen Geometrie von Kreisverkehren versagen.",
  },
  {
    name: "risiken/fehler-baustelle-spur.gif",
    description:
      "Vogelperspektive: weißer BMW auf einer Straße mit orangen Baustellenmarkierungen und Pylonen. Zeigt, dass überlagerte oder abweichende Spurmarkierungen in Baustellen das Spurhaltungssystem verwirren können.",
  },
  {
    name: "risiken/fehler-rotlicht-nicht-erkannt.gif",
    description:
      "Rückansicht eines BMW an einer Kreuzung mit roter Ampel. Illustriert das Risiko, dass die Ampelerkennung eine rote Ampel unter bestimmten Umständen nicht zuverlässig erkennt — der Fahrer muss stets aufmerksam bleiben.",
  },
  {
    name: "risiken/fehler-spurwechsel-fahrzeuge.gif",
    description:
      "Rückansicht eines BMW auf einer zweispurigen Straße mit einem weißen Fahrzeug auf der Nebenspur. Zeigt das Risiko bei Spurwechseln, wenn sich andere Fahrzeuge im toten Winkel befinden und vom System möglicherweise nicht erkannt werden.",
  },
]

/** Flat list of GIF names — used as enum values in the show_gif tool schema. */
export const GIF_NAMES = GIF_CATALOG.map((g) => g.name)

/** GIFs whose name lives under the given /public/gifs/ subfolder. */
export function gifsForFolder(folder: string): GifEntry[] {
  return GIF_CATALOG.filter((g) => g.name.startsWith(`${folder}/`))
}

/** Builds the tool description with the full catalog embedded for the model. */
export function buildShowGifDescription(): string {
  const entries = GIF_CATALOG.map((g) => `- ${g.name}: ${g.description}`).join(
    "\n"
  )
  return `Zeige dem Nutzer eine passende GIF-Animation unterhalb der Sprachblase. Rufe dieses Tool auf, sobald eine visuelle Illustration hilfreich ist. Verfügbare GIFs:\n${entries}`
}

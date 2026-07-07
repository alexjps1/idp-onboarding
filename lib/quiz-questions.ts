/**
 * Knowledge-check questions for the post-onboarding quiz. Ported from the legacy
 * study prototype (HMI_LFE `categoryQuestions.js`), flattened into a single
 * ordered list with each question tagged by its onboarding-module category.
 *
 * `category` deliberately matches the ONBOARDING_MODULES `id` (see
 * lib/onboarding-modules.ts) so the quiz can be filtered to only the modules the
 * guide actually showed (omitted modules are skipped, mirroring the legacy
 * "only visible categories" behaviour), and the saved answers join cleanly back
 * to which module was presented.
 */

export type QuizOption = {
  text: string
  correct: boolean
}

export type QuizQuestion = {
  /** Onboarding-module id this question belongs to (see lib/onboarding-modules.ts). */
  category: string
  /** Human-readable category / assistance-system name. */
  categoryName: string
  question: string
  options: QuizOption[]
}

export const QUIZ_QUESTIONS: QuizQuestion[] = [
  // ── Aktivierung ──────────────────────────────────────────────────────
  {
    category: "aktivierung",
    categoryName: "Aktivierung",
    question:
      "Wie können Sie als Fahrer*in das teilautomatisierte Fahren aktivieren?",
    options: [
      { text: "Durch das Drücken des Bremspedals", correct: false },
      { text: "Durch das Drücken der Aktivierungstaste", correct: true },
      { text: "Durch das Loslassen des Lenkrads", correct: false },
      { text: "Durch einen Doppelklick auf die Set-Taste", correct: false },
    ],
  },
  {
    category: "aktivierung",
    categoryName: "Aktivierung",
    question:
      "Leuchtet das Automationssymbol in weiß, ist das teilautomatisierte Fahren verfügbar.",
    options: [
      { text: "Richtig", correct: true },
      { text: "Falsch", correct: false },
    ],
  },
  {
    category: "aktivierung",
    categoryName: "Aktivierung",
    question:
      "In welcher Farbe leuchtet das Automationssymbol bei erfolgreicher Aktivierung des teilautomatisierten Fahrens?",
    options: [
      { text: "Blau", correct: false },
      { text: "Rot", correct: false },
      { text: "Gelb", correct: false },
      { text: "Grün", correct: true },
    ],
  },

  // ── Verkehrszeichenassistent ─────────────────────────────────────────
  {
    category: "verkehrszeichenassistent",
    categoryName: "Verkehrszeichenassistent",
    question:
      "Bei einem neuen Tempolimit wird die erkannte Geschwindigkeit automatisch übernommen.",
    options: [
      { text: "Richtig", correct: true },
      { text: "Falsch", correct: false },
    ],
  },
  {
    category: "verkehrszeichenassistent",
    categoryName: "Verkehrszeichenassistent",
    question: "Wo wird Ihnen als Fahrer*in das erkannte Tempolimit angezeigt?",
    options: [
      { text: "Im Seitenspiegel", correct: false },
      { text: "Im Display", correct: true },
      { text: "Auf dem Lenkrad", correct: false },
      { text: "Auf der Aktivierungstaste", correct: false },
    ],
  },
  {
    category: "verkehrszeichenassistent",
    categoryName: "Verkehrszeichenassistent",
    question:
      "Können Sie als Fahrer*in während der teilautomatisierten Fahrt die Geschwindigkeit manuell anpassen?",
    options: [
      { text: "Ja", correct: true },
      { text: "Nein", correct: false },
    ],
  },

  // ── Abstandsregeltempomat ────────────────────────────────────────────
  {
    category: "abstandsregeltempomat",
    categoryName: "Abstandsregeltempomat",
    question:
      "Ist das teilautomatisierte Fahren aktiviert, hält das Fahrzeug automatisch den Abstand zum Vorderfahrzeug.",
    options: [
      { text: "Richtig", correct: true },
      { text: "Falsch", correct: false },
    ],
  },
  {
    category: "abstandsregeltempomat",
    categoryName: "Abstandsregeltempomat",
    question:
      "Für Sie als Fahrer*in ist es nicht möglich, den Abstand zum Vorderfahrzeug individuell anzupassen.",
    options: [
      { text: "Richtig", correct: false },
      { text: "Falsch", correct: true },
    ],
  },
  {
    category: "abstandsregeltempomat",
    categoryName: "Abstandsregeltempomat",
    question:
      "Wie wird der eingestellte Abstand zum Vorderfahrzeug im Display symbolisch dargestellt?",
    options: [
      { text: "Durch ein rotes Lenkrad", correct: false },
      { text: "Durch Blinken des Automationssymbols", correct: false },
      { text: "Durch Striche vor dem Fahrzeug", correct: true },
      { text: "Durch ein weißes Dreieck", correct: false },
    ],
  },

  // ── Ampelerkennung ───────────────────────────────────────────────────
  {
    category: "ampelerkennung",
    categoryName: "Ampelerkennung",
    question:
      "Erkennt das Fahrzeug Ampeln, wenn das teilautomatisierte Fahren aktiv ist?",
    options: [
      { text: "Richtig", correct: true },
      { text: "Falsch", correct: false },
    ],
  },
  {
    category: "ampelerkennung",
    categoryName: "Ampelerkennung",
    question:
      "Das Fahrzeug bremst automatisch, wenn es eine rote Ampel erkannt hat.",
    options: [
      { text: "Richtig", correct: true },
      { text: "Falsch", correct: false },
    ],
  },
  {
    category: "ampelerkennung",
    categoryName: "Ampelerkennung",
    question:
      "Im Stillstand erkennt das Fahrzeug grüne Ampeln und fährt automatisch wieder los.",
    options: [
      { text: "Richtig", correct: false },
      { text: "Falsch", correct: true },
    ],
  },

  // ── Spurführungsassistent ────────────────────────────────────────────
  {
    category: "spurfuehrungsassistent",
    categoryName: "Spurführungsassistent",
    question:
      "Ist das teilautomatisierte Fahren aktiv, hält das Fahrzeug die Spur selbstständig?",
    options: [
      { text: "Richtig", correct: true },
      { text: "Falsch", correct: false },
    ],
  },
  {
    category: "spurfuehrungsassistent",
    categoryName: "Spurführungsassistent",
    question:
      "Können Sie als Fahrer*in das Lenkrad loslassen, wenn das teilautomatisierte Fahren aktiv ist?",
    options: [
      { text: "Ja", correct: true },
      { text: "Nein", correct: false },
    ],
  },
  {
    category: "spurfuehrungsassistent",
    categoryName: "Spurführungsassistent",
    question:
      "Das Fahrzeug schlägt eigenständig Spurwechsel vor, auch wenn es die Verkehrssituation nicht zulässt.",
    options: [
      { text: "Richtig", correct: false },
      { text: "Falsch", correct: true },
    ],
  },

  // ── Notbremsassistent ────────────────────────────────────────────────
  {
    category: "notbremsassistent",
    categoryName: "Notbremsassistent",
    question: "Funktioniert der Notbremsassistent nur bei statischen Hindernissen?",
    options: [
      { text: "Ja", correct: false },
      { text: "Nein", correct: true },
    ],
  },
  {
    category: "notbremsassistent",
    categoryName: "Notbremsassistent",
    question: "In welcher Situation greift der Notbremsassistent ein?",
    options: [
      {
        text: "Wenn der Fahrer eine Warnung durch die Set-Taste bestätigt",
        correct: false,
      },
      { text: "Nur in bestimmten Verkehrssituationen", correct: false },
      {
        text: "Wenn eine Kollision mit einem Hindernis, einer Person oder einem Fahrzeug droht",
        correct: true,
      },
      { text: "Nur bei niedrigen Geschwindigkeiten unter 30 km/h", correct: false },
    ],
  },
  {
    category: "notbremsassistent",
    categoryName: "Notbremsassistent",
    question:
      "Was passiert, wenn der Notbremsassistent eine Kollisionsgefahr registriert?",
    options: [
      { text: "Der Fahrer wird dazu aufgefordert, selbst zu bremsen", correct: false },
      { text: "Das Fahrzeug bremst automatisch bis zum Stillstand", correct: true },
      { text: "Das Fahrzeug reagiert gar nicht", correct: false },
      { text: "Der Fahrer erhält nur eine visuelle Warnung", correct: false },
    ],
  },

  // ── Deaktivierung ────────────────────────────────────────────────────
  {
    category: "deaktivierung",
    categoryName: "Deaktivierung",
    question: "Wie kann das teilautomatisierte Fahren deaktiviert werden?",
    options: [
      { text: "Durch langes Drücken der Set-Taste", correct: false },
      { text: "Durch kurzes Antippen des Blinkers", correct: false },
      { text: "Durch erneutes Drücken der Aktivierungstaste", correct: true },
      {
        text: "Durch manuelles Einstellen des Abstands über die Abstandstasten",
        correct: false,
      },
    ],
  },
  {
    category: "deaktivierung",
    categoryName: "Deaktivierung",
    question:
      "Kann das teilautomatisierte Fahren durch manuelles Eingreifen (z. B. Lenken oder Bremsen) deaktiviert werden?",
    options: [
      { text: "Ja", correct: true },
      { text: "Nein", correct: false },
    ],
  },
  {
    category: "deaktivierung",
    categoryName: "Deaktivierung",
    question:
      "Wie wird angezeigt, dass das teilautomatisierte Fahren deaktiviert wurde?",
    options: [
      { text: "Durch ein rotes Ausrufezeichen im Display", correct: false },
      { text: "Durch ein akustisches Signal", correct: false },
      {
        text: "Durch das Erlöschen der Lenkradlichter und des Symbols im Display",
        correct: true,
      },
      { text: "Durch eine Warnmeldung im Head-Up-Display", correct: false },
    ],
  },

  // ── Risiken und Verantwortung ────────────────────────────────────────
  {
    category: "risiken",
    categoryName: "Risiken und Verantwortung",
    question:
      "Das teilautomatisierte Fahren entbindet Sie als Fahrer*in von der Verantwortung, sodass Sie nicht mehr aufmerksam sein müssen.",
    options: [
      { text: "Richtig", correct: false },
      { text: "Falsch", correct: true },
    ],
  },
  {
    category: "risiken",
    categoryName: "Risiken und Verantwortung",
    question:
      "Müssen Sie als Fahrer*in jederzeit auf unvorhersehbare Situationen vorbereitet sein?",
    options: [
      { text: "Ja", correct: true },
      { text: "Nein", correct: false },
    ],
  },
  {
    category: "risiken",
    categoryName: "Risiken und Verantwortung",
    question:
      "Warum dürfen Sie sich als Fahrer*in nicht vollständig auf die Assistenzsysteme verlassen?",
    options: [
      { text: "Weil die Systeme zu langsam reagieren", correct: false },
      {
        text: "Weil das teilautomatisierte Fahrzeug immer 10 km/h schneller fährt als erlaubt",
        correct: false,
      },
      {
        text: "Weil die Systeme Fehler machen können, ohne Sie als Fahrer*in zu warnen",
        correct: true,
      },
      { text: "Weil das teilautomatisierte Fahren nur auf Autobahnen nutzbar ist", correct: false },
    ],
  },
]

/**
 * The five SAE-L2 driver-assistance systems rated across the study, with the
 * short descriptions shown in the self-assessment matrices. Single source of
 * truth so the theory and practice pages stay in sync.
 */
export type AssistanceSystem = {
  name: string
  description: string
}

export const ASSISTANCE_SYSTEMS: AssistanceSystem[] = [
  {
    name: "Verkehrszeichenassistent",
    description:
      "Erkennt Verkehrszeichen und zeigt die Informationen im Fahrzeug an. Kann die Geschwindigkeit entsprechend automatisch anpassen.",
  },
  {
    name: "Abstandsregeltempomat",
    description:
      "Hält automatisch einen voreingestellten Abstand zum vorausfahrenden Fahrzeug durch Beschleunigen und Abbremsen.",
  },
  {
    name: "Ampelerkennung",
    description:
      "Erkennt Ampeln und zeigt den Status im Fahrzeug an. Kann auf das Ampelsignal reagieren oder die Fahrperson entsprechend informieren.",
  },
  {
    name: "Spurführungsassistent",
    description:
      "Erkennt die Fahrspurmarkierungen und hält das Fahrzeug aktiv in der Spur, ohne die Fahrspur zu verlassen.",
  },
  {
    name: "Notbremsassistent",
    description:
      "Erkennt Kollisionsgefahren und warnt davor. Bremst bei drohender Kollision automatisch zur Reduktion der Aufprallgeschwindigkeit.",
  },
]

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
    description: "Passt Geschwindigkeit an Verkehrszeichen an.",
  },
  {
    name: "Abstandsregeltempomat",
    description: "Hält voreingestellten Abstand zum Vorderfahrzeug.",
  },
  {
    name: "Ampelerkennung",
    description: "Reagiert auf Ampeln oder informiert den Fahrer.",
  },
  {
    name: "Spurführungsassistent",
    description: "Hält Fahrzeug in der Spur.",
  },
  {
    name: "Notbremsassistent",
    description: "Bremst bei drohender Kollision automatisch.",
  },
]

/**
 * Systems the proactive tutor must never offer to explain on its own, because
 * they are self-explanatory and require no change to how the person drives. The
 * driver can still ask about them — the tutor just won't proactively propose
 * them. Add more names here as needed.
 */
export const NON_OFFERABLE_SYSTEMS: string[] = ["Notbremsassistent"]

# Prompt-Tuning: „Vor der Fahrt"-Onboarding-Leitfaden

Harness, um den `ONBOARDING_SYSTEM_PROMPT` ([../lib/prompts.ts](../lib/prompts.ts)) zu tunen:
**bei wenig Wissen einfacher & länger erklären, mit steigendem Wissen kürzer, bei sehr hohem
Wissen komplett weglassen.**

## Rollenverteilung

- **`tune.py` generiert nur.** Es ruft OpenAI exakt wie die App-Route `adaptModule`
  ([../app/api/onboarding/route.ts](../app/api/onboarding/route.ts)) auf (`gpt-5-mini`,
  `reasoning_effort="low"`, JSON-Output) und schreibt einen Markdown-Report mit Wortzahlen je
  Wissensstufe. **Kein Scoring, kein Judge-LLM, keine automatische Prompt-Umschreibung.**
- **Der Judge ist Opus / Claude Code** (im Chat): liest den Report, bewertet jede Antwort gegen die
  Ziel-Leiter und schreibt verbesserte Kandidaten-Prompts.

## Setup

> ⚠️ **venv NICHT im Projektbaum anlegen.** Next/turbopack beobachtet den Projektordner;
> ein venv mit Tausenden Dateien überlastet den File-Watcher und kann `npm run dev` aufhängen.
> Lege das venv außerhalb des Repos an:

```bash
# venv außerhalb des Projekts (einmalig)
python3 -m venv ~/.venvs/idp-tuning
~/.venvs/idp-tuning/bin/pip install -r prompt-tuning/requirements.txt

# Skript darüber ausführen
~/.venvs/idp-tuning/bin/python prompt-tuning/tune.py --prompt prompt-tuning/prompts/current.txt --dry-run
# OPENAI_API_KEY kommt aus ../.env.local (dieselbe Datei wie die App)
```

## Nutzung

```bash
# 0) Zusammenbau prüfen, ohne API-Calls
python tune.py --prompt prompts/current.txt --dry-run

# 1) Baseline generieren
python tune.py --prompt prompts/current.txt

# 2) A/B: aktueller Prompt gegen einen Kandidaten
python tune.py --prompt prompts/current.txt --prompt prompts/candidate-1.txt

# Optionen
#   --runs 3        mehrere Outputs je Szenario (Reasoning-Streuung sichtbar machen)
#   --model NAME    Modell überschreiben (Default: $OPENAI_CONTENT_MODEL oder gpt-5-mini)
#   --samples PFAD  anderes Sample-Set
#   --label NAME    Dateiname des Reports
```

Reports landen in `out/` (gitignored): `<timestamp>-<label>.md` (lesen) + `.json` (roh).

## Tuning-Loop

1. `python tune.py --prompt prompts/current.txt` → Baseline-Report.
2. **Opus bewertet** den Report gegen die `expect`-Notizen je Szenario:
   - Sinken die Wortzahlen monoton mit steigendem Wissen?
   - Einfache, konkrete Sprache (ggf. Analogie) bei wenig Vorwissen?
   - Beidseitig hoch ⇒ `omitted:true` + leere Absätze, **ohne** Fülltext?
   - Faktentreue: keine erfundenen Tasten/Funktionen über die Baseline hinaus.
3. **Opus schreibt** `prompts/candidate-1.txt` (gezielte Edits an der Längen-/Weglass-Leiter).
4. `python tune.py --prompt prompts/current.txt --prompt prompts/candidate-1.txt` → A/B.
5. Wiederholen. Finalen Wortlaut zurück in `ONBOARDING_SYSTEM_PROMPT` übertragen.

## Dateien

| Datei | Zweck |
|---|---|
| `tune.py` | Generierungs-/Vergleichs-Harness (CLI) |
| `samples.json` | Kuratierte Samples: Modul-Baselines + Wissensprofile (1–7) + `expect`-Notiz |
| `prompts/current.txt` | Snapshot des Produktiv-Prompts (GIF-Block durch Platzhalter ersetzt) |
| `prompts/candidate-*.txt` | Tuning-Kandidaten (von Opus geschrieben) |
| `out/` | Generierte Reports (gitignored) |

> Hinweis: GIF-Zuordnung ist **nicht** Ziel dieses Tunings. In `prompts/current.txt` ist der
> dynamische GIF-Katalog (`buildOnboardingGifGuide()`) durch einen kurzen Platzhalter ersetzt; die
> Samples tragen keine GIFs und der Report ignoriert `gifs`-Felder.

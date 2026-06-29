#!/usr/bin/env python3
"""
Prompt-Tuning-Harness für den „Vor der Fahrt"-Onboarding-Leitfaden.

Das Skript GENERIERT nur: Es nimmt einen Prompt-unter-Test plus kuratierte
Samples und ruft OpenAI exakt so auf wie die App-Route adaptModule()
(app/api/onboarding/route.ts) — gpt-5-mini, reasoning_effort="low",
response_format=json_object. Heraus kommt ein lesbarer Markdown-Report (+ rohes
JSON) mit Wortzahlen je Wissensstufe.

Das BEWERTEN (LLM-as-a-judge) und das Verbessern des Prompts übernimmt Opus /
Claude Code im Chat — hier passiert kein Scoring und keine Prompt-Umschreibung.

Beispiele:
  python tune.py --prompt prompts/current.txt --dry-run
  python tune.py --prompt prompts/current.txt
  python tune.py --prompt prompts/current.txt --prompt prompts/candidate-1.txt
"""

from __future__ import annotations

import argparse
import datetime as dt
import json
import pathlib
import sys

HERE = pathlib.Path(__file__).resolve().parent
REPO = HERE.parent

# 1–7 Skala der Selbsteinschätzung (identisch zu app/api/onboarding/route.ts).
SCALE = [
    "keins/keine",
    "sehr wenig",
    "wenig",
    "eher wenig",
    "eher viel",
    "viel",
    "sehr viel",
]


def scale_label(value):
    if value is None or value < 1 or value > 7:
        return "unbekannt"
    return SCALE[value - 1]


def build_mod(module: dict, theory, practice) -> dict:
    """Baut die ModuleForModel-Payload exakt wie die Route."""
    name = module.get("system")
    if name:
        knowledge = (
            f'System "{name}": '
            f"Theorie={scale_label(theory)}, Praxis={scale_label(practice)}"
        )
    else:
        knowledge = (
            f"Allgemein (kein Einzelsystem): "
            f"Theorie≈{scale_label(theory)}, Praxis≈{scale_label(practice)}"
        )
    return {
        "id": module["id"],
        "title": module["title"],
        "alwaysKeep": False,
        "knowledge": knowledge,
        "baseline": module["baseline"],
    }


def word_count(text: str) -> int:
    return len(text.split())


def section_words(section: dict) -> int:
    return sum(word_count(p.get("text", "")) for p in section.get("paragraphs", []))


# --------------------------------------------------------------------------- #
# OpenAI                                                                       #
# --------------------------------------------------------------------------- #


def get_api_key() -> str | None:
    """Gleiche Logik wie lib/openai.ts getOpenAIKey()."""
    import os

    key = (os.environ.get("OPENAI_API_KEY") or "").strip()
    if not key or key.startswith("sk-dummy"):
        return None
    return key


def make_client(api_key: str):
    from openai import OpenAI

    return OpenAI(api_key=api_key)


def adapt_module(client, model: str, prompt_text: str, mod: dict) -> dict:
    """Spiegelt adaptModule(): ein Modul -> eine adaptierte Section."""
    user = json.dumps({"modules": [mod]}, ensure_ascii=False)
    resp = client.chat.completions.create(
        model=model,
        messages=[
            {"role": "system", "content": prompt_text},
            {"role": "user", "content": user},
        ],
        response_format={"type": "json_object"},
        # gpt-5-mini ist ein Reasoning-Modell: keine temperature; "low" effort
        # wie in der Route (minimal neigte dazu, statt wegzulassen Fülltext zu
        # schreiben). extra_body hält es SDK-versionsrobust.
        extra_body={"reasoning_effort": "low"},
    )
    raw = resp.choices[0].message.content or "{}"
    parsed = json.loads(raw)
    sections = parsed.get("sections") or []
    return sections[0] if sections else {}


# --------------------------------------------------------------------------- #
# Run                                                                          #
# --------------------------------------------------------------------------- #


def run_scenario(client, model, prompt_text, mod, runs) -> list:
    """Generiert `runs` Outputs für ein Modul. Fehler werden eingefangen."""
    out = []
    for _ in range(runs):
        try:
            section = adapt_module(client, model, prompt_text, mod)
            out.append(
                {
                    "omitted": bool(section.get("omitted")),
                    "paragraphs": [
                        p.get("text", "") for p in section.get("paragraphs", [])
                    ],
                    "words": section_words(section),
                    "error": None,
                }
            )
        except Exception as exc:  # noqa: BLE001 — sichtbar machen, nicht schlucken
            out.append(
                {"omitted": False, "paragraphs": [], "words": 0, "error": str(exc)}
            )
    return out


# --------------------------------------------------------------------------- #
# Report                                                                       #
# --------------------------------------------------------------------------- #


def fmt_runs_words(runs: list) -> str:
    ws = [r["words"] for r in runs]
    if len(ws) == 1:
        return str(ws[0])
    return f"{round(sum(ws) / len(ws))} (Ø von {ws})"


def render_markdown(meta: dict, prompt_labels: list, scenarios: list, data: dict) -> str:
    """data[scn_idx][prompt_label] = list[run-dict]."""
    lines = []
    lines.append(f"# Tuning-Report — {meta['title']} — {meta['timestamp']}")
    lines.append("")
    for lbl, path in meta["prompts"].items():
        lines.append(f"- **{lbl}**: `{path}`")
    lines.append(f"- Modell: `{meta['model']}` · runs/Szenario: {meta['runs']}")
    lines.append("")

    # Übersichtstabelle: Wörter & omitted je Prompt (Monotonie-Check auf einen Blick).
    head = ["Szenario", "Theorie", "Praxis"]
    for lbl in prompt_labels:
        head.append(f"Wörter ({lbl})")
        head.append(f"omitted ({lbl})")
    lines.append("## Übersicht")
    lines.append("")
    lines.append("| " + " | ".join(head) + " |")
    lines.append("|" + "|".join(["---"] * len(head)) + "|")
    for i, scn in enumerate(scenarios):
        row = [
            scn["label"],
            f"{scn['theory']} ({scale_label(scn['theory'])})",
            f"{scn['practice']} ({scale_label(scn['practice'])})",
        ]
        for lbl in prompt_labels:
            runs = data[i][lbl]
            row.append(fmt_runs_words(runs))
            row.append("ja" if any(r["omitted"] for r in runs) else "nein")
        lines.append("| " + " | ".join(row) + " |")
    lines.append("")

    # Detail je Szenario.
    lines.append("## Details")
    for i, scn in enumerate(scenarios):
        lines.append("")
        lines.append(f"### {scn['label']}")
        lines.append(
            f"- Modul: `{scn['module']}` · "
            f"Theorie {scn['theory']} ({scale_label(scn['theory'])}) · "
            f"Praxis {scn['practice']} ({scale_label(scn['practice'])})"
        )
        if scn.get("expect"):
            lines.append(f"- **Erwartung:** {scn['expect']}")
        for lbl in prompt_labels:
            runs = data[i][lbl]
            lines.append("")
            lines.append(f"#### {lbl}")
            for ri, r in enumerate(runs, 1):
                tag = f" (Lauf {ri})" if len(runs) > 1 else ""
                if r["error"]:
                    lines.append(f"- ⚠️ FEHLER{tag}: {r['error']}")
                    continue
                lines.append(
                    f"- omitted: **{str(r['omitted']).lower()}** · "
                    f"Absätze: {len(r['paragraphs'])} · Wörter: {r['words']}{tag}"
                )
                if r["omitted"] and not r["paragraphs"]:
                    lines.append("  - _(korrekt weggelassen, keine Absätze)_")
                for pi, para in enumerate(r["paragraphs"], 1):
                    lines.append(f"  {pi}. {para}")
    lines.append("")
    return "\n".join(lines)


# --------------------------------------------------------------------------- #
# CLI                                                                          #
# --------------------------------------------------------------------------- #


def load_dotenvs():
    from dotenv import load_dotenv

    # Gleiche Dateien wie die App; .env.local hat Vorrang.
    load_dotenv(REPO / ".env.local")
    load_dotenv(REPO / ".env")


def resolve(path: str) -> pathlib.Path:
    p = pathlib.Path(path)
    return p if p.is_absolute() else (HERE / p)


def main() -> int:
    import os

    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument(
        "--prompt",
        action="append",
        required=True,
        help="Pfad zu einer Prompt-Datei. Mehrfach für A/B-Vergleich.",
    )
    ap.add_argument("--samples", default="samples.json")
    ap.add_argument(
        "--model",
        default=None,
        help="Default: $OPENAI_CONTENT_MODEL oder gpt-5-mini.",
    )
    ap.add_argument("--runs", type=int, default=1, help="Outputs je Szenario.")
    ap.add_argument("--label", default=None, help="Name für die Report-Datei.")
    ap.add_argument("--out", default="out", help="Ausgabeordner.")
    ap.add_argument(
        "--dry-run",
        action="store_true",
        help="Nur Prompt-/Payload-Zusammenbau zeigen, keine API-Calls.",
    )
    args = ap.parse_args()

    load_dotenvs()
    model = args.model or os.environ.get("OPENAI_CONTENT_MODEL") or "gpt-5-mini"

    # Samples laden.
    samples = json.loads(resolve(args.samples).read_text(encoding="utf-8"))
    modules = samples["modules"]
    scenarios = samples["scenarios"]

    # Prompts laden (Label = Dateiname ohne Endung).
    prompt_paths = {}
    prompt_texts = {}
    for raw in args.prompt:
        p = resolve(raw)
        lbl = p.stem
        prompt_paths[lbl] = str(p.relative_to(HERE)) if HERE in p.parents else str(p)
        prompt_texts[lbl] = p.read_text(encoding="utf-8")
    prompt_labels = list(prompt_texts.keys())

    if args.dry_run:
        print(f"Modell: {model} · runs: {args.runs}")
        print(f"Prompts: {', '.join(prompt_labels)}")
        for scn in scenarios:
            mod = build_mod(modules[scn["module"]], scn["theory"], scn["practice"])
            print(f"\n=== {scn['label']} ===")
            print("user-payload:")
            print(json.dumps({"modules": [mod]}, ensure_ascii=False, indent=2))
        first = prompt_labels[0]
        print(f"\n--- system prompt '{first}' (erste 400 Zeichen) ---")
        print(prompt_texts[first][:400])
        return 0

    api_key = get_api_key()
    if not api_key:
        print(
            "FEHLER: OPENAI_API_KEY nicht gesetzt (oder sk-dummy). "
            "Setze ihn in .env.local.",
            file=sys.stderr,
        )
        return 1
    client = make_client(api_key)

    # data[scn_idx][prompt_label] = list[run-dict]
    data = {i: {} for i in range(len(scenarios))}
    total = len(scenarios) * len(prompt_labels)
    n = 0
    for i, scn in enumerate(scenarios):
        mod = build_mod(modules[scn["module"]], scn["theory"], scn["practice"])
        for lbl in prompt_labels:
            n += 1
            print(f"[{n}/{total}] {scn['label']} · {lbl} …", flush=True)
            data[i][lbl] = run_scenario(
                client, model, prompt_texts[lbl], mod, args.runs
            )

    ts = dt.datetime.now().strftime("%Y%m%d-%H%M%S")
    title = args.label or "+".join(prompt_labels)
    meta = {
        "title": title,
        "timestamp": ts,
        "model": model,
        "runs": args.runs,
        "prompts": prompt_paths,
    }

    out_dir = resolve(args.out)
    out_dir.mkdir(parents=True, exist_ok=True)
    base = out_dir / f"{ts}-{title}"
    md = render_markdown(meta, prompt_labels, scenarios, data)
    base.with_suffix(".md").write_text(md, encoding="utf-8")
    base.with_suffix(".json").write_text(
        json.dumps(
            {"meta": meta, "scenarios": scenarios, "results": data},
            ensure_ascii=False,
            indent=2,
        ),
        encoding="utf-8",
    )
    print(f"\nReport: {base.with_suffix('.md')}")
    print(f"JSON:   {base.with_suffix('.json')}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

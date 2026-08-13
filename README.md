# IDP Onboarding — Onboarding-Studie Fahrassistenz

A Next.js web app for a driving-simulator study on onboarding drivers to advanced driver-assistance systems (ADAS). Participants work through a German-language study flow — self-assessment, an adaptive onboarding guide, a knowledge quiz — and then drive in a [SILAB](https://wivw.de/en/silab) simulator accompanied by an AI voice tutor built on the OpenAI Realtime API.

## Study flows

The landing page (`/`) lets the study lead enter or generate a participant ID and pick one of three conditions:

| Route | Condition | Steps |
| --- | --- | --- |
| `/ohnetutor` | Nur Onboarding | Welcome → self-assessment → guide → quiz → end |
| `/nurfahrt` | Nur Fahrt | Welcome → drive with AI tutor → end |
| `/mittutor` | Onboarding und Fahrt | Full flow: all of the above |

The ordered step definition lives in [lib/study-steps.ts](lib/study-steps.ts) — a single source of truth for routing, progress indication and step labels.

## How it works

**Adaptive onboarding guide.** [lib/onboarding-modules.ts](lib/onboarding-modules.ts) holds the baseline content for each ADAS module. `/api/onboarding` sends it to an OpenAI content model together with the participant's self-assessment ratings and gets back a version adapted to their prior knowledge; `alwaysKeep` modules render verbatim, and the baseline is the fallback when no API key is configured. Modules can embed instructional GIFs from `public/gifs/` (catalog in [lib/gif-catalog.ts](lib/gif-catalog.ts)).

**AI voice tutor.** During the drive, the browser opens a WebRTC session to the OpenAI Realtime API using an ephemeral key minted by [/api/realtime](app/api/realtime/route.ts). The tutor speaks proactively as well as on demand — a one-time self-introduction, a prompt when the driving automation is first activated, and fixed-zone nudges and system-limit warnings along the track ([lib/track-zones.ts](lib/track-zones.ts), hooks in [components/study/](components/study/)). It can also show GIFs to the participant via a tool call. Set `NEXT_PUBLIC_REALTIME_TEXT_INPUT=true` to type to the tutor instead of speaking (useful for development without a microphone).

**SILAB integration.** The Java component [silab_config/java/SilabServer.java](silab_config/java/SilabServer.java) runs inside SILAB and pushes ADAS + vehicle state every 500 ms to `/api/silab-ingest` (plain HTTP with a shared secret — the SILAB JVM cannot complete a TLS handshake). The client polls [/api/simstate](app/api/simstate/route.ts) to react to what happens in the simulator. Alternatively, `SILAB_COMMUNICATION_MODE=tcp` makes the server poll the FS-SCENERY machine directly over TCP (`SILAB_ADDR`) when both are on the same network. `silab_config/` also contains the full SILAB scenario (track, models, DMS config), and [backendGo/sendMessage.go](backendGo/sendMessage.go) is a small standalone TCP client for testing the SILAB socket.

**Study data.** Everything a participant produces — questionnaire ratings, the adapted guide modules, quiz answers, the full voice-tutor conversation log — is collected into one session record and mirrored to the server as `data/sessions/<id>.json` (types in [lib/study-data.ts](lib/study-data.ts)). The `/trials` page is a viewer for these records, gated server-side by a shared password ([lib/trials-auth.ts](lib/trials-auth.ts)).

## Getting started

Prerequisites: Node.js and [pnpm](https://pnpm.io).

```bash
pnpm install
cp .env.example .env.local   # then fill in a real OPENAI_API_KEY
pnpm dev                     # starts https://localhost:3000 (self-signed cert)
```

The dev server runs with `--experimental-https` because microphone access (for the voice tutor) requires a secure context. Without an OpenAI key the app still works: the guide falls back to the baseline modules and the AI routes return 501.

Other scripts:

```bash
pnpm typecheck   # tsc --noEmit
pnpm lint        # eslint
pnpm format      # prettier
pnpm build       # production build (standalone output)
```

## Configuration

All settings come from environment variables — see [.env.example](.env.example) for the full annotated list:

| Variable | Purpose |
| --- | --- |
| `OPENAI_API_KEY` | Enables the adaptive guide and voice tutor |
| `OPENAI_*_MODEL`, `OPENAI_REALTIME_VOICE` | Model/voice overrides (sensible defaults) |
| `NEXT_PUBLIC_REALTIME_TEXT_INPUT` | `true` = type to the tutor instead of speaking |
| `SILAB_COMMUNICATION_MODE` | `api` (SILAB pushes state) or `tcp` (poll SILAB directly) |
| `SILAB_ADDR` | FS-SCENERY host:port, used in `tcp` mode |
| `SILAB_INGEST_SECRET` | Shared secret; must match `INGEST_SECRET` in SilabServer.java |
| `NEXT_PUBLIC_BASE_PATH` | Subpath the app is served under behind the reverse proxy |
| `TRIALS_PASSWORD` | Password for the `/trials` data viewer (fails closed if unset) |

## Deployment

The study server is too small to build on, so the app is built locally (`output: standalone`) and the finished bundle is rsynced to the server, where a systemd unit runs `node server.js` behind nginx under the `NEXT_PUBLIC_BASE_PATH` subpath. The deploy script (`scripts/deploy.sh`) is gitignored because it contains the personal deploy target; collected study data and the server's `app.env` are preserved across deploys.

## Repository layout

```
app/                  Next.js App Router pages (one folder per study step) + API routes
components/study/     Study UI: shell, provider, voice-tutor and SILAB hooks
components/ui/        shadcn/ui components
lib/                  Study flow, content, prompts, SILAB state, data types
silab_config/         SILAB scenario + SilabServer.java (state pusher)
backendGo/            Standalone TCP test client for the SILAB socket
prompt-tuning/        Offline prompt-tuning experiments for the guide adaptation
public/gifs/          Instructional GIFs referenced by guide modules and the tutor
data/sessions/        Collected participant records (gitignored)
```

Stack: Next.js 16 (App Router, Turbopack), React 19, TypeScript, Tailwind CSS 4, shadcn/ui.

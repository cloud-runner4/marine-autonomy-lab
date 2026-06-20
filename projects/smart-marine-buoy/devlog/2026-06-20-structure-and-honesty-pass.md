# 2026-06-20 - Structure alignment and honesty pass

Documentation-only session — no bench work. Brought this repo's structure into line with the
companion edge-ai-vibration-monitor project so the two read as one coherent body of work, and
started stripping the scaffold feel out of the docs.

## Changes
- Moved the devlog into a dated `devlog/` folder (this file plus the 2026-06-16 entry); the
  single-file `docs/devlog.md` is retired.
- Promoted the planning material out of the design board into committed markdown:
  `docs/technical-direction.md`, `docs/roadmap.md`, `docs/open-questions.md`,
  `docs/competency-matrix.md`. They render on GitHub and stand on their own.
- Added **Exit** and **Kill / pivot** criteria to each roadmap phase — what would tell me the
  approach is wrong, and what I'd do then. The Phase-1 noise-floor gate and the Phase-2
  hull-resonance check are the two that could genuinely sink the approach.
- Added a firmware skeleton (`firmware/platformio.ini`, `firmware/src/main.cpp`) — structure
  and TODOs only — and a `hardware/` folder for the enclosure and rig design files.

## Note to self
The repo still reads a little like a scaffold in places: placeholder READMEs, everything
stamped the same day, every ADR "Accepted" before a single measurement. The honest fix isn't
more prose — it's putting real results in. Phase 1 brings the first (the noise-floor PSD).

## Next
Unchanged: M1 — ESP32 + MPU6050 bring-up and the static noise-floor PSD. The synthetic-data
generator (`tools/`) can start in parallel without any hardware.

# 2026-06-19 - Design review and scope correction

**State:** still design / early build. No hardware bring-up yet. This was a documentation-only
session: a critical review of the scaffolded repo, then revisions. Recording it because the
devlog is meant to capture decisions and course-corrections, not just bench work.

## Why
The scaffold was sound but a critical read surfaced four real weaknesses worth fixing before any
build starts — better to correct the framing now than to let the documentation drift ahead of
what gets built.

## Changes made
- **Headline claim corrected (the important one).** The repo said it classifies "developing-fault"
  states. That over-claims: at the ADXL345's ~1600 Hz usable band, plain FFT band energies catch a
  *gross / seeded* defect but not genuinely *incipient* damage, whose tell-tale energy is in
  high-frequency resonance (envelope-analysis territory). Reframed throughout: the *goal* is
  developing-fault detection; v1 demonstrates *present*-fault classification, and early
  detection is a v2 target (needs envelope features + more bandwidth). README, technical-direction,
  ADR-0003 updated.
- **Pulled the differentiator forward.** The strongest, least-replicable thread — that the mount is
  part of the measurement — was sitting as a deferred open question while the commodity FFT+ML work
  was front-loaded. That inverts the advantage. Promoted it to **ADR-0009** and a **Phase-1
  deliverable**: a coupling sensitivity study and a mounting spec, done before the fault dataset.
  Added to the method and milestones; named as the headline in technical-direction and the README.
- **CWRU cross-check reframed.** CWRU is 12/48 kHz on a high-bandwidth sensor, so a like-for-like
  comparison would be misleading. Reframed as: down-sample CWRU into the v1 band and re-run the
  hand-built pipeline — validates the *pipeline*, not parity with CWRU-grade kit. (ADR-0004,
  open-question 3.)
- **Resolved a latent contradiction.** ADR-0003 said "hand-build the FFT"; `platformio.ini` listed
  `arduinoFFT`. Made the sequence explicit: hand-build first (the evidence of understanding),
  cross-check, then optionally use the library on-device purely for speed.
- **Per-class reporting.** Imbalance and looseness are trivially separable at this bandwidth, so
  headline accuracy will look high regardless. Committed to reporting **per-class** performance with
  bearing-class results called out separately (roadmap P2 exit, open-question 6).
- **Kill / pivot criteria** added to every roadmap phase — what result would falsify the approach
  and what to do then. Reads as engineering maturity for the research track.
- **Data schema** gained `mount_spec_id`, `mount_condition`, `sensor_location`, `temperature_c` and
  `timestamp` — mounting is now a logged variable, not a free-text note.
- Added a single-file HTML **working design board** (`docs/vibration-monitor-design-doc_master_19-06-26.html`),
  matching the companion buoy doc, as the at-a-glance decision/handoff surface.

## Decisions
- v1 claims present-fault classification, not incipient detection (ADR-0003).
- Mounting/coupling is a controlled variable and a Phase-1 deliverable (ADR-0009).
- Public-dataset cross-check is down-sampled into band; it validates the pipeline only (ADR-0004).

## Next
- Unchanged target: Phase 1 — accelerometer bring-up + calibration, hand-built FFT/feature
  pipeline, healthy baseline, then the coupling sensitivity study and mounting spec.

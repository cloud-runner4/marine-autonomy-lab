# 2026-06-18 - Project kickoff

**State:** design / early build. No hardware bring-up yet.

## Done today
- Stood up the repository and the documentation-first structure.
- Wrote the technical direction and the first eight ADRs (sensor, MCU, features, data strategy,
  on-device inference, custom PCB, sampling/windowing, calibration).
- Drafted the roadmap, open questions, competency matrix and BOM.
- Added a firmware skeleton (structure + TODOs) and placeholders for hardware and data.

## Decisions
- v1 on an **ESP32 dev board + ADXL345**, breadboard; custom PCB deferred to v2 to de-risk
  firmware and ML first (ADR-0002, ADR-0006).
- Labelled data via **fault induction** on a bench rig rather than waiting for real failures
  (ADR-0004).
- **On-device inference**, report the verdict not the waveform — matching the comms-denied
  subsea case this project is aimed at (ADR-0005).

## Known limitation logged
- ADXL345 usable bandwidth (~1600 Hz) may not reach all high-frequency bearing signatures;
  upgrade path recorded (ADR-0001 / ADR-0007). To be tested, not assumed.

## Next
- Phase 1: accelerometer bring-up + calibration, then the hand-built FFT/feature pipeline, then
  a clean healthy-state baseline on the rig.

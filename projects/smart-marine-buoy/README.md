# Smart Marine Buoy

**Low-power, on-device sea-state classification for bandwidth-constrained ocean platforms.**

A floating sensor node that classifies sea-state from its own motion and transmits the
**result, not the raw stream**. Where offshore telemetry is scarce and costly, a compact
classification beats streaming raw IMU data. The node runs a small ML model on an ESP32-class
MCU + MEMS IMU, classifies wave motion into sea-state bands, and sends a payload sized to fit a
single Iridium Short-Burst-Data frame. LoRa is the bench/coastal prototype for that satellite link.

## Status
**Design / early build — entering hardware bring-up (M1).** No hardware results yet. The repo
currently holds the design rationale, decision records, planned BOM and structure; build logs
and test data follow against the roadmap.

## Why this design
- **Synthetic training data, validated against real water.** Trained on motion synthesised from
  standard wave spectra (Pierson–Moskowitz / JONSWAP), then validated against a Welsh mooring
  buoy and public Waverider records. Hand-agitation was rejected as a spurious proxy.
  ([ADR-0002](docs/decisions/0002-synthetic-training-data.md))
- **The hull is part of the instrument.** A float filters wave motion before the IMU sees it, so
  the fabricated hull shapes the signal the model classifies — characterised in two steps (dry
  oscillation rig, wet free-decay), no wave tank.
  ([ADR-0005](docs/decisions/0005-characterisation-no-tank.md))
- **Sensor judged on the right axis** — low-frequency noise and bias, not output data rate.
  ([ADR-0001](docs/decisions/0001-imu-figure-of-merit.md))
- **Honest tooling** — Edge Impulse for deployment and quantisation; the spectral feature
  pipeline is hand-built. ([ADR-0003](docs/decisions/0003-handrolled-features-ei-deploy.md))

## Roadmap
Three phases, each with exit and kill/pivot criteria — see [`docs/roadmap.md`](docs/roadmap.md).
1. **Sensing & ML** — IMU bring-up + noise-floor PSD, synthetic dataset, hand-built features, on-device 3-class model.
2. **Characterisation** — oscillation rig (instrument response) and hull free-decay (natural frequency + damping).
3. **Integration & real water** — sealed hull, LoRa link closed, deployed, synthetic-to-real validation.

## Repository map
- [`docs/technical-direction.md`](docs/technical-direction.md) — objective, scope, method
- [`docs/roadmap.md`](docs/roadmap.md) — phased plan with exit / kill-pivot criteria
- [`docs/open-questions.md`](docs/open-questions.md) — live questions and how each resolves
- [`docs/competency-matrix.md`](docs/competency-matrix.md) — what the project evidences, honest levels
- [`docs/decisions/`](docs/decisions/) — decision records (ADRs)
- [`docs/bom.csv`](docs/bom.csv) — planned bill of materials with status
- [`docs/wiring/`](docs/wiring/) — pin assignment and wiring
- [`docs/photos/`](docs/photos/) — build photos
- [`devlog/`](devlog/) — dated, same-evening working notes
- [`firmware/`](firmware/) — ESP32 firmware (skeleton; built from M1)
- [`hardware/`](hardware/) — enclosure and rig design files (CERN-OHL-P v2)
- [`data/raw/`](data/raw/) · [`data/results/`](data/results/) — datasets and committed results
- [`tools/`](tools/) — host-side scripts (wave-spectrum generator, plotting)

## Positioning
Built by a fabrication and robotics technologist with a professional boatbuilding and marine
composites background, retraining into embedded systems and edge AI (part-time BEng in electronic
engineering; signal-processing module 2026/27). The marine-fabrication and deployment layer is the
part software-only work can't replicate; the embedded and ML layer is in active development.
See [`docs/competency-matrix.md`](docs/competency-matrix.md).

## Licence
- **Software / firmware:** MIT (see `LICENSE`)
- **Hardware design files:** CERN-OHL-P v2 (see `LICENSE-HARDWARE`)
- **Documentation:** © 2026 Jonathan Blake, reuse with attribution welcome

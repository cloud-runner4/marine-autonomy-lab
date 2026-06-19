# Smart Marine Buoy

**Low-power, on-device sea-state classification for bandwidth-constrained ocean platforms.**

A floating sensor node that classifies sea-state from its own motion and transmits the
**result, not the raw stream**. The governing constraint is the offshore-bandwidth problem:
where telemetry is scarce and costly, sending a compact classification beats streaming raw
IMU data. The node runs a small ML model on an ESP32-class MCU + MEMS IMU, classifies wave
motion into sea-state bins, and transmits a payload sized to fit a single Iridium
Short-Burst-Data frame. LoRa is the bench/coastal prototype for that satellite link.

## Status

**Design phase — entering hardware bring-up (M1).**
No hardware results yet. This repository currently holds the design rationale, decision
records, planned BOM, and project structure; build logs and test data follow against the
roadmap below. Documentation is treated here as a primary artefact, not an afterthought —
the reasoning is part of the deliverable.

## Why this design (the decisions that matter)

- **Synthetic training data, validated against real water.** The model trains on motion
  synthesised from standard wave spectra (Pierson–Moskowitz / JONSWAP), then is validated
  against a Welsh mooring buoy and public Waverider records. Hand-agitation was rejected as
  a spurious proxy. — [ADR-0002](docs/decisions/0002-synthetic-training-data.md)
- **The hull is part of the instrument.** A float filters wave motion before the IMU sees
  it, so the fabricated hull shapes the signal the model classifies. Characterised in two
  honest steps — a dry oscillation-rig instrument response and a wet free-decay hull test —
  neither needing a wave tank. — [ADR-0005](docs/decisions/0005-characterisation-no-tank.md)
- **Sensor judged on the right axis.** The IMU is chosen on low-frequency noise and bias
  stability, not output data rate. — [ADR-0001](docs/decisions/0001-imu-figure-of-merit.md)
- **Honest tooling.** Edge Impulse handles deployment and quantisation; the spectral feature
  pipeline is implemented by hand. — [ADR-0003](docs/decisions/0003-handrolled-features-ei-deploy.md)

Full reasoning, including superseded choices, lives in [`docs/decisions/`](docs/decisions/).

## Roadmap

- **M1** — Hardware on bench + IMU noise-floor PSD (settle the sensor question first)
- **M2** — Synthetic dataset from wave spectra + hand-rolled feature pipeline
- **M3** — Edge Impulse model on synthetic data (3-class; confusion matrix, model size)
- **M4** — Inference on device (latency/RAM) + six-position calibration
- **M5** — Oscillation rig + instrument transfer function (dry)
- **M6** — Hull build + free-decay test (wet): natural frequency + damping, second-order fit
- **M7** — End-to-end MVP: LoRa link closed in real water, validation data captured

Out of scope for v1: classical-DSP baseline benchmark (v2), solar/sleep optimisation,
satellite hardware (v2), hydrophone, multi-node mesh, federated learning.

## Repository map

- [`docs/devlog.md`](docs/devlog.md) — same-evening, append-only log of decisions and failures
- [`docs/decisions/`](docs/decisions/) — decision records (one per significant choice)
- [`docs/bom.csv`](docs/bom.csv) — planned bill of materials with status
- [`docs/wiring/`](docs/wiring/) — pin assignment and wiring diagrams
- [`docs/photos/`](docs/photos/) — build photos (fabrication foregrounded)
- [`data/raw/`](data/raw/) · [`data/results/`](data/results/) — datasets and committed results
- [`firmware/`](firmware/) — ESP32 firmware (from M1)
- [`tools/`](tools/) — host-side scripts (wave-spectrum generator, plotting)

## Positioning

Built by a fabrication and robotics technologist with a professional boatbuilding and marine
composites background, retraining into embedded systems and edge AI (part-time BEng in
electronic engineering; signal-processing module 2026/27). The marine-fabrication and
deployment layer is the part software-only work cannot replicate; the embedded and ML layer
is in active development and documented as it grows.

## Licence
- **Software / firmware:** MIT (see `LICENSE`)
- **Hardware design files:** CERN-OHL-P v2 (see `LICENSE-HARDWARE`)
- **Documentation:** © 2026 Jonathan Blake, reuse with attribution welcome

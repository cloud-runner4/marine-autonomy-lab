# Roadmap — Edge AI Vibration Monitor

Status keys: **planned** · **in progress** · **done**

Each phase has an **Exit** (what success looks like) and a **Kill / pivot** criterion (the result
that would say the current approach can't do the job, and what to do then). Recording the latter
is deliberate: a portfolio aimed partly at a research track should show what would falsify the
approach, not just what would confirm it.

## Phase 1 — Bench, sensor & coupling  (planned)
- ESP32 + ADXL345 bring-up; verify ODR, ranges, axes
- Per-axis calibration procedure (ADR-0008)
- Hand-built FFT + feature pipeline, cross-checked against a library implementation (ADR-0003)
- Capture healthy-state baseline across machine speeds
- **Coupling sensitivity study + mounting spec (ADR-0009)** — vary mount stiffness / contact /
  location against one fixed fault; commit the spectra; fix a repeatable mounting spec
- **Exit:** clean spectra and stable features from a known-good machine, *and* a documented
  mounting spec with evidence of how coupling moves the features
- **Kill / pivot:** if features are dominated by mounting variance rather than machine state even
  after the spec is fixed, the sensing chain isn't measuring what we need — revisit sensor
  location / fixture design (ADR-0009) before any ML work

## Phase 2 — Fault induction & dataset  (planned)
- Induce imbalance (eccentric mass), looseness (loosened mount), bearing defect (seeded bearing)
- Capture labelled recordings across speeds, all to the fixed mounting spec; document protocol
  (`data/README.md`)
- Train + validate classifier in Edge Impulse; quantise
- Cross-check by **down-sampling a public bearing dataset (e.g. CWRU) into the v1 band** and
  re-running the pipeline (ADR-0004) — validates the pipeline, not parity with CWRU-grade kit
- **Exit:** classifier separates the classes with documented **per-class** performance (confusion
  matrix), explicitly reporting bearing-class performance separately — imbalance/looseness are the
  easy classes; bearing is the discriminating test of the method
- **Kill / pivot:** if the bearing class can't be separated at v1 bandwidth (likely for *incipient*
  defects), that is itself a documented result — pull the ADR-0001 sensor upgrade and ADR-0003
  envelope analysis forward rather than overclaiming v1

## Phase 3 — Hardware  (planned)
- Custom PCB in KiCad: MCU + accelerometer + power + machine-mount sensor-head connector (ADR-0006)
- Fabricate via PCBWay; bring up board
- Sealed, machine-mountable enclosure realising the Phase-1 mounting spec (fabrication)
- On-device inference running from the board
- **Exit:** a self-contained unit that mounts to a machine and reports verdicts
- **Kill / pivot:** if board bring-up stalls beyond the time budget, fall back to a documented
  perfboard/carrier build so integration is still proven — the PCB is a learning goal, not a gate

## Phase 4 — Integration & validation  (planned)
- Continuous monitoring loop; thresholds / alerting; minimal opportunistic telemetry
- Validate against seeded faults; characterise false-positive / false-negative behaviour
- Commit results, plots and decision updates
- **Exit:** documented validation against known faults, with the present-vs-incipient boundary
  stated plainly
- **Kill / pivot:** if false-positive behaviour makes a verdict untrustworthy for an unattended
  platform, report the operating envelope where it *is* trustworthy rather than claiming general
  reliability

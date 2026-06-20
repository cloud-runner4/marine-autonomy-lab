# Technical Direction — Edge AI Vibration Monitor

**Status:** design / early build · **Owner:** Jonathan Blake · **Updated:** 2026-06-19

## 1. Objective
Detect faults in rotating marine machinery (motors, pumps, thrusters) from vibration,
**on-device**, and report a health verdict rather than raw data — so the capability survives on a
platform that is power-limited and effectively comms-denied (the subsea case).

**Honest scope.** The long-term *goal* is detecting *developing* (incipient) faults early. v1
proves the method end-to-end and detects **present, established faults** — including a *seeded*
(already-damaged) bearing. Genuinely *early* bearing detection relies on high-frequency resonance
energy (envelope/demodulation territory) above the v1 sensor's usable band, and is a v2 target,
not a v1 claim (ADR-0001, ADR-0003). The documentation must not let the claim drift ahead of this.

## 2. Scope
| | v1 (this cycle) | v2 (planned) |
|---|---|---|
| Sensor | ADXL345 MEMS accelerometer | wider-bandwidth / lower-noise device (see ADR-0001) |
| Platform | ESP32 dev board + breadboard | custom PCB (KiCad to PCBWay), sealed mountable head |
| Data | induced faults on a bench rig | + cross-check vs public/real bearing data |
| Output | verdict + confidence over serial/wireless on the bench | logged + opportunistic minimal telemetry |
| Goal | prove the method end-to-end | a deployable, sealed, machine-mountable unit |

v1 deliberately de-risks firmware, features and ML on a dev board **before** committing to a
custom board — the PCB work is the explicit learning goal of v2, not a prerequisite for v1.

## 3. Key design decisions
| # | Decision | Status | ADR |
|---|---|---|---|
| 1 | ADXL345 for v1, with a documented sensor upgrade path | Accepted | [0001](adr/0001-sensor-selection.md) |
| 2 | ESP32 microcontroller platform | Accepted | [0002](adr/0002-microcontroller-platform.md) |
| 3 | FFT / spectral features over raw time-series | Accepted | [0003](adr/0003-spectral-feature-pipeline.md) |
| 4 | Labelled data by physical fault induction | Accepted | [0004](adr/0004-fault-induction-data-strategy.md) |
| 5 | On-device inference; report the verdict, not the waveform | Accepted | [0005](adr/0005-on-device-inference-vs-raw-telemetry.md) |
| 6 | Custom PCB in KiCad (v2); breadboard for v1 | Proposed | [0006](adr/0006-custom-pcb-and-tooling.md) |
| 7 | Sampling rate and FFT windowing tied to fault frequencies | Proposed | [0007](adr/0007-sampling-and-windowing.md) |
| 8 | Per-axis accelerometer calibration, shared with the buoy | Proposed | [0008](adr/0008-accelerometer-calibration.md) |
| 9 | Mounting and mechanical coupling as a controlled variable | Proposed | [0009](adr/0009-mounting-and-coupling.md) |

## 4. Method
1. **Baseline.** Capture healthy-state vibration across machine speeds on the test rig.
2. **Mounting characterisation (pulled forward).** With one fixed fault present, vary the sensor
   mount — stiffness, contact area, location — and measure how the spectrum and features shift.
   Define a repeatable mounting interface and spec from the result (ADR-0009). This is the
   differentiating deliverable and is done early, not deferred.
3. **Fault induction.** Add eccentric mass (imbalance), loosen a mount (looseness), and fit a
   seeded/worn bearing (bearing defect); capture each, labelled, across speeds.
4. **Features.** Compute FFT band energies around characteristic fault frequencies (outer- and
   inner-race, ball, cage) plus broadband RMS and crest factor (see ADR-0003 / ADR-0007).
5. **Model.** Train a small classifier (healthy / imbalance / looseness / bearing) in Edge
   Impulse; quantise for on-device inference. Report **per-class** performance, not just headline
   accuracy: imbalance and looseness are easily separable at this bandwidth, so the bearing class
   is the real discriminating test of the method (see open questions).
6. **Report.** Emit verdict + confidence + timestamp; log locally; surface minimal data when a
   link exists.

## 5. Test rig and the headline thread
Small electric motor, shaft, a pillow-block bearing and an interchangeable bearing position,
on a rigid base with a controllable mount. The rig is itself a fabrication task.

**The headline — the mount is part of the measurement.** Mount stiffness, contact area and sensor
location change the measured spectrum for the *same* fault: the mounting interface is a filter
between the machine and the accelerometer. A fabrication background turns this from a nuisance
into a controllable variable — design a repeatable mounting interface, *measure* how coupling
moves the features, and define a mounting spec so a model transfers between machines. This is the
thread a software-only candidate cannot author, so it is foregrounded (method step 2, ADR-0009)
rather than left as an afterthought. It is the direct analogue of the companion buoy's hull
transfer-function thread.

## 6. Milestones
| Milestone | State |
|---|---|
| Repo + design records scaffolded | done (2026-06-18) |
| Accelerometer bring-up + calibration | planned |
| FFT / feature pipeline (hand-built) | planned |
| Healthy-baseline capture | planned |
| **Mounting / coupling sensitivity study + mounting spec** | planned |
| Fault-induced dataset | planned |
| Trained classifier + on-device inference (per-class results) | planned |
| Custom PCB (v2) | planned |
| Sealed enclosure + validation against seeded faults | planned |

## 7. Risks & open questions
See [open-questions.md](open-questions.md). The principal known limitation is sensor bandwidth
versus high-frequency bearing signatures (ADR-0001 / ADR-0007), handled by the v2 upgrade path.

## 8. Honest positioning
Established ground: marine fabrication/composites, production and delivery, hands-on
electromechanical and power work. In active development: firmware, on-device ML, PCB design,
signal processing (BEng in marine autonomy + this project). See
[competency-matrix.md](competency-matrix.md).

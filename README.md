# Edge AI Vibration Monitor

On-device machinery-health monitoring for power- and comms-constrained marine platforms.

> **Status — design / early build.** No field deployment yet. This repository is
> documentation-first: design decisions, methodology and roadmap are committed as the
> project is built, so the reasoning is visible alongside the hardware and code as they
> arrive. Commit history reflects a project that is genuinely new and openly in progress.

## What this is
A self-contained sensor that learns the vibration signature of rotating machinery (motors,
pumps, thrusters) and classifies its health state **on-device**, reporting a verdict and
confidence rather than raw waveforms.

**Honest scope of the claim.** The long-term *goal* is catching faults while they are still
*developing*. v1 is precise about what it actually proves: it classifies **present, established
fault states** — imbalance, looseness, and a *seeded* bearing defect — end-to-end on-device.
Detecting genuinely *incipient* bearing damage is a harder problem: the tell-tale energy lives in
high-frequency structural resonance (the basis of envelope/demodulation analysis) that sits
largely above the v1 sensor's usable band. That capability is a documented v2 target
([ADR-0001](docs/adr/0001-sensor-selection.md), [ADR-0003](docs/adr/0003-spectral-feature-pipeline.md)),
not a v1 result.

The governing constraint — limited power and near-zero live communications on an unattended
or submerged platform — is the same constraint that dominates subsea autonomy. A
long-endurance autonomous vehicle that cannot be serviced mid-mission and cannot stream data
ashore has to detect incipient machinery faults itself.

## Approach (in brief)
- **Hardware:** ESP32-class MCU + MEMS accelerometer (ADXL345 for v1; documented upgrade path — see [ADR-0001](docs/adr/0001-sensor-selection.md)).
- **Features:** FFT / spectral features targeting characteristic bearing-fault frequencies — physically motivated, not opaque ([ADR-0003](docs/adr/0003-spectral-feature-pipeline.md)).
- **Data:** labelled dataset built by *fault induction* on a test rig — controlled imbalance, looseness, seeded bearing defect — since real fault data is scarce ([ADR-0004](docs/adr/0004-fault-induction-data-strategy.md)).
- **Inference:** small quantised model (Edge Impulse for deployment); verdict + confidence reported, raw data logged locally ([ADR-0005](docs/adr/0005-on-device-inference-vs-raw-telemetry.md)).
- **Mounting as a controlled variable:** the sensor mount and its mechanical coupling are treated as part of the measurement chain, characterised early, not assumed away ([ADR-0009](docs/adr/0009-mounting-and-coupling.md)). This is the differentiating thread — see *the headline below*.
- **Hardware design:** this project is also the deliberate vehicle for learning PCB design (KiCad to PCBWay) ([ADR-0006](docs/adr/0006-custom-pcb-and-tooling.md)).

## The headline — what only this background can author
A vibration sensor is only as good as how it is bolted on. Mount stiffness, contact area and
sensor location change the measured spectrum for the *same* fault — the mount is a filter sitting
between the machine and the accelerometer. A fabrication background makes this a controllable
variable rather than a nuisance: design a repeatable mounting interface, *measure* how coupling
changes the features, and define a mounting spec so a model can transfer between machines. The
pure-software route stops at "feed the FFT to a classifier"; the edge that no software-only
candidate replicates is owning the mechanical coupling end-to-end. This is pulled forward into
Phase 1 deliberately (see [roadmap](docs/roadmap.md)).

## Honest positioning
- **Established ground:** professional marine fabrication and composites, production management, and hands-on electromechanical / power work (motors, drives, machine rebuilds).
- **In active development:** embedded firmware, on-device ML, PCB design and signal processing — underpinned by a part-time BEng in marine autonomy and projects like this one.

A fuller breakdown is in [docs/competency-matrix.md](docs/competency-matrix.md).

## Repository layout
| Path | Contents |
|---|---|
| `docs/technical-direction.md` | The living design document — objective, scope, decisions, milestones |
| `docs/vibration-monitor-design-doc_master_19-06-26.html` | Single-file working design board (decisions, headline, milestones, handoff) — open in a browser |
| `docs/adr/` | Architecture decision records (the design reasoning) |
| `docs/roadmap.md` | Phased plan and status |
| `docs/open-questions.md` | Live engineering questions |
| `docs/competency-matrix.md` | What this project evidences, honestly levelled |
| `docs/bom.md` | Bill of materials |
| `firmware/` | ESP32 firmware (skeleton; under development) |
| `hardware/` | PCB design (KiCad; to come) |
| `data/` | Dataset structure and the fault-induction protocol |
| `devlog/` | Dated development log |

## Roadmap (summary)
Bench & sensor -> fault induction & dataset -> custom hardware -> integration & validation.
Detail in [docs/roadmap.md](docs/roadmap.md).

## Companion project
Part of a two-project portfolio with the **Smart Marine Buoy** (sea-state classification from
platform motion, `marine-autonomy-lab`). The two share an accelerometer-calibration and
on-device-ML methodology; this project carries the high-frequency sensing and PCB-design
workload.

---
Jonathan Blake · jonny.s.blake@gmail.com

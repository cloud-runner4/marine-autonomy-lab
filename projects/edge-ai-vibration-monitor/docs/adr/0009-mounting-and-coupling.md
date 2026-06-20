# ADR-0009: Mounting and mechanical coupling as a controlled variable

- **Status:** Proposed (2026-06-19)
- **Context:** A vibration sensor measures the machine *through its mount*. Mount stiffness,
  contact area, preload and sensor location all shape the transmitted spectrum — they form a
  mechanical filter between the source and the accelerometer. This was previously logged only as
  an open question (mounting/coupling), which under-weights it: for this portfolio the mechanical
  coupling is the **differentiating** thread, the part a software-only candidate cannot author. It
  was at risk of being deferred behind firmware and ML; this ADR promotes it to a decision and a
  Phase-1 deliverable. It is the direct analogue of the companion buoy's hull transfer-function
  thread.
- **Decision:** Treat mounting and coupling as a **controlled, measured variable**, not a fixed
  assumption.
  1. Design a **repeatable mounting interface** for the sensor on the rig (a fabricated, defined
     fixture rather than ad-hoc tape/blu-tack).
  2. Run a **coupling sensitivity study early (Phase 1)**: with one fixed fault present, vary
     mount stiffness / contact area / location and record how the spectrum and extracted features
     move. Commit the plots.
  3. From the result, define a **mounting spec** (interface, torque, location, orientation) used
     for all subsequent captures, so that classifier features are reproducible and have a chance
     of transferring between machines.
- **Consequences:** Adds a deliberate study before the fault-induction dataset, and a commissioning
  constraint (every capture records its mount condition — see `data/labels.csv`). In return it
  produces a result almost no software portfolio holds, and it makes the later classifier honest:
  performance is reported against a *known* coupling rather than an uncontrolled one. Establishes
  that "the mount is part of the measurement" as a first-class engineering claim, not a footnote.
- **Alternatives considered:**
  - *Fix one mount and ignore the variable* — simplest, but discards the project's strongest,
    most differentiating result and hides a real source of model non-transfer. Rejected.
  - *Defer coupling work to the hardware phase (v2 enclosure)* — the original implicit plan;
    rejected because the study is cheap, possible now on the dev-board rig, and is the headline.
  - *Standardised stud-mount only (industrial accelerometer practice)* — informs the spec, but the
    MEMS module and learning goal call for a fabricated interface that is characterised, not just
    adopted by convention.

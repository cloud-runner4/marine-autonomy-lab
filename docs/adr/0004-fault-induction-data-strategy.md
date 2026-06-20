# ADR-0004: Fault-induction data strategy

- **Status:** Accepted (2026-06-18)
- **Context:** A supervised classifier needs labelled fault data. Real machinery-fault data is
  scarce and waiting for natural failures is impractical.
- **Decision:** Build a labelled dataset by **inducing controlled faults** on a test rig:
  mass **imbalance** (added eccentric mass), mechanical **looseness** (loosened mount), and a
  **bearing defect** (seeded or worn bearing) — captured across machine speeds, with a healthy
  baseline. Treat the gap between induced and naturally-occurring faults as an explicit,
  documented limitation.
- **Consequences:** Repeatable, safe and cleanly labelled. May not capture every real
  degradation mode; cross-checking against public bearing datasets and, later, any real records
  mitigates this. This mirrors the synthetic-to-real honesty of the companion buoy project.
- **On the public-dataset cross-check (important caveat).** The obvious reference, CWRU, is
  recorded at 12 kHz / 48 kHz with a high-bandwidth accelerometer — its detection performance
  leans on resonance energy well above this project's ~1600 Hz usable band (ADR-0001/0007). A
  naive "my device vs CWRU-grade detection" comparison would be apples-to-oranges and would
  flatter or unfairly damn this build. The honest, sharper use is to **down-sample CWRU into the
  v1 band and re-run the hand-built feature pipeline on it** — answering "which fault signatures
  survive at my bandwidth?" with data (directly addresses open-question on bandwidth). The
  cross-check validates the *pipeline*, it does not claim parity with CWRU-grade instrumentation.
- **Alternatives considered:**
  - *Public bearing datasets only* — useful for pipeline cross-check / pre-training, but recorded
    on different rigs, sensors and (much higher) bandwidths, so not specific to the target
    machines or this sensor mounting. Use down-sampled into the v1 band, as above.
  - *Wait for real failures* — impractical for a portfolio timeline.

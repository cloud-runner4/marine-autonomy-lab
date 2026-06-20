# ADR-0005: On-device inference vs raw telemetry

- **Status:** Accepted (2026-06-18)
- **Context:** Target platforms are power- and comms-constrained. A submerged UUV has effectively
  no live bandwidth and cannot stream vibration data ashore.
- **Decision:** Run **inference on-device** and emit only a **health verdict + confidence +
  timestamp** (optionally a compact spectral summary). Log locally; surface minimal data only
  when a link is available.
- **Consequences:** Matches subsea reality and minimises bandwidth and power. Raw data is not
  available for post-hoc analysis unless selective raw-capture-on-anomaly is added (see open
  questions) — a deliberate trade recorded here.
- **Alternatives considered:**
  - *Stream raw vibration* — infeasible subsea; rejected.
  - *Edge-summarise + opportunistic raw bursts on anomaly* — promising future option that keeps
    most of the bandwidth saving while retaining evidence of interesting events.

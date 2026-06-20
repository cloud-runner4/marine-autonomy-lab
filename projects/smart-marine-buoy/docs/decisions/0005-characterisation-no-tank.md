# ADR-0005: Two-part hull/instrument characterisation without a wave tank

- **Status:** Proposed (2026-06-16)
- **Context:** A floating hull's heave response (mass, waterplane area, damping) filters wave motion before the IMU sees it — so the hull is part of the instrument. No university wave-tank access is available.
- **Options considered:** (a) borrow tank time (not available); (b) skip characterisation (guts the centrepiece); (c) split into dry instrument characterisation + wet free-decay.
- **Decision:** Characterise in two separable steps:
  1. **Instrument transfer function (dry).** A self-built, stepper-driven oscillation rig applies known vertical sinusoids across 0.05–0.5 Hz; measure recovered gain and phase. The rig is itself a fabricated deliverable.
  2. **Hull response (wet).** A free-decay test in still water (displace a known amount, release, log) yields the hull's natural frequency and damping ratio, fitted to a second-order model — a classical naval-architecture method.
  A full forced-response hydrodynamic sweep is named as future work requiring a controlled wave facility.
- **Consequences:** Rigorous and achievable in-shop; the limitation is stated plainly and doubles as a fundable research line. Finding to look for: if the hull resonates inside 0.05–0.5 Hz it distorts the classified signal (a real result, and the correction worth demonstrating); if it sits above the band, the hull is a faithful follower. Still-water site availability constrains maximum hull size.
- **Revisit when:** wave-tank access becomes available (then run the forced sweep).

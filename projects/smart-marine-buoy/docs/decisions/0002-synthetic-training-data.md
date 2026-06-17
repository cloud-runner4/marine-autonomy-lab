# ADR-0002: Training data synthesised from standard wave spectra

- **Status:** Accepted (2026-06-16)
- **Context:** A sea-state classifier needs labelled motion data, but real sea-state data needs a deployed buoy (chicken-and-egg). The tempting shortcut — hand-agitation or a tilt table — produces broadband, unrepeatable motion roughly an order of magnitude above the wave band. A model trained on it learns shake intensity, not sea state: a spurious proxy that a reviewer spots immediately.
- **Options considered:** (a) hand/tilt bench motion; (b) synthesise from standard wave spectra; (c) wait for real deployment data.
- **Decision:** Generate training data by drawing target spectra per sea-state bin — Pierson–Moskowitz (fully-developed seas) and JONSWAP (fetch-limited) — and inverse-FFT-ing with random phase to produce physically grounded, perfectly labelled heave-acceleration series across 0.05–0.5 Hz. Validate the synthetic distributions against real water (a Welsh mooring buoy) and public wave-buoy (Waverider) records.
- **Consequences:** A reproducible, expandable dataset, and an honest, documented synthetic-to-real domain gap treated as a first-class research question. Requires implementing the spectral synthesis — which ties directly into the signal-processing study.
- **Revisit when:** real-water validation contradicts the synthetic distributions.

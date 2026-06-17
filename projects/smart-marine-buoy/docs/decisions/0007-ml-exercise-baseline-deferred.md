# ADR-0007: v1 is an applied edge-ML exercise; classical baseline deferred to v2

- **Status:** Accepted (2026-06-16)
- **Context:** A reviewer will reasonably ask why ML is used when sea-state can be estimated classically — significant wave height (Hs) from spectral moments, thresholded into bins.
- **Options considered:** (a) build the classical baseline first as the MVP gate; (b) frame v1 explicitly as an applied edge-ML exercise and defer the baseline to v2 as the comparison.
- **Decision:** Frame v1 as a deliberate applied edge-ML exercise; defer the classical-DSP baseline to v2, where ML is benchmarked against it. State this explicitly so the ML choice reads as intentional rather than ML-for-its-own-sake.
- **Consequences:** Keeps the MVP tight and pre-empts the "why not a spectral estimator" question without forcing the work now. The v2 benchmark becomes a strong, honest follow-up result either way it lands.
- **Revisit when:** the ML pipeline is validated (then build the baseline).

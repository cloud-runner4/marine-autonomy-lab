# ADR-0003: Spectral features by hand; Edge Impulse for deployment only

- **Status:** Accepted (2026-06-16)
- **Context:** If the whole ML pipeline is clicked together in a GUI, the work reads as "tool operator" rather than engineer — exactly the wrong signal for the target audience.
- **Options considered:** (a) Edge Impulse spectral block end-to-end; (b) implement feature extraction by hand, deploy via Edge Impulse; (c) fully bespoke firmware ML.
- **Decision:** Implement the spectral feature pipeline (windowing, FFT, band-power across the wave band) by hand and document it; use Edge Impulse for training, quantisation, EON tuning and the C++ export. Commit a comparison of raw time-series vs spectral features.
- **Consequences:** Demonstrates DSP understanding while keeping deployment tractable. Slightly more work than the GUI path.
- **Revisit when:** the feature comparison shows raw features are competitive (then simplify).

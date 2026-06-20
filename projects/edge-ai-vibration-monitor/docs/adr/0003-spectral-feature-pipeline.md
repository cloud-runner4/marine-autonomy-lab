# ADR-0003: Spectral feature pipeline

- **Status:** Accepted (2026-06-18)
- **Context:** The model must distinguish machine-health states. Imbalance, looseness and bearing
  faults have well-understood **frequency-domain** signatures.
- **Decision:** Use **FFT-based spectral features** — band energies around characteristic fault
  frequencies, plus broadband RMS and crest factor — rather than feeding raw time-series to the
  model. **Demonstrate the signal processing by hand** — a from-scratch FFT and feature
  extraction (Python for the offline pipeline; a clear C implementation for reference) committed
  and documented, so the DSP is understood, not hidden behind a tool. A vetted library
  (e.g. `arduinoFFT`) **may** then be used on-device purely for runtime performance — but only
  after the hand-built version exists and is shown to agree with it. The point of the hand-built
  pass is the evidence of understanding; the library, if used, is an optimisation, and the repo
  must make that sequence explicit so there is no "you said hand-built but imported a library" gap.
- **Consequences:** Features are physically interpretable and the model can be small. Requires
  correct sampling/windowing (ADR-0007) and knowledge of machine RPM to place fault-frequency
  bands. Fixed-speed assumption simplifies v1 (see open questions for variable speed). Adds a
  cross-check step (hand-built vs library output) but that check is itself a useful test artefact.
- **Alternatives considered:**
  - *Raw time-series into a CNN* — more data-hungry and opaque; rejected for v1.
  - *Envelope / demodulation analysis* — the standard technique for **early** bearing detection,
    because incipient defects show first as high-frequency structural *resonance* (well above the
    defect tones themselves). Plain FFT band energies at BPFO/BPFI/etc. will catch a **gross /
    seeded** defect but are weak for genuinely incipient damage — especially at the ADXL345's
    ~1600 Hz ceiling. This is why v1 claims *present*-fault detection, not early detection, and
    envelope analysis (with more bandwidth, ADR-0001) is the headline v2 enhancement.

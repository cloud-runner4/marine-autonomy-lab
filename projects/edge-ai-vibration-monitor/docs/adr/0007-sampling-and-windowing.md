# ADR-0007: Sampling and windowing

- **Status:** Proposed
- **Context:** FFT features require an adequate sample rate and window length for the fault
  frequencies of interest.
- **Decision:** Set the accelerometer ODR to capture the highest fault harmonic of interest with
  Nyquist margin (target 3200 Hz on ADXL345 -> ~1600 Hz usable). Choose an FFT window length that
  gives adequate frequency resolution at the **lowest** fault frequency, with overlap, and
  **document the RPM assumption** for each test machine.
- **Consequences:** Bounds detectable faults (links to ADR-0001) and sets a resolution/latency
  trade-off. Requires awareness of the digital sensor's internal anti-alias filtering.
- **Alternatives considered:**
  - *Higher-ODR sensor* — deferred to the v2 upgrade (ADR-0001).
  - *Order tracking with a tachometer* — better for variable-speed machines; a future enhancement.

# ADR-0001: Sensor selection

- **Status:** Accepted for v1 (2026-06-18); upgrade path Proposed
- **Context:** The project needs to capture vibration spectra from rotating machinery. Bearing
  fault signatures and their harmonics can extend into the low-kHz range. For v1 the priorities
  are low cost, a simple digital interface, and good documentation for a learning build.
- **Decision:** Use the **ADXL345** (+/-16 g, digital I2C/SPI, output data rate up to 3200 Hz)
  for v1 bench work. **Document an explicit upgrade path** to a wider-bandwidth / lower-noise
  device for v2 once bandwidth limits are characterised on real machines.
- **Consequences:** At 3200 Hz ODR the usable bandwidth is ~1600 Hz (Nyquist), which bounds the
  fault harmonics that can be resolved. Adequate for method development and many lower-speed
  machines, but it may miss high-frequency bearing signatures — hence the upgrade path
  (ADR-0007 quantifies the sampling implications). The ADXL345 is cheap and very
  well-documented; honest note: this is guided territory with many existing examples.
- **Alternatives considered:**
  - *MPU6050* — cheaper but noisier, lower ODR. Rejected.
  - *ADXL355* — lower noise, costlier, ODR ~4 kHz. Strong v2 candidate.
  - *Analog piezo accelerometer + external ADC* — best bandwidth/dynamic range, more analog
    electronics. A v2 candidate that pairs well with the custom-PCB work (ADR-0006).

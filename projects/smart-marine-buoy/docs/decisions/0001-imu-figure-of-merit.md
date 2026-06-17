# ADR-0001: IMU judged on low-frequency noise and bias, not ODR

- **Status:** Accepted (2026-06-16)
- **Context:** Wave sensing is sub-Hz (0.05–0.5 Hz). Peak heave accelerations are small — roughly 0.08 g at Hs ≈ 1 m, Tp ≈ 5 s, and single milli-g in calm seas. The intuitive reason to "upgrade" an IMU is output data rate (ODR), but ODR is irrelevant at the ~10–25 Hz sampling this needs.
- **Options considered:** (a) MPU6050 — cheap, widely supported; (b) LSM6DS3TR-C — FIFO, lower noise, wider temperature range; (c) higher-grade MEMS.
- **Decision:** Use the MPU6050 for v1, justified on the *correct* axis: sensors for this job are judged by low-frequency noise density (µg/√Hz) and bias stability, not ODR. Characterise the MPU6050's static noise floor at M1 (PSD of a stationary device) before building anything on it.
- **Consequences:** Avoids spending before the data justifies it and keeps the rationale defensible to an instrumentation audience. If the floor cannot resolve calm-sea heave, upgrade to the LSM6DS3TR-C — justified on noise/bias and recorded as a superseding ADR.
- **Revisit when:** the M1 noise-floor PSD is in hand.

# 2026-06-16 - Design phase: direction locked, entering M1

Project framing and the core technical decisions were settled in a focused design review
*before* any hardware work. Writing it down now is the point: decisions are far cheaper to
interrogate before parts are bought than after.

## What was decided (full reasoning in ../docs/decisions/)
- IMU judged on low-frequency noise density and bias stability, **not** ODR (ADR-0001).
  MPU6050 stays for v1 pending an M1 static-noise-floor PSD; LSM6DS3TR-C is the upgrade
  *only if* the floor can't resolve calm-sea heave (single milli-g territory).
- Training data **synthesised** from Pierson–Moskowitz / JONSWAP spectra, validated against
  real water (ADR-0002). Hand-agitation / tilt-table rejected — it trains on shake intensity,
  not sea state.
- Spectral features implemented **by hand**; Edge Impulse for deployment and quantisation
  only (ADR-0003).
- Transmit a **classification** sized to one Iridium SBD frame; LoRa is the coastal/bench
  prototype for a satellite link; comms is in the MVP, not deferred (ADR-0004).
- Hull characterisation **split** into a dry oscillation-rig instrument transfer function and
  a wet free-decay hull test; full forced-response sweep deferred, needs a tank (ADR-0005).
- Enclosure: PETG minimum, composite layup preferred (ADR-0006).
- v1 framed as an **applied edge-ML exercise**; classical Hs baseline deferred to v2 as the
  benchmark (ADR-0007).
- Competency split: buoy = marine / DSP / ML / comms; vibration monitor = PCB / high-freq /
  calibration (ADR-0008).

## Next (M1)
Wire ESP32 + MPU6050, stream raw accel over serial, and capture a static-device PSD to settle
the noise-floor question before building anything on top of the sensor.

## Risks I'm watching
1. Whether the MPU6050 noise floor is adequate — everything downstream depends on it.
2. Still-water access for a clean free-decay drop.
3. Holding the MVP tight — the LoRa link must close, but solar / sleep / hydrophone / mesh stay out.

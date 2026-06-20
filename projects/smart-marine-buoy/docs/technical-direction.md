# Technical Direction — Smart Marine Buoy

**Status:** design / early build · **Owner:** Jonathan Blake · **Updated:** 2026-06-20

## 1. Objective
A low-power floating node that classifies sea-state from its own motion **on-device** and
transmits the classification, not the raw stream — so the capability survives where telemetry
is scarce and costly (the offshore case).

**Honest scope.** v1 proves the method end-to-end on a dev board: three sea-state bands, trained
on synthetic data and validated against real water. It is deliberately an applied edge-ML
exercise; the classical baseline (significant wave height from spectral moments) is the v2
comparison, not a v1 claim (ADR-0007). The hull's heave response is measured, not assumed
(ADR-0005).

## 2. Scope
| | v1 (this cycle) | v2 (planned) |
|---|---|---|
| Sensor | MPU6050 MEMS IMU | LSM6DS3TR-C if the noise floor demands it (ADR-0001) |
| Platform | ESP32 dev board + breadboard | sealed, ballasted composite hull |
| Data | synthetic wave spectra, validated vs real water | + real-sea datasets, more classes |
| Comms | LoRa (coastal/bench), payload sized for one Iridium SBD frame | satellite link (Iridium SBD) |
| Output | class + confidence over LoRa / SD, bench and inshore | opportunistic satellite telemetry |
| Goal | prove the method end-to-end | a deployable, sealed, moored buoy |

## 3. Key design decisions
| # | Decision | ADR |
|---|---|---|
| 1 | IMU judged on low-frequency noise / bias, not ODR | [0001](decisions/0001-imu-figure-of-merit.md) |
| 2 | Training data synthesised from wave spectra, validated vs real water | [0002](decisions/0002-synthetic-training-data.md) |
| 3 | Spectral features by hand; Edge Impulse for deployment only | [0003](decisions/0003-handrolled-features-ei-deploy.md) |
| 4 | Transmit a classification sized to one satellite frame | [0004](decisions/0004-payload-satellite-frame.md) |
| 5 | Two-part hull/instrument characterisation, no wave tank | [0005](decisions/0005-characterisation-no-tank.md) |
| 6 | Enclosure: PETG minimum, composite layup preferred | [0006](decisions/0006-enclosure-material.md) |
| 7 | v1 is an applied edge-ML exercise; classical baseline in v2 | [0007](decisions/0007-ml-exercise-baseline-deferred.md) |
| 8 | Competency split across the two portfolio projects | [0008](decisions/0008-competency-split.md) |

## 4. Method
1. **IMU bring-up + noise floor (the gate).** Wire ESP32 + MPU6050; capture a static-device PSD
   to confirm it resolves calm-sea heave before building on it (ADR-0001).
2. **Synthetic dataset + features.** Generate labelled heave series from Pierson–Moskowitz /
   JONSWAP spectra (ADR-0002); hand-build the FFT / band-power pipeline, cross-checked against a
   library (ADR-0003).
3. **Model + calibration.** Train a 3-class model in Edge Impulse, quantise, run on-device;
   six-position IMU calibration.
4. **Instrument characterisation (dry).** Stepper-driven oscillation rig → gain/phase of the
   sensor+DSP chain across the wave band (ADR-0005).
5. **Hull characterisation (wet).** Free-decay test in still water → natural frequency + damping,
   second-order fit (ADR-0005). Forced-response sweep deferred (needs a tank).
6. **Real water.** Deploy on the Dart / at Cardigan; close the LoRa link end-to-end; capture data
   for the synthetic-to-real comparison.

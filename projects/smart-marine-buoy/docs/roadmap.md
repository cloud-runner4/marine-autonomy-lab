# Roadmap — Smart Marine Buoy

Status keys: **planned** · **in progress** · **done**

Each phase has an **Exit** (what success looks like) and a **Kill / pivot** criterion (the result
to say the approach can't do the job, and what to do then).

## Phase 1 — Sensing & ML  (in progress)
- ESP32 + MPU6050 bring-up; verify range, ODR, axes
- **Static noise-floor PSD** — confirm the sensor resolves calm-sea heave (ADR-0001)
- Synthetic dataset from Pierson–Moskowitz / JONSWAP spectra (ADR-0002)
- Hand-built FFT + band-power pipeline, cross-checked against a library (ADR-0003)
- 3-class model in Edge Impulse; quantise; run on-device; six-position calibration
- **Exit:** model separates calm/moderate/rough on synthetic+validated data, running on-device
  with logged RAM/latency
- **Kill / pivot:** if the MPU6050 noise floor can't resolve calm-sea heave (single milli-g)
  after calibration, the sensing chain can't see the signal — pull the ADR-0001 LSM6DS upgrade
  *before* any more ML work, rather than training on noise

## Phase 2 — Characterisation  (planned)
- Build a stepper-driven oscillation rig; measure the instrument transfer function (dry)
- Build the hull; free-decay test in still water → natural frequency + damping, second-order fit
- **Exit:** a measured instrument response across the wave band, and a measured hull natural
  frequency + damping ratio
- **Kill / pivot:** if the hull's natural frequency sits inside 0.05–0.5 Hz and dominates the
  response, the hull is distorting the signal it's meant to measure — revisit geometry / ballast
  before deployment; don't paper the resonance over in software

## Phase 3 — Integration & real water  (planned)
- Seal the hull (IP gland, potting, ballast, mooring); close the LoRa link end-to-end
- Deploy on the Dart / at Cardigan; capture real-water data for the synthetic-to-real comparison
- **Exit:** one full classification cycle in real water, transmitted as an SBD-sized payload;
  real-water dataset captured
- **Kill / pivot:** if a synthetic-trained model collapses on real water (large domain gap),
  that is itself the documented research result — retrain on a synthetic+real mix and report the
  gap, rather than claiming v1 generalises

## Out of scope for v1
Classical-DSP baseline benchmark (v2), solar / sleep optimisation, satellite hardware (v2),
hydrophone, multi-node mesh, federated learning.

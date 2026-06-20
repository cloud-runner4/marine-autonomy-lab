# Data — vibration recordings & dataset

> **Status:** structure only; recordings to follow in Phases 1-2. Bulk raw recordings are
> **not** committed (see `.gitignore`); the protocol, labels and processed features are.

## Layout
```
data/
  raw/         # raw recordings (git-ignored; kept locally / external storage)
  processed/   # windowed feature sets used for training
  labels.csv   # recording id -> class, machine, speed, mount condition, bearing id, notes
```

## Fault-induction protocol (summary — see ADR-0004)
For each machine speed, capture:
- **healthy** — known-good bearing, tight mount, no added mass
- **imbalance** — calibrated eccentric mass added
- **looseness** — mount fasteners deliberately loosened to a recorded torque
- **bearing** — seeded/worn bearing fitted

Record sensor mounting location and orientation each time — the mount is part of the measurement
(ADR-0009), so it is a logged field, not a free-text aside. Capture all fault classes against the
fixed Phase-1 mounting spec. Note RPM, ODR and ambient temperature (MEMS bias/noise drift with
temperature). Keep a healthy baseline before and after each fault run to catch rig drift.

## Labelling
`labels.csv` columns (provisional):
`recording_id, timestamp, class, machine, rpm, mount_spec_id, mount_condition, sensor_location,
bearing_id, odr_hz, window, temperature_c, notes`

- `mount_spec_id` — which mounting spec/fixture (ADR-0009) this recording used
- `mount_condition` — tight / loosened-to-torque, etc.
- `sensor_location` / orientation — where on the rig the accelerometer sat
- `temperature_c` — ambient at capture, for drift analysis (ADR-0008)

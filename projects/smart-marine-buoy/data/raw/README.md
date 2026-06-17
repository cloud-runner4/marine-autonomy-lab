# Raw data

Per-session CSV captures, newest committed as they are produced:

- **Synthetic** — heave-acceleration series generated from wave spectra (ADR-0002),
  one labelled file per sea-state bin, plus the generator parameters.
- **Real water** — IMU sessions from the Dart (canoe) and the Welsh mooring buoy,
  with deployment notes (date, location, conditions). Kept separate from synthetic.

Each file: timestamp, ax, ay, az (and gyro if logged), plus a header noting sample
rate, sensor, calibration state, and source.

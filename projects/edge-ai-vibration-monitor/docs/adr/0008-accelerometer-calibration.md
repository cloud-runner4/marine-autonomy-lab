# ADR-0008: Accelerometer calibration

- **Status:** Proposed
- **Context:** Offset, scale and axis-sensitivity errors affect features and cross-unit
  consistency. This is a shared concern with the companion buoy IMU.
- **Decision:** Apply **per-axis offset and scale calibration** from known static orientations,
  document the procedure, and **reuse the calibration methodology across both portfolio
  projects**.
- **Consequences:** Improves consistency between units and over time; adds a bench step to
  commissioning. Sufficient for v1; full dynamic calibration is out of scope for now.
- **Alternatives considered:**
  - *Factory defaults only* — less consistent between units; rejected.
  - *Full dynamic / temperature calibration* — overkill at this stage; revisit if drift matters.

# Hardware — planned

> **Status:** not started. Enclosure CAD and the characterisation-rig design will be committed
> here as they are built (see [../docs/roadmap.md](../docs/roadmap.md)).

## Intended scope
- **Hull / enclosure** — Fusion 360 model. PETG print is the minimum; a composite layup
  (printed plug → glass/epoxy) is preferred (ADR-0006). IP-rated gland, potted penetrations,
  ballast, mooring eye. Geometry is signal-shaping, not cosmetic (ADR-0005).
- **Oscillation rig** — stepper-driven scotch-yoke for the dry instrument-response measurement
  (ADR-0005).

## To be added
```
hardware/
  enclosure/        # Fusion 360 source + STEP / STL exports
  rig/              # oscillation-rig CAD + drive notes
```
Honest note: marine fabrication is established ground; the embedded/PCB side is carried by the
vibration-monitor project (ADR-0008). Licensed CERN-OHL-P v2 (see ../LICENSE-HARDWARE) — add an
SPDX header to each design file as it lands.

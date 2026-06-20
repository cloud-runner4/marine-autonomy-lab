# Hardware (PCB) — planned

> **Status:** not started. KiCad project files will be committed here during Phase 3
> (see [../docs/roadmap.md](../docs/roadmap.md) and [../docs/adr/0006-custom-pcb-and-tooling.md](../docs/adr/0006-custom-pcb-and-tooling.md)).

## Intended scope (v2)
- ESP32 module + ADXL345 (or upgraded accelerometer per ADR-0001)
- Power: regulation suitable for a duty-cycled, power-constrained node
- Connector for a **machine-mounted sensor head** so the board sits away from the vibration source
- Designed for a **sealed, machine-mountable enclosure** (the mounting is part of the measurement)
- Fabrication via PCBWay

## To be added
```
hardware/
  vibration-monitor.kicad_pro
  vibration-monitor.kicad_sch
  vibration-monitor.kicad_pcb
  gerbers/         # fabrication outputs
  bom.csv          # board BOM (links to ../docs/bom.md)
```
Honest note: PCB design is a deliberate learning goal of this project, not existing capability.

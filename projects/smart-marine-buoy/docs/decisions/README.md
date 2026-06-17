# Decision records (ADRs)

One file per significant decision. Each records the reasoning at the time, so a
choice can be interrogated — and, where superseded, traced — rather than silently
reversed.

Format: Status · Context · Options considered · Decision · Consequences · Revisit when.

| ADR | Decision |
|-----|----------|
| 0001 | IMU judged on low-frequency noise / bias, not ODR |
| 0002 | Training data synthesised from standard wave spectra, validated against real water |
| 0003 | Spectral features implemented by hand; Edge Impulse for deployment only |
| 0004 | Transmit a classification sized to one satellite frame; LoRa as prototype |
| 0005 | Two-part hull/instrument characterisation, no wave tank |
| 0006 | Enclosure: PETG minimum, composite layup preferred |
| 0007 | v1 is an applied edge-ML exercise; classical baseline deferred to v2 |
| 0008 | Competency split across the two portfolio projects |

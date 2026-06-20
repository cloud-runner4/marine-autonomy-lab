# ADR-0006: Enclosure — PETG minimum, composite layup preferred

- **Status:** Proposed (2026-06-16)
- **Context:** The hull must survive seawater and UV and stay watertight. PLA is hygroscopic, UV-degrading, and porous along layer lines — poor in seawater.
- **Options considered:** (a) PLA (reject); (b) PETG print; (c) printed plug → composite layup.
- **Decision:** PETG is the FDM minimum. The preferred route — leveraging the boatbuilding/composites background — is a 3D-printed plug taken to a laid-up composite hull: more durable, and a stronger demonstration of ground that software-only work cannot replicate. Pot PCB penetrations; IP-rated gland; ballast; mooring point.
- **Consequences:** More fabrication effort for the composite route, in exchange for survivability and portfolio value. Hull geometry is treated as signal-shaping (see ADR-0005), not cosmetic.
- **Revisit when:** float/decay tests indicate geometry changes.

# ADR-0006: Custom PCB and tooling

- **Status:** Proposed
- **Context:** v1 runs on a dev board plus breadboard. This project is also the **deliberate
  vehicle for learning PCB design** within the portfolio.
- **Decision:** Design a **custom PCB in KiCad** (MCU + accelerometer + power + a connector for a
  machine-mounted sensor head) and fabricate via **PCBWay** for **v2**. Keep v1 on a dev board
  to de-risk firmware and ML first.
- **Consequences:** Sequences the learning sensibly (firmware/ML before hardware). A custom board
  enables a sealed, mountable form factor suited to deployment. Honest note: PCB design is **new**
  to me — this ADR records the intent and the learning path, not an existing capability.
- **Alternatives considered:**
  - *Perfboard* — quicker, but less of the intended learning and no clean mountable form.
  - *Off-the-shelf carrier board* — faster, but bypasses the PCB-design goal.

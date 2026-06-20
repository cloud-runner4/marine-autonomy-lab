# ADR-0002: Microcontroller platform

- **Status:** Accepted (2026-06-18)
- **Context:** The device must buffer samples, run an FFT and a small ML model on-device, and be
  convenient to develop on the bench. Edge Impulse deployment support is desirable.
- **Decision:** Use the **ESP32** (dual-core, hardware FP, sufficient RAM for FFT buffers, wide
  tooling and Edge Impulse support, on-board wireless for bench telemetry during development).
- **Consequences:** Ample headroom for v1. Power is not yet optimised — the subsea power budget
  is addressed in the hardware phase, not now. Wireless is useful on the bench but is **not**
  representative of submerged operation (where there is effectively no live link — see ADR-0005).
- **Alternatives considered:**
  - *RP2040 / Pico* — cheaper, no FPU or wireless; possible for a cost-down v2 node.
  - *STM32* — capable but more setup overhead for this stage; revisit if power/latency demands it.

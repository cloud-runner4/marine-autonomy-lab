# ADR-0008: Competency split across the two portfolio projects

- **Status:** Accepted (2026-06-16)
- **Context:** Two projects run in parallel — this buoy and an edge-AI vibration monitor. One project trying to evidence every competency does each of them poorly.
- **Options considered:** (a) load everything onto the buoy; (b) divide the competency load across the two.
- **Decision:** The buoy carries marine deployment/fabrication, low-frequency DSP, on-device ML, and wireless comms. The vibration monitor carries PCB-level design, high-frequency vibration sensing, and the heaviest calibration work. PCB work is therefore minimised on the buoy (dev-board + at most a simple breakout); calibration discipline is shared (six-position static calibration on both).
- **Consequences:** Each project does ~3–4 competencies well. The buoy stays focused; PCB credibility is established on the monitor.
- **Revisit when:** project scope changes.

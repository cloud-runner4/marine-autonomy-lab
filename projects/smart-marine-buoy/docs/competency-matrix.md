# Competency matrix

What this project is intended to evidence, with an honest current level. Levels:
**established** (professional track record) · **developing** (hands-on, guided, improving) ·
**new** (deliberately learning here).

| Competency | How this project evidences it | Current level |
|---|---|---|
| Marine fabrication & deployment | Sealed composite hull, ballast, mooring, real-water deployment | established |
| Low-frequency DSP | Hand-built FFT / PSD / band-power on heave data (not tool-hidden) | developing |
| On-device ML | Edge Impulse model on synthetic+validated data, quantised, on ESP32 | developing |
| Wireless comms | LoRa link; payload sized for an Iridium SBD frame | developing |
| Sensor integration & calibration | IMU interfacing, six-position calibration, noise-floor characterisation | established (hands-on) / developing (this context) |
| Buoy hydrodynamics | Hull heave response measured and corrected for | developing / new |
| Documentation & decision records | This repo: ADRs, devlog, technical direction | established practice |

The differentiating layer is the marine-fabrication row applied to genuinely **developing**
embedded and DSP work. The sharpest single expression of that edge is owning the **hull as
instrument** (ADR-0005): the fabricated hull shapes the signal, and characterising then
correcting for it is a result a software-only portfolio cannot produce. This project and the
edge-ai-vibration-monitor split the competency load (ADR-0008) — the vibration monitor carries
the PCB and high-frequency work.

# Competency matrix

What this project is intended to evidence, with an honest current level. Levels:
**established** (professional track record) · **developing** (hands-on, guided, improving) ·
**new** (deliberately learning here).

| Competency | How this project evidences it | Current level |
|---|---|---|
| Embedded firmware | ESP32 sampling, buffering, FFT, inference loop | developing |
| On-device ML | Edge Impulse model trained on induced-fault data, quantised | developing |
| Signal processing | Hand-built FFT + fault-frequency features (not tool-hidden) | developing |
| Sensor integration | Accelerometer interfacing, calibration, mounting | established (hands-on) / developing (this context) |
| PCB design | Custom board in KiCad, fabricated via PCBWay (v2) | new (learning goal) |
| Marine fabrication & sealing | Test rig + sealed, machine-mountable enclosure | established |
| Test methodology | Fault-induction protocol, labelled dataset, validation | developing |
| Documentation & decision records | This repo: ADRs, devlog, technical direction | established practice |

The differentiating layer is the **established** rows — fabrication, electromechanical and
delivery experience that software-only candidates rarely have — applied to genuinely
**developing** embedded/ML work. The sharpest single expression of that edge is owning the
**mechanical coupling**: the mount is part of the measurement (ADR-0009), and characterising it
is a result a pure-software portfolio cannot produce.

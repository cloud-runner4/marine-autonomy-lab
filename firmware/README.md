# Firmware (ESP32) — SKELETON

> **Status:** skeleton only. Structure and intent are defined; the implementation is in
> progress. Files here compile as stubs with `// TODO` markers — they do **not** yet perform
> real sensing or inference.

## Intended architecture
- **Acquire:** read the accelerometer at a fixed ODR into a ring buffer (ADR-0001, ADR-0002).
- **Window:** assemble overlapping windows for analysis (ADR-0007).
- **Features:** FFT -> band energies at fault frequencies + RMS / crest factor (ADR-0003).
- **Infer:** run the quantised Edge Impulse model -> {healthy, imbalance, looseness, bearing}.
- **Report:** emit verdict + confidence + timestamp; log locally; minimal opportunistic
  telemetry (ADR-0005).

## Build (planned)
[PlatformIO](https://platformio.org/):
```
pio run                 # build
pio run -t upload       # flash an ESP32 dev board
pio device monitor      # serial output
```

## Layout
```
firmware/
  platformio.ini
  src/
    main.cpp            # skeleton entry point (sample -> feature -> infer -> report)
```

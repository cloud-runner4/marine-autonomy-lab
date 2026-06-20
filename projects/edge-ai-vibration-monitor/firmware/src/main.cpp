// Edge AI Vibration Monitor - firmware SKELETON (NOT YET IMPLEMENTED)
// ---------------------------------------------------------------------------
// This file defines the intended structure only. Every stage is a TODO.
// See ../README.md and ../../docs/technical-direction.md for the design.
// Decisions: ADR-0001 (sensor), 0002 (MCU), 0003 (features), 0005 (reporting),
//            0007 (sampling/windowing), 0008 (calibration).
// ---------------------------------------------------------------------------
#include <Arduino.h>

// --- Configuration (provisional; see ADR-0007) ---
static const uint16_t SAMPLE_RATE_HZ = 3200;  // accelerometer ODR target
static const uint16_t FFT_WINDOW     = 1024;  // window length (TBD)

void setupSensor() {
  // TODO: init ADXL345 over I2C/SPI; set range and ODR (ADR-0001)
  // TODO: apply per-axis calibration offsets/scales (ADR-0008)
}

void acquireWindow(float* buffer, uint16_t n) {
  // TODO: fill 'buffer' with n samples at SAMPLE_RATE_HZ from a ring buffer
  (void)buffer; (void)n;
}

void computeFeatures(const float* buffer, uint16_t n, float* features) {
  // TODO: FFT -> band energies at characteristic fault frequencies + RMS/crest (ADR-0003)
  (void)buffer; (void)n; (void)features;
}

int runInference(const float* features) {
  // TODO: run quantised Edge Impulse model -> class index
  // classes: 0 healthy, 1 imbalance, 2 looseness, 3 bearing
  (void)features;
  return -1;  // not implemented
}

void report(int verdict, float confidence) {
  // TODO: emit verdict + confidence + timestamp; log locally; minimal telemetry (ADR-0005)
  (void)verdict; (void)confidence;
}

void setup() {
  Serial.begin(115200);
  Serial.println(F("Edge AI Vibration Monitor - SKELETON build. Not yet implemented."));
  setupSensor();
}

void loop() {
  // Intended pipeline: acquire -> features -> infer -> report -> sleep/duty-cycle
  // TODO: implement. Placeholder delay so the skeleton does nothing harmful.
  delay(1000);
}

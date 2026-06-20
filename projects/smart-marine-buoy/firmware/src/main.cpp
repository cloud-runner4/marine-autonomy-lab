// Smart Marine Buoy - firmware SKELETON (NOT YET IMPLEMENTED)
// ---------------------------------------------------------------------------
// Structure only; every stage is a TODO. See ../README.md and
// ../../docs/technical-direction.md for the design.
// Decisions: ADR-0001 (sensor), 0003 (features), 0004 (payload/comms).
// ---------------------------------------------------------------------------
#include <Arduino.h>

// Provisional; see docs/open-questions.md Q1 (to be swept).
static const uint16_t SAMPLE_RATE_HZ = 25;   // waves are sub-Hz; clears Nyquist easily
static const uint32_t WINDOW_SECONDS = 60;   // tens of seconds for sub-0.1 Hz resolution

void setupSensor() {
  // TODO: init MPU6050 over I2C; set range/ODR; remove the 1g gravity DC term (ADR-0001)
  // TODO: apply six-position calibration offsets/scales
}

void acquireWindow(float* buffer, uint32_t n) {
  // TODO: fill 'buffer' with n heave-axis samples at SAMPLE_RATE_HZ from a ring buffer
  (void)buffer; (void)n;
}

void computeFeatures(const float* buffer, uint32_t n, float* features) {
  // TODO: Hann window -> FFT -> band power across 0.05-0.5 Hz (ADR-0003)
  (void)buffer; (void)n; (void)features;
}

int runInference(const float* features) {
  // TODO: quantised Edge Impulse model -> class index: 0 calm, 1 moderate, 2 rough
  (void)features; return -1;
}

void packAndSend(int cls, float confidence) {
  // TODO: pack class + confidence + timestamp <= one Iridium SBD frame (ADR-0004)
  // TODO: transmit over LoRa (RFM95); fall back to SD log
  (void)cls; (void)confidence;
}

void setup() {
  Serial.begin(115200);
  setupSensor();
}

void loop() {
  // TODO: acquireWindow -> computeFeatures -> runInference -> packAndSend
  // then deep-sleep until the next window to hold the power budget
}

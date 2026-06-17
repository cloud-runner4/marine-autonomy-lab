# Firmware

ESP32 firmware (Arduino or ESP-IDF). Structure to follow at M1:
sensor read → windowing → hand-rolled spectral features → Edge Impulse inference →
payload pack (≤ one Iridium SBD frame) → LoRa transmit / SD log.

_No source committed yet — bring-up begins at M1._

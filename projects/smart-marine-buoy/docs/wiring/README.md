# Wiring

Hand-drawn diagrams photographed here are acceptable early; a Fritzing/KiCad
version is the upgrade. At minimum the pin assignment lives in the table below
and is kept current.

## Provisional pin plan (ESP32) — to be confirmed at bring-up

| Function | Bus | Signal | ESP32 pin |
|----------|-----|--------|-----------|
| MPU6050  | I2C | SDA    | GPIO21 |
| MPU6050  | I2C | SCL    | GPIO22 |
| MPU6050  | I2C | INT (opt) | GPIO4 |
| Shared SPI | SPI | SCK  | GPIO18 |
| Shared SPI | SPI | MISO | GPIO19 |
| Shared SPI | SPI | MOSI | GPIO23 |
| RFM95    | SPI | CS     | GPIO5  |
| RFM95    | SPI | RST    | GPIO14 |
| RFM95    | SPI | DIO0   | GPIO26 |
| microSD  | SPI | CS     | GPIO15 |
| Status   | —   | LED    | GPIO2  |

_Provisional. Pins move at M1 if conflicts appear (strapping pins, ADC2/WiFi clashes)._

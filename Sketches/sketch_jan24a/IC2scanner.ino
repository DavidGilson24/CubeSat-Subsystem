#include <Wire.h>

void I2Cscan() {
  Serial.println("\nScanning for I2C devices...");

  Wire.begin();
  bool deviceFound = false;

  for (uint8_t address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found I2C device at 0x");
      Serial.println(address, HEX);
      deviceFound = true;
    }
  }

  if (!deviceFound) {
    Serial.println("No I2C devices found! Check wiring.");
  }

  Serial.println("I2C Scan Complete.");
  Serial.println("--------------------------------");
}

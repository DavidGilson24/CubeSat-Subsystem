#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;  // BMP280 sensor object

void BMPsetup() {
  if (!bmp.begin(0x76)) {  // 0x76 or 0x77 depending on your module
    Serial.println("ERROR: BMP280 not found. Check wiring!");
    while (1);
  }
  Serial.println("BMP280 initialized successfully!");
}

void BMPloop() {
  Serial.println("\nBMP280 Sensor Data:");

  Serial.print("Temperature: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" °C");

  Serial.print("Pressure: ");
  Serial.print(bmp.readPressure() / 100.0F);  // Convert Pa to hPa
  Serial.println(" hPa");

  Serial.print("Approx. Altitude: ");
  Serial.print(bmp.readAltitude(1013.25));  // Sea level pressure as reference
  Serial.println(" m");
}


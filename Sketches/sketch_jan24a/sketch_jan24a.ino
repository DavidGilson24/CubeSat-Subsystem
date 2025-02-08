#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <QMC5883LCompass.h>
#include <RTClib.h>
#include <MPU6050.h>

// Function declarations
void BMPsetup();
void BMPloop();
void MPUsetup();
void MPUloop();
void DS3231setup();
void DS3231loop();
void I2Cscan();  // Now we can call the I2C scanner anytime

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing sensors...");

  I2Cscan();  // Run I2C scanner first to verify connections

  MPUsetup();  // Initialize MPU6050
  // BMPsetup();  // Initialize BMP280
  DS3231setup();  // Uncomment to enable RTC
  QMCsetup();  // Uncomment to enable Magnetometer

  Serial.println("All sensors initialized successfully!");
}

void loop() {
  MPUloop();  // Read MPU6050 sensor data
  // BMPloop();  // Read BMP280 sensor data
  DS3231loop();  // Uncomment if using RTC
  QMCloop();  // Uncomment if using Magnetometer

  Serial.println("-------------------------");
  delay(2000);
}




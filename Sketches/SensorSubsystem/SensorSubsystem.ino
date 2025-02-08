/*
  SensorSubsystem.ino (Main)
  - Responsible for overall workflow:
    - Initializes all sensors (by calling initializeX() from other .ino files)
    - Periodically calls the getXReport() functions to gather interpretive sensor data
    - Prints the outputs
*/

#include <Arduino.h>
#include <Wire.h>  // Common for I2C

// Forward declarations from other files:
void initializeBME();
String getBMEReport();

void initializeMPU();
String getMPUReport();

void initializeQMC();
String getQMCReport();

void initializeDSClock();
String getDSClockReport();

// ----------------------------------------------------------------------------------

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println(F("Initializing Sensor Subsystem..."));

  initializeBME();
  initializeMPU();
  initializeQMC();
  initializeDSClock();

  Serial.println(F("All sensors initialized successfully!"));
  Serial.println(F("---------------------------------------"));
}

void loop() {
  Serial.println(F("=== Sensor Data Report ==="));

  //BME report
  Serial.println(getBMEReport());

  //MPU report
  Serial.println(getMPUReport());

  //report
  Serial.println(getQMCReport());

  //DS clock report
  Serial.println(getDSClockReport());

  Serial.println(F("---------------------------------------"));
  delay(5000); 
}


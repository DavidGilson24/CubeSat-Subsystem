#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <QMC5883LCompass.h>
#include <RTClib.h>
#include <MPU6050.h>

// Function declarations
void BMEsetup();
void BMEloop();
void MPUsetup();
void MPUloop();
void DS3231setup();
void DS3231loop();
void I2Cscan();  

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing sensors...");

  I2Cscan();  

  MPUsetup();  
  BMEsetup();  
  DS3231setup();  
  QMCsetup(); 

  Serial.println("All sensors initialized successfully!");
}

void loop() {
  MPUloop();
  Serial.println("-------------------------");  
  BMEloop();
  Serial.println("-------------------------"); 
  DS3231loop();
  Serial.println("-------------------------");   
  QMCloop(); 

  Serial.println("<<<<<<<<------------------------->>>>>>>>");
  delay(5000);
}




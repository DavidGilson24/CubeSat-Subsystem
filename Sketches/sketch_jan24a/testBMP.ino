#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

#define SEALEVELPRESSURE_HPA (1013.25)

void BMEsetup() {
  Serial.begin(9600);

  bool status = bme.begin(0x76);
  if (!status) {
    Serial.println(F("Could not find a valid BME280 sensor! Check wiring or I2C address."));
    while (1);
  }
  Serial.println(F("BME280 sensor found and initialized!"));
}

void BMEloop() {
  float temperatureC = bme.readTemperature();
  Serial.print(F("Temperature = "));
  Serial.print(temperatureC);
  Serial.println(" *C");

  float pressureHpa = bme.readPressure() / 100.0F;
  Serial.print(F("Pressure = "));
  Serial.print(pressureHpa);
  Serial.println(" hPa");

  float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  Serial.print(F("Approx. Altitude = "));
  Serial.print(altitude);
  Serial.println(" m");

  float humidity = bme.readHumidity();
  Serial.print(F("Humidity = "));
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println();
  delay(2000); 
}


#include <Wire.h>
#include <QMC5883LCompass.h>

QMC5883LCompass compass;

void QMCsetup() {
  compass.init();  // Initialize the QMC5883L sensor
  Serial.println("QMC5883L initialized successfully!");
}

void QMCloop() {
  int x, y, z;
  compass.read(); // Read magnetometer values
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  // Convert raw values to microteslas (µT)
  float scalingFactor = 12000.0;
  float xMicroT = x / scalingFactor;
  float yMicroT = y / scalingFactor;
  float zMicroT = z / scalingFactor;

  Serial.print("X: "); Serial.print(xMicroT, 2);
  Serial.print(" µT  Y: "); Serial.print(yMicroT, 2);
  Serial.print(" µT  Z: "); Serial.println(zMicroT, 2);

  delay(1000);
}

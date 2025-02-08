#include <Wire.h>
#include <QMC5883LCompass.h>  // Use Adafruit_HMC5883_U.h if using HMC5883L

QMC5883LCompass compass;

void QMCsetup() {
  compass.init();
  Serial.println("QMC5883L Magnetometer Initialized!");
}

void QMCloop() {
  int x, y, z;
  compass.read();
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  float fieldStrength = sqrt(x * x + y * y + z * z);

  float heading = atan2(y, x) * (180.0 / PI);
  if (heading < 0) heading += 360;

  Serial.println("\n Magnetometer HMC/QMC Readings:");

  Serial.print("Magnetic Field Strength: ");
  Serial.print(fieldStrength);
  Serial.println(" µT  (Normal range: 25-65 µT)");

  Serial.print("→ Compass Heading: ");
  Serial.print(heading, 2);
  Serial.println("°");

  Serial.print("X: "); Serial.print(x); Serial.print(" µT, ");
  Serial.print("Y: "); Serial.print(y); Serial.print(" µT, ");
  Serial.print("Z: "); Serial.println(z); Serial.print(" µT");

  // Check if the field strength is unusually weak (possible interference)
  if (fieldStrength < 10) {
    Serial.println("WARNING: Magnetic field is very weak! Possible interference.");
  }

  Serial.println("-------------------------");
  delay(2000);
}

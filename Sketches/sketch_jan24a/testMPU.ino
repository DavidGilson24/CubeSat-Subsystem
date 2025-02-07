#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void MPUsetup() {
  Wire.begin();

  Serial.println("Initializing MPU6050...");
  
  mpu.initialize();
  
  if (!mpu.testConnection()) {
    Serial.println("ERROR: MPU6050 not found. Check wiring!");
    while (1);
  }

  Serial.println("MPU6050 initialized successfully!");
}

void MPUloop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  // Get raw accelerometer and gyroscope data
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  Serial.println("\nMPU6050 Sensor Data:");

  Serial.print("Accelerometer (X, Y, Z): ");
  Serial.print(ax); Serial.print(", ");
  Serial.print(ay); Serial.print(", ");
  Serial.println(az);

  Serial.print("Gyroscope (X, Y, Z): ");
  Serial.print(gx); Serial.print(", ");
  Serial.print(gy); Serial.print(", ");
  Serial.println(gz);
}

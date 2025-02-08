/*
  MPUProcessing.ino
  Handles:
    - MPU6050 initialization
    - Reading accelerometer and gyroscope data
    - Creating a "report" about motion/orientation
*/

#include "MPU6050.h"

MPU6050 mpu;

static int16_t ax, ay, az;
static int16_t gx, gy, gz;

void initializeMPU() {
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println(F("[MPU] FAIL"));
  } else {
    Serial.println(F("[MPU] INITIALIZED"));
  }
}

// -----------------------------------------------------------------------------

void readMPUData() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
}

// -----------------------------------------------------------------------------

String getMPUReport() {
  readMPUData();

  float ax_g = ax / 16384.0;
  float ay_g = ay / 16384.0;
  float az_g = az / 16384.0;

  float gx_dps = gx / 131.0;
  float gy_dps = gy / 131.0;
  float gz_dps = gz / 131.0;

  float accelMagnitude = sqrt(ax_g*ax_g + ay_g*ay_g + az_g*az_g);

  String orientationRemark;
  if (fabs(accelMagnitude - 1.0) < 0.2) {
    orientationRemark = "Close to 1g total, likely stable orientation.";
  } else {
    orientationRemark = "Acceleration significantly different from 1g; device may be moving or angled.";
  }

  float totalGyro = fabs(gx_dps) + fabs(gy_dps) + fabs(gz_dps);
  String motionRemark;
  if (totalGyro > 50) {
    motionRemark = "Significant rotation detected; system may be in motion or vibrating heavily.";
  } else {
    motionRemark = "Low rotation rates; system is relatively stable.";
  }

  String report = F("MPU6050 Detailed Report:\n");
  report += "  Accelerometer (g): X=" + String(ax_g, 2) + ", Y=" + String(ay_g, 2) + ", Z=" + String(az_g, 2) + "\n";
  report += "    Insight: " + orientationRemark + "\n\n";

  report += "  Gyroscope (deg/s): X=" + String(gx_dps, 2) + ", Y=" + String(gy_dps, 2) + ", Z=" + String(gz_dps, 2) + "\n";
  report += "    Insight: " + motionRemark + "\n";

  return report;
}

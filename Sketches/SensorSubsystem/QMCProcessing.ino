/*
  QMCProcessing.ino
  Handles:
    - QMC5883L initialization
    - Reading magnetometer data
    - Reporting on magnetic field strength and heading
*/

#include "QMC5883LCompass.h"
#include <math.h> 

QMC5883LCompass qmc;

static float mx = 0, my = 0, mz = 0;
static float headingDeg = 0;
static float magFieldStrength = 0;

// -----------------------------------------------------------------------------

void initializeQMC() {
  qmc.init();
  Serial.println(F("[QMC] INITIALIZED"));
}

// -----------------------------------------------------------------------------

void readQMCData() {
  qmc.read();
  int x = qmc.getX();
  int y = qmc.getY();
  int z = qmc.getZ();

  mx = x * 0.01;
  my = y * 0.01;
  mz = z * 0.01;

  headingDeg = atan2(my, mx) * (180.0 / M_PI);
  if (headingDeg < 0) headingDeg += 360.0;

  magFieldStrength = sqrt(mx*mx + my*my + mz*mz);
}

// -----------------------------------------------------------------------------

String getQMCReport() {
  readQMCData();

  String fieldInsight;
  if (magFieldStrength < 10) {
    fieldInsight = F("Extremely weak field; likely interference or miscalibration.");
  } else if (magFieldStrength < 25) {
    fieldInsight = F("Below Earth's normal range; possibly partial shielding or interference.");
  } else if (magFieldStrength > 65) {
    fieldInsight = F("Above Earth's normal range; possible local magnets or metal interference.");
  } else {
    fieldInsight = F("Within normal Earth field range.");
  }

  String report = F("QMC5883L Detailed Report:\n");
  report += "  Heading: " + String(headingDeg, 2) + "°\n";
  report += F("    Note: 0° = North, 90° = East, etc.\n\n");

  report += "  Magnetic Field Strength: " + String(magFieldStrength, 2) + " µT\n";
  report += "    Insight: " + fieldInsight + "\n\n";

  report += "  Raw Components: X=" + String(mx, 2) + "µT, Y=" + String(my, 2) + "µT, Z=" + String(mz, 2) + "µT\n";

  return report;
}



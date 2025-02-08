/*
  BMEProcessing.ino
  Handles:
    - BME280 initialization
    - Reading sensor data (temperature, pressure, humidity)
    - Interpreting the readings into a comprehensive "report"
*/

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Create a BME280 object
Adafruit_BME280 bme;

static float bmeTempC     = 0.0;
static float bmePressure  = 0.0;
static float bmeHumidity  = 0.0;
static float bmeAltitude  = 0.0;

#define SEALEVELPRESSURE_HPA (1013.25)

// -----------------------------------------------------------------------------

void initializeBME() {
  bool status = bme.begin(0x76);
  if (!status) {
    Serial.println(F("[BME] FAIL at 0x76 -> 0x77..."));
    status = bme.begin(0x77);
  }
  if (!status) {
    Serial.println(F("[BME] FAIL"));
  } else {
    Serial.println(F("[BME] INITIALIZED"));
  }
}

// -----------------------------------------------------------------------------

void readBMEData() {
  bmeTempC    = bme.readTemperature();
  bmePressure = bme.readPressure() / 100.0F; // Convert Pa to hPa
  bmeHumidity = bme.readHumidity();
  bmeAltitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
}

// -----------------------------------------------------------------------------

String getBMEReport() {
  readBMEData();

  String tempRemark;
  if (bmeTempC < 0) {
    tempRemark = "Below freezing; risk of ice formation in certain conditions.";
  } else if (bmeTempC < 18) {
    tempRemark = "A bit cool; may require additional heating for sensitive electronics.";
  } else if (bmeTempC < 25) {
    tempRemark = "Comfortable room temperature range.";
  } else {
    tempRemark = "Quite warm; ensure adequate cooling for heat-sensitive components.";
  }

  String humidityRemark;
  if (bmeHumidity < 30) {
    humidityRemark = "Air is dry; may cause static or dryness issues.";
  } else if (bmeHumidity <= 60) {
    humidityRemark = "Optimal humidity range for most environments.";
  } else {
    humidityRemark = "High humidity; risk of condensation or corrosion on electronics.";
  }

  String pressureRemark;
  if (bmePressure < 1000) {
    pressureRemark = "Lower than standard sea-level pressure; potential storm or high altitude.";
  } else if (bmePressure <= 1025) {
    pressureRemark = "Within normal sea-level range; likely stable weather conditions.";
  } else {
    pressureRemark = "Higher than average sea-level pressure; typically fair weather.";
  }

  String report = F("BME280 Detailed Report:\n");
  report += "  Temperature: ";
  report += String(bmeTempC, 2) + " °C\n";
  report += "    Insight: " + tempRemark + "\n\n";

  report += "  Pressure: ";
  report += String(bmePressure, 2) + " hPa\n";
  report += "    Insight: " + pressureRemark + "\n\n";

  report += "  Altitude (approx): ";
  report += String(bmeAltitude, 2) + " m\n";
  report += F("    Note: Altitude is derived from pressure. For accuracy, update SEALEVELPRESSURE_HPA.\n\n");

  report += "  Humidity: ";
  report += String(bmeHumidity, 2) + " %\n";
  report += "    Insight: " + humidityRemark + "\n";

  return report;
}


/*
  DSClockProcessing.ino
  Handles:
    - DS3231 (or DS1307) real-time clock initialization
    - Fetching the current time
    - Providing interpretive text about day/night, etc.
*/

#include <RTClib.h>

RTC_DS3231 rtc;

// -----------------------------------------------------------------------------

void initializeDSClock() {
  if (!rtc.begin()) {
    Serial.println(F("[DS] FAIL"));
  } else {
    Serial.println(F("[DS] INITIALIZED"));
    // set the RTC time, for example:
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

// -----------------------------------------------------------------------------

String getDSClockReport() {
  DateTime now = rtc.now();

  char buffer[50];
  snprintf(buffer, sizeof(buffer), "%d/%02d/%02d %02d:%02d:%02d",
           now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());

  String dayPart = (now.hour() < 6 || now.hour() >= 22) ? "nighttime" : "daytime";

  String report = F("DS3231 RTC Detailed Report:\n");
  report += "  Current UTC Time: ";
  report += String(buffer);
  report += "\n  Insight: It appears to be ";
  report += dayPart;
  report += " (based on UTC hour).\n";

  return report;
}


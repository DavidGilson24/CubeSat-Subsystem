#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void DS3231setup() {
  if (!rtc.begin()) {
    Serial.println("Could not find a valid DS3231 RTC. Check wiring!");
    while (1);
  }

  Serial.println("DS3231 initialized successfully!");

  // **SET THE TIME ONLY ONCE, THEN COMMENT THIS OUT**
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); 

  Serial.println("RTC time has been set!");
}

void DS3231loop() {
  DateTime now = rtc.now();  // Get current UTC time

  Serial.println("\nCurrent UTC Time:");
  printTime(now, "UTC");

  delay(1000);
}

// Function to print time in a formatted way
void printTime(DateTime time, String location) {
  Serial.print(location + " Time: ");
  Serial.print(time.year(), DEC);
  Serial.print("/");
  Serial.print(time.month(), DEC);
  Serial.print("/");
  Serial.print(time.day(), DEC);
  Serial.print("  ");
  Serial.print(time.hour(), DEC);
  Serial.print(":");
  Serial.print(time.minute(), DEC);
  Serial.print(":");
  Serial.println(time.second(), DEC);
}



# CubeSat Subsystem

A functional CubeSat telemetry subsystem built with Arduino and various sensors.

## Overview

This project simulates a CubeSat telemetry subsystem, integrating various sensors and using LoRa SX1278 for long-range communication. The system collects and transmits atmospheric, positional, and time-based data.

## Features

- Environmental Monitoring (Temperature, Humidity, Pressure)
- Real-Time Clock for scheduling transmissions
- Magnetometer for orientation sensing
- Data Logging & Visualization on a ground station

## Hardware Components

| Component        | Function                                        |
|-----------------|------------------------------------------------|
| Arduino R3 | Control Unit | 
| BME280 | Altitude & Atmospheric Pressure Sensor | 
| DS3231 | Real-Time Clock |
| HMC5883L | Triple-Axis Magnetometer |
| MPU6050 | Gyroscope/Accelerometer for Orientation Sensing |

### TEST OUTPUT for subsystem

```shell
Initializing sensors...

Scanning for I2C devices...
Found I2C device at 0xD
Found I2C device at 0x68
Found I2C device at 0x69
Found I2C device at 0x76
I2C Scan Complete.
--------------------------------
Initializing MPU6050...
MPU6050 initialized successfully!
BME280 sensor found and initialized!
DS3231 initialized successfully!
RTC time has been set!
QMC5883L initialized successfully!
All sensors initialized successfully!
-------------------------

MPU6050 Sensor Data:
Accelerometer (X, Y, Z): 16808, -284, -1812
Accelerometer (g): 1.02, -0.02, -0.11
Gyroscope (X, Y, Z): -76, -85, -64
-------------------------

Temperature = 22.36 *C
Pressure = 1021.48 hPa
Approx. Altitude = 7.40 m
Humidity = 76.21 %
-------------------------

Current UTC Time using DS3:
UTC Time: 2025/01/23  14:23:06
-------------------------

Magnetometer HMC/QMC Readings:
Magnetic Field Strength: 0.198 µT  (Normal range: 25-65 µT)
Compass Heading: 263.29° 
X: -0.01 µT  Y: -0.18 µT  Z: 0.10 µT
WARNING: Magnetic field is very weak! Possible interference.
<<<<<<<<------------------------->>>>>>>>
```
# System design:

## Implemented
**Breadboard & Full-Board Setup**
![BREADBOARD-SYSTEM](https://github.com/user-attachments/assets/3f7a6421-bc16-4017-bb5a-60546074a683)

**ProtoShield System Setup**
![ProtoShield](https://github.com/user-attachments/assets/265aceed-508b-406c-8a3e-03dd4781db34)

## Not Implemented
**Enclosure Setup**
![ENCLOSURE-DESIGN1](https://github.com/user-attachments/assets/0d237dae-de9b-40f7-bcda-483326f747b4)

# Finalized CubeSat SubSystem response to environment

```
Initializing Sensor Subsystem...
[BME] INITIALIZED
[MPU] INITIALIZED
[QMC] INITIALIZED
[DS] INITIALIZED
All sensors initialized successfully!
---------------------------------------
=== Sensor Data Report ===
BME280 Detailed Report:
  Temperature: 22.36 °C
    Insight: Comfortable room temperature range.

  Pressure: 1021.48 hPa
    Insight: Within normal sea-level range; likely stable weather conditions.

  Altitude (approx): 7.40 m
    Note: Altitude is derived from pressure. For accuracy, update SEALEVELPRESSURE_HPA.

  Humidity: 76.21 %
    Insight: High humidity; risk of condensation or corrosion on electronics.

MPU6050 Detailed Report:
  Accelerometer (g): X=1.02, Y=-0.02, Z=-0.11
    Insight: Close to 1g total, likely stable orientation.

  Gyroscope (deg/s): X=-0.58, Y=-0.65, Z=-0.49
    Insight: Low rotation rates; system is relatively stable.

QMC5883L Detailed Report:
  Heading: 263.29°
    Note: 0° = North, 90° = East, etc.

  Magnetic Field Strength: 0.20 µT
    Insight: Extremely weak field; likely interference or miscalibration.

  Raw Components: X=-0.01µT, Y=-0.18µT, Z=0.10µT

DS3231 RTC Detailed Report:
  Current UTC Time: 2025/01/23 14:23:06
  Insight: It appears to be daytime (based on UTC hour).
---------------------------------------

```

# What this means:

## Interpretation of the Test Results

### 1. BME280 Environmental Data
- **Temperature: 22.36 °C**  
  - **Earth Context:**  
    - This is a comfortable indoor temperature, suggesting normal lab or room conditions.  
    - Electronics operate well in this range, with minimal risk of overheating or freezing.  
  - **High Altitude / Near-Space:**  
    - At high altitude (e.g., in balloon missions), ambient temperature can drop well below 0 °C. A reading of ~22 °C may indicate you’re still near ground level or you have some thermal regulation.  
  - **Low-Earth Orbit (CubeSat Scenario):**  
    - External temperatures can vary from about -120 °C to +120 °C depending on sun exposure. A reading in the 20s °C suggests either an internal temperature-controlled environment, insulation, or that the sensor is measuring conditions inside a pressurized, thermally managed compartment.

- **Pressure: 1021.48 hPa**  
  - **Earth Context:**  
    - Very close to standard sea-level pressure (1013 hPa), indicating near-sea-level elevation with stable weather conditions.  
  - **High Altitude / Near-Space:**  
    - Pressure drops significantly with altitude. Near the edge of space (30+ km), atmospheric pressure is only a fraction of sea-level values.
  - **Orbit:**  
    - True orbital flight is a near-vacuum environment (~0 hPa). A BME280 reading around 1000 hPa in orbit would imply it’s measuring the internal pressure of a sealed satellite module rather than the external vacuum.

- **Approx. Altitude: 7.40 m**  
  - **Earth Context:**  
    - Suggests a location close to sea level. This is plausible if you’re physically near coastal regions or at low elevation.  
  - **High Altitude / Near-Space:**  
    - If actually in near-space, this value should read thousands of meters or more
  - **Orbit:**  
    - In Low-Earth Orbit, you’re 200+ km above Earth’s surface. Because the sensor uses atmospheric pressure to estimate altitude, it wouldn’t reflect real orbital altitude.

- **Humidity: 76.21 %**  
  - **Earth Context:**  
    - Relatively high humidity, indicating a humid environment (possibly coastal or a damp indoor setting). High humidity can risk condensation or corrosion on sensitive electronics if not properly sealed.  
  - **High Altitude / Near-Space:**  
    - Humidity generally decreases sharply as altitude increases.  
  - **Orbit:**  
    - External humidity is virtually zero in a vacuum. If a CubeSat measured 76% internally, that would be a sign of poor humidity control or possible leakage of moisture into the sealed environment.

### 2. MPU6050 Motion & Orientation Data
- **Accelerometer (g): X=1.02, Y=-0.02, Z=-0.11**  
  - **Interpretation:**  
    - The total magnitude is ~1 g, indicating normal gravity without significant motion. Slight deviations from exactly 1.0 may be due to tilt or sensor noise.  
  - **Earth Context:**  
    - Suggests the device is resting on a surface, angled slightly.  
  - **High Altitude / Near-Space / Orbit:**  
    - In free-fall or microgravity, you’d expect near 0 g unless the craft is undergoing accelerations from rocket thrust or attitude maneuvers.

- **Gyroscope (deg/s): X=-0.58, Y=-0.65, Z=-0.49**  
  - **Interpretation:**  
    - Low rotation rates imply the system is not spinning or vibrating heavily.  
  - **CubeSat in Orbit:**  
    - A tumbling satellite could show higher values. A well-stabilized satellite might show very low rates similar to these if attitude control is functioning.

### 3. QMC5883L Magnetic Field Data
- **Magnetic Field Strength: ~0.20 µT**  
  - **Typical Earth Surface Range:** 25–65 µT.  
  - **Interpretation:**  
    - This reading is much weaker than Earth’s expected field. Likely indicates local interference (e.g., large metal objects, EMI).  
  - **High Altitude / Near-Space:**  
    - Earth’s field is somewhat weaker but still much higher than 0.20 µT.  
  - **Orbit:**  
    - In Low-Earth Orbit, the Earth’s magnetic field is still measurable (often 20–60 µT).

- **Heading: 263.29°**  
  - Interprets the sensor facing roughly West (where 0°=North, 90°=East, 180°=South, and 270°=West). This could be skewed by indoor interference or metal objects.

### 4. DS3231 Real-Time Clock
- **UTC Time: 2025/01/23 14:23:06**  
  - **Daytime** by standard 24-hour measurement.  
  - The DS3231 is keeping accurate time. In orbit, the clock would still function the same, although you might use mission elapsed time or sync with ground stations.

---

## Key Takeaways from the Report

1. **Environment**: The subsystem is operating under typical **ground-level conditions** (22 °C, ~1021 hPa).  
2. **Humidity**: 76% is relatively high, prompting concerns about potential moisture issues if not handled properly.  
3. **Stability**: Low gyroscopic and near-1g accelerometer readings indicate a **stationary** or gently angled orientation, consistent with a lab test setup.  
4. **Magnetic Field Anomaly**: An extremely weak measured field (~0.20 µT) suggests **interference** problems with the magnetometer, especially since normal Earth conditions should read tens of microteslas.  
5. **Timekeeping**: The DS3231 shows an accurate timestamp, useful for logging or telemetry scheduling.

---

## How This Relates to Space / Near-Space Missions

- **Thermal Considerations**: Actual CubeSat missions experience extreme temperature swings. If your BME280 is reading a comfortable 22 °C, it may be placed in an insulated or heated compartment.  
- **Pressure Readings**: True orbital or near-space flights won’t see ~1000 hPa externally. The sensor data here suggests ground testing.  
- **Attitude & Orbit**: Real orbital measurements might see near-0 g (unless maneuvering) and possibly a different magnetic field strength if the magnetometer is properly calibrated.  
- **Data Logging & Time Sync**: The DS3231 provides consistent timing for data logging, which is crucial for correlating sensor events with ground station telemetry.  

Overall, **these test results confirm** that the sensors are functioning, but **they also highlight** areas needing attention for a real mission scenario (particularly magnetometer calibration and humidity control). If a telemetry subsystem such as this is deployed, we should notice significantly different readings (e.g., near-zero atmospheric pressure, wider temperature ranges, etc.).


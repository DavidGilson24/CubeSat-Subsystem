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
### Breadboard system design:
![BREADBOARD-SYSTEM](https://github.com/user-attachments/assets/3f7a6421-bc16-4017-bb5a-60546074a683)

# Finalized CubeSat SubSystem response to environment

```
Initializing Sensor Subsystem...
BME280 sensor found and initialized!
MPU6050 initialized successfully!
QMC5883L initialized successfully!
DS3231 initialized successfully!
All sensors initialized successfully!
---------------------------------------
=== Sensor Data Report ===
BME280 Report:
  Temperature: 22.36 °C (Normal room temperature range)
  Pressure:    1021.48 hPa (Near-sea-level pressure)
  Altitude:    7.40 m (approx.)
  Humidity:    76.21 % (High humidity)

MPU6050 Report:
  Accelerometer (g): X=1.02, Y=-0.02, Z=-0.11 (Nearly stable, close to 1g total acceleration)
  Gyroscope (deg/s): X=-0.58, Y=-0.65, Z=-0.49

QMC5883L Report:
  Magnetic Field (µT): 0.20 (Extremely weak field - possible interference?)
  Heading: 263.29°
  Components: X=-0.01µT, Y=-0.18µT, Z=0.10µT

DS3231 RTC Report:
  Current UTC Time: 2025/01/23 14:23:06
  It's daytime. (Based on UTC hour)
---------------------------------------
```

### What this means:

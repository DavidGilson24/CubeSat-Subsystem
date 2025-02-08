# CubeSat Subsystem

A fully functional CubeSat telemetry subsystem built with Arduino and various sensors.

## Overview

This project simulates a CubeSat telemetry subsystem, integrating various sensors and using LoRa SX1278 for long-range communication. The system collects and transmits atmospheric, positional, and time-based data.

## Features

- Telemetry Communication using LoRa SX1278
- Environmental Monitoring (Temperature, Humidity, Pressure)
- Real-Time Clock for scheduling transmissions
- Magnetometer for orientation sensing
- Data Logging & Visualization on a ground station

## Hardware Components

| Component        | Function                                        |
|-----------------|------------------------------------------------|
| Arduino Uno | Control Unit | 
| BMP280 | Altitude & Atmospheric Pressure Sensor | 
| DS3231 | Real-Time Clock |
| LoRa SX1278 | Wireless Telemetry Communication | 
| HMC5883L | Triple-Axis Magnetometer |
| MPU6050 | Gyroscope/Accelerometer for Orientation Sensing |

### Example of OUTPUT using HMC, DS3 and MPU

```shell script
Initializing sensors...

🔍 Scanning for I2C devices...
✅ Found I2C device at 0xD
✅ Found I2C device at 0x68
✅ Found I2C device at 0x69
🔍 I2C Scan Complete.
--------------------------------
Initializing MPU6050...
MPU6050 initialized successfully!
DS3231 initialized successfully!
RTC time has been set!
QMC5883L initialized successfully!
All sensors initialized successfully!

MPU6050 Sensor Data:
Accelerometer (X, Y, Z): 16808, -284, -1812
Accelerometer (g): 1.02, -0.02, -0.11
Gyroscope (X, Y, Z): -76, -85, -64

Current UTC Time using DS3:
UTC Time: 2025/01/23  14:23:06

Magnetometer HMC/QMC:
X: -0.01 µT  Y: -0.18 µT  Z: 0.10
Magnetic Field Strength: 0.198 µT  (Normal range: 25-65 µT, very weak - possible interference)
Compass Heading: 263.29° 
-------------------------
```


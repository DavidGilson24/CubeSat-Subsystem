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

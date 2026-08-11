🥛 Milk Adulteration Detection System

📌 Overview

Milk adulteration is a major food-quality concern in which substances such as water, detergent, starch, urea, and other chemicals may be added to milk.

This project presents a low-cost, portable, and real-time **Milk Adulteration Detection System** using an Arduino Uno and multiple sensors. The system monitors important milk parameters using a pH sensor, DS18B20 temperature sensor, and MQ135 gas sensor. The sensor readings are processed by the Arduino and the detected status is displayed on a 16×2 LCD.

The project aims to provide a simple and accessible approach for preliminary milk quality monitoring without relying entirely on conventional laboratory-based testing.

🎯 Objectives

1. Develop a low-cost milk adulteration detection system.
2. Monitor milk using pH, temperature, and gas sensors.
3. Process sensor data using an Arduino Uno.
4. Compare sensor readings with predefined threshold values.
5. Provide real-time results through an LCD display.
6. Develop a portable and user-friendly prototype.
7. Explore possibilities for future IoT and machine-learning enhancements.


🔧 Hardware Components

Arduino Uno - Processes sensor data and controls the system.
pH Sensor - Measures the acidity/alkalinity of the milk.
DS18B20 Temperature Sensor - Measures milk temperature.
MQ135 Gas Sensor - Detects gases/volatile compounds.
16×2 LCD Display - Displays sensor readings and detection status.
Breadboard - Circuit prototyping.
Jumper Wires - Component connections.
Power Supply - Powers the system.


⚙️ System Architecture

The system follows this basic architecture:

                 ┌─────────────────┐
                 │   Milk Sample   │
                 └────────┬────────┘
                          │
          ┌───────────────┼────────────────┐
          │               │                │
          ▼               ▼                ▼
    ┌──────────┐    ┌────────────┐    ┌───────────┐
    │ pH Sensor│    │ DS18B20    │    │  MQ135    │
    │          │    │ Temperature│    │Gas Sensor │
    └────┬─────┘    └─────┬──────┘    └─────┬─────┘
         │                │                 │
         └────────────────┼─────────────────┘
                          ▼
                 ┌─────────────────┐
                 │   Arduino UNO   │
                 │ Data Processing │
                 └────────┬────────┘
                          │
                          ▼
                 ┌─────────────────┐
                 │    16×2 LCD     │
                 │  Result Display │
                 └─────────────────┘

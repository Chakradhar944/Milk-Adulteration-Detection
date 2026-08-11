# 🥛 Milk Adulteration Detection System

## 📌 Overview

Milk adulteration is a major food-quality concern in which substances such as water, detergent, starch, urea, and other chemicals may be added to milk.

This project presents a low-cost, portable, and real-time **Milk Adulteration Detection System** using an **Arduino Uno** and multiple sensors. The system monitors important milk parameters using a **pH sensor, DS18B20 temperature sensor, and MQ135 gas sensor**. The sensor readings are processed by the Arduino and the detected status is displayed on an LCD.

The system provides a simple approach for preliminary milk quality monitoring by analyzing multiple sensor parameters and comparing them with predefined threshold values.

---

## 🎯 Objectives

- Develop a low-cost milk quality monitoring system.
- Monitor milk using pH, temperature, and gas sensors.
- Process sensor data using an Arduino Uno.
- Compare sensor readings with predefined threshold values.
- Provide real-time information through an LCD display.
- Develop a portable and easy-to-use prototype.
- Combine multiple sensor parameters for preliminary milk quality assessment.

---

## 🔧 Hardware Components

**Arduino Uno** - Processes sensor data and controls the system 
**pH Sensor** - Measures the acidity/alkalinity of the milk 
**DS18B20 Temperature Sensor** - Measures the temperature of the milk sample 
**MQ135 Gas Sensor** - Provides gas-level measurements 
**LCD Display** - Displays sensor readings and detection status 
**Breadboard** - Used for circuit prototyping 
**Jumper Wires** - Used for component connections 
**Power Supply** - Provides power to the system 

---

## ⚙️ System Architecture

The system follows a multi-sensor architecture in which the sensors collect information from the milk sample and send their readings to the Arduino Uno.


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
                 │   LCD Display   │
                 │  Result Display │
                 └─────────────────┘

🔄 How the System Works
A milk sample is provided for testing.
The pH sensor measures the pH level of the sample.
The DS18B20 sensor measures the temperature.
The MQ135 sensor provides a gas-level reading.
The Arduino Uno collects the sensor readings.
The readings are processed by the Arduino.
Each parameter is compared with its predefined threshold.
If a parameter falls outside its defined range, the system identifies the sample as potentially adulterated.
The sensor values and detected status are displayed on the LCD.
Sensor information can also be observed through the Arduino IDE Serial Monitor.

💻 IDE & Development Environment

Arduino IDE:

The project was developed using the Arduino IDE (Integrated Development Environment).

Arduino IDE was used to:

Write and edit the Embedded C/C++ program.
Compile and verify the source code.
Upload the program to the Arduino Uno.
Select the Arduino board and communication port.
Monitor sensor readings during testing.
Debug the system using the Serial Monitor.
Development Workflow
Write Code
    ↓
Compile / Verify
    ↓
Connect Arduino Uno
    ↓
Select Board & COM Port
    ↓
Upload Program
    ↓
Monitor Sensor Data
    ↓
Test & Debug


📚 Libraries Used

The project uses Arduino libraries for communication with the LCD and DS18B20 temperature sensor.

1. Wire.h

The Wire library provides I2C communication support for the Arduino.

It is used to establish communication between the Arduino Uno and the I2C-based LCD module.

It allows the Arduino to send commands and display data through the I2C interface.

2. LiquidCrystal_I2C.h

The LiquidCrystal_I2C library is used to control the I2C LCD.

It provides functions for:

Initializing the LCD
Controlling the LCD backlight
Setting the cursor position
Displaying sensor readings
Displaying the system status
Clearing the display

3. OneWire.h

The OneWire library provides communication support for devices that use the One-Wire communication protocol.

In this project, it is used to communicate with the DS18B20 temperature sensor.

4. DallasTemperature.h

The DallasTemperature library provides functions for obtaining temperature measurements from the DS18B20 sensor.

It is used to:

Initialize the temperature sensor
Request temperature measurements
Read the temperature value
Obtain the temperature reading in degrees Celsius
Library Summary
Library	Purpose
Wire.h	I2C communication
LiquidCrystal_I2C.h	LCD control
OneWire.h	One-Wire communication
DallasTemperature.h	DS18B20 temperature measurement

🔌 Pin Connections

The main sensor connections used by the Arduino program are:

pH Sensor -	A0
MQ135 Gas Sensor -	A1
DS18B20 Temperature Sensor -	D2
I2C LCD SDA -	A4
I2C LCD SCL -	A5

Detailed circuit diagrams and connection diagrams are available in the circuit folder.

📐 Circuit Diagram

The project contains the following circuit documentation:

Block diagram
Circuit diagram
Pin-connection diagram

These diagrams can be found in:

circuit/
🖥️ System Output

The system displays the measured parameters and detection status on the LCD.

The displayed information includes:

Temperature
pH value
Gas value
Milk status
Reason for the detected status

The Arduino program compares the measured values with predefined threshold conditions.

The implemented detection logic uses:

Temperature Range: 25°C – 35°C
pH Range: 6.4 – 7.0
Gas Sensor Limit: 300
If a measured parameter falls outside its defined condition, the system displays an ADULTERATED status along with the corresponding reason.

📷 Prototype

The project was implemented as a hardware prototype using an Arduino Uno, sensors, LCD display, breadboard, and connecting wires.


▶️ How to Run the Project
Step 1 — Install Arduino IDE

Install the Arduino IDE on your computer.

Step 2 — Install Required Libraries

Open the Arduino IDE Library Manager and install:

LiquidCrystal_I2C
OneWire
DallasTemperature

The Wire.h library is used for I2C communication.

Step 3 — Connect the Hardware

Connect the sensors, Arduino Uno, and LCD according to the circuit diagrams provided in the circuit/ folder.

Step 4 — Open the Source Code

Open:

source-code/milk_adulteration_detection.ino

in the Arduino IDE.

Step 5 — Select the Board

Select:

Arduino Uno

from the Arduino IDE board selection menu.

Step 6 — Select the COM Port

Connect the Arduino Uno to your computer using a USB cable and select the corresponding COM port.

Step 7 — Verify the Code

Click Verify or Compile in the Arduino IDE to check the program for compilation errors.

Step 8 — Upload the Program

Click Upload to transfer the program to the Arduino Uno.

Step 9 — Monitor the System

After uploading the program, the sensors begin collecting data.

The LCD displays the sensor readings and system status.

The Serial Monitor can also be used to observe sensor readings during testing.

🧪 Detection Parameters

The system evaluates multiple parameters instead of relying on a single sensor.

pH

The pH sensor provides the pH value of the milk sample. The measured value is compared against the predefined pH range.

Temperature

The DS18B20 sensor measures the temperature of the milk sample. The temperature reading is compared against the defined temperature range.

Gas Level

The MQ135 sensor provides a gas-level reading. The measured value is compared against the predefined gas threshold.


📊 Serial Monitor

The Arduino IDE Serial Monitor can be used to observe sensor data during testing.

Example output format:

------ MILK ANALYSIS ------
Temperature: XX.X
pH Value: X.XX

The Serial Monitor is useful for observing sensor readings and debugging the system during development.

🛠️ Technologies Used
Hardware
Arduino Uno
pH Sensor
DS18B20 Temperature Sensor
MQ135 Gas Sensor
LCD Display
Breadboard
Jumper Wires
Software
Arduino IDE
Embedded C/C++
Arduino Libraries
I2C Communication
One-Wire Communication

## 📁 Repository Structure

```text
Milk-Adulteration-Detection/
│
├── circuit/
│   ├── block-diagram.png
│   └── circuit-diagram.png
│
├── documentation/
│   └── Project-report.pdf
│
├── prototype/
│   └── prototype-and-lcd-output.png
│
├── source-code/
│   └── milk_adulteration_detection.ino
│
└── README.md 

📂 Documentation

Additional project documentation will be available in the documentation folder.

The documentation may include:
Project Report

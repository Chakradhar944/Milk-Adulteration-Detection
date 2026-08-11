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


💻 IDE & Libraries


Arduino IDE:
The "Arduino IDE (Integrated Development Environment)" was used as the primary development environment for this project. It was used to write, edit, compile, and upload the Embedded C/C++ program to the Arduino Uno.
The Arduino IDE was also used during testing and debugging through the **Serial Monitor**, which allows sensor readings such as temperature, pH value, and gas sensor value to be observed while the system is running.


The overall development workflow was:

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
The project uses several Arduino libraries to interface with the LCD and temperature sensor.

1. Wire.h
The Wire library provides I2C communication support for the Arduino. It is used as the communication interface between the Arduino Uno and the I2C-based LCD module.

In this project, the library enables the Arduino to send display commands and data to the LCD using the I2C interface.

2. LiquidCrystal_I2C.h
The LiquidCrystal_I2C library is used to control the I2C LCD display.
It provides functions for:

Initializing the LCD
Turning on the LCD backlight
Setting the cursor position

Displaying sensor readings
Displaying the milk quality status
Clearing the display

The LCD is used to display parameters such as temperature, pH value, gas value, and the detected status.

3. OneWire.h
The OneWire library provides communication support for devices that use the One-Wire communication protocol.
In this project, it is used to communicate with the DS18B20 temperature sensor through its data line.

4. DallasTemperature.h
The DallasTemperature library provides a convenient interface for obtaining temperature measurements from the DS18B20 sensor.
It is used to:

Initialize the temperature sensor
Request temperature measurements
Read the temperature value
Convert the sensor data into a temperature reading in °C



▶️ How to Run the Project

1. Install Arduino IDE
Download and install the Arduino IDE on your computer.

2. Install Required Libraries
Open Arduino IDE and install the following libraries through the Library Manager:

- LiquidCrystal_I2C
- OneWire
- DallasTemperature

The Wire.h library is used for I2C communication and is included with the Arduino environment.

3. Connect the Hardware
Connect the components according to the circuit and pin-connection diagrams provided in the circuit/ folder.

The main connections are:

pH Sensor - A0 
MQ135 Gas Sensor - A1 
DS18B20 Temperature Sensor - D2 
I2C LCD SDA - A4 
I2C LCD SCL - A5 

4. Open the Source Code
Open: source-code/milk_adulteration_detection.ino

5. Select Arduino Board
In Arduino IDE, select:
Board: Arduino Uno

6. Select COM Port
Connect the Arduino Uno to the computer using a USB cable and select the corresponding COM port.

7. Verify the Program
Click Verify/Compile in the Arduino IDE to check the program for compilation errors.

8. Upload the Program
Click Upload to transfer the program to the Arduino Uno.

9. Monitor the Output
After uploading, the system initializes the sensors and LCD.

The LCD displays:

Temperature
pH value
Gas value
Milk status
Reason for adulteration, if detected

The Arduino IDE Serial Monitor can also be used to observe sensor readings and system output during testing.

10. Test the System
Provide the milk sample and observe the sensor readings and displayed status.

The system compares the measured values against predefined threshold values and displays the corresponding milk quality status.

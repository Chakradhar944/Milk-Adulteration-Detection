#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// -------- LCD --------
LiquidCrystal_I2C lcd(0x27, 20, 4);

// -------- PINS --------
#define PH_PIN A0
#define MQ135_PIN A1
#define ONE_WIRE_BUS 2

// -------- TEMP SENSOR --------
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// -------- CALIBRATION --------
float neutralVoltage = 3.33;
float slope = 3.5;

// -------- STANDARD VALUES --------
#define TEMP_MIN 25
#define TEMP_MAX 35
#define PH_MIN 6.4
#define PH_MAX 7.0
#define GAS_MAX 300 // only upper limit

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  sensors.begin();

  lcd.setCursor(0, 0);
  lcd.print("Milk Quality Sys");

  lcd.setCursor(0, 1);
  lcd.print("Initializing...");

  delay(2000);
  lcd.clear();
}

void loop() {

  // -------- TEMPERATURE --------
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  // -------- pH SENSOR --------
  float sum = 0;

  for (int i = 0; i < 10; i++) {
    sum += analogRead(PH_PIN);
    delay(10);
  }

  float avg = sum / 10.0;
  float voltage = avg * (5.0 / 1023.0);
  float pHValue = 7 - (voltage - neutralVoltage) * slope;

  // -------- MQ135 --------
  int gasValue = analogRead(MQ135_PIN);

  // -------- STATUS & REASON --------
  String status = "PURE MILK";
  String reason = "All OK";

  if (temperature < TEMP_MIN || temperature > TEMP_MAX) {
    status = "ADULTERATED";
    reason = "Temp Issue";
  }
  else if (pHValue < PH_MIN || pHValue > PH_MAX) {
    status = "ADULTERATED";
    reason = "pH Issue";
  }
  else if (gasValue > GAS_MAX) {
    status = "ADULTERATED";
    reason = "Gas High";
  }

  // -------- LCD DISPLAY --------
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C");

  lcd.setCursor(10, 0);
  lcd.print("pH:");
  lcd.print(pHValue, 2);

  lcd.setCursor(0, 1);
  lcd.print("Gas:");
  lcd.print(gasValue);

  lcd.setCursor(0, 2);
  lcd.print("Status:");
  lcd.print(status);

  lcd.setCursor(0, 3);
  lcd.print(reason);

  // -------- SERIAL OUTPUT --------
  Serial.println("------ MILK ANALYSIS ------");

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("pH Value: ");
  Serial.println(pHValue);
}

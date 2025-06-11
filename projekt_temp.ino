#include <LiquidCrystal.h>
#include <math.h>
 
// LCD pin configuration: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
// Thermistor pins
const int ThermistorPin1 = A0;
const int ThermistorPin2 = A1;
 
// LED bar graph
const int analogPin = A2; // Potentiometer
const int ledCount = 10;
int ledPins[] = {6, 7, 8, 9, 10, A3, A4, A5, A6, A7};
 
// Thermistor 1 configuration (100k thermistor)
const float R1_T1 = 100000.0;
const float c1_T1 = 1.204607809e-03;
const float c2_T1 = 1.225340325e-04;
const float c3_T1 = 5.282886122e-07;
 
// Thermistor 2 configuration (50k thermistor)
const float R1_T2 = 50000.0;
const float c1_T2 = 1.687596719e-03;
const float c2_T2 = 1.256222705e-04;
const float c3_T2 = 6.606794151e-07;
 
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Initialize 16x2 LCD
 
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}
 
// Generalized function to read temperature from a thermistor
float readThermistor(int pin, float R1, float c1, float c2, float c3) {
  int val = analogRead(pin);
  float R2 = R1 * (1023.0 / (float)val - 1.0);
  float logR2 = log(R2);
  float tempK = 1.0 / (c1 + c2 * logR2 + c3 * pow(logR2, 3));
  return tempK - 273.15;  // Convert Kelvin to Celsius
}
 
void loop() {
  // Read temperatures using their specific configurations
  float temp1 = readThermistor(ThermistorPin1, R1_T1, c1_T1, c2_T1, c3_T1);
  float temp2 = readThermistor(ThermistorPin2, R1_T2, c1_T2, c2_T2, c3_T2);
 
  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("T1: ");
  lcd.print(temp1, 1);
  lcd.print((char)223); // Degree symbol
  lcd.print("C   ");
 
  lcd.setCursor(0, 1);
  lcd.print("T2: ");
  lcd.print(temp2, 1);
  lcd.print((char)223);
  lcd.print("C   ");
 
  // Also print to Serial Monitor
  Serial.print("Temp1: ");
  Serial.print(temp1);
  Serial.print(" °C, Temp2: ");
  Serial.print(temp2);
  Serial.println(" °C");
 
  // Read potentiometer and update LEDs
  int sensorReading = analogRead(analogPin);
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
 
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], i < ledLevel ? HIGH : LOW);
  }
 
  delay(1000);
}
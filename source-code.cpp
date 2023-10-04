// C++ code
//
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#define WATERPIN 2
#define SENSOR A1
#define MAXDRYNESS 500
#define WATERPOSTDELAY 1000

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
int moisture = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  // Apply power to the soil moisture sensor
  digitalWrite(A0, HIGH);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  // Turn off the sensor to reduce metal corrosion
  // over time
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  if (moisture < 200) {
    digitalWrite(12, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
       digitalWrite(7, HIGH);
  } else {
    if (moisture < 400) {
      digitalWrite(11, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
    } else {
      if (moisture < 600) {
        digitalWrite(10, HIGH);
        digitalWrite(5, LOW);
         digitalWrite(6, LOW);
          digitalWrite(7, LOW);
      } else {
        if (moisture < 800) {
          digitalWrite(9, HIGH);
          digitalWrite(5, LOW);
           digitalWrite(6, LOW);
            digitalWrite(7, LOW);
        } else {
          digitalWrite(8, HIGH);
          digitalWrite(5, LOW);
             digitalWrite(6, LOW);
             digitalWrite(7, LOW);
        }
      }
    }
  }
  delay(100); // Wait for 100 millisecond(s)
}
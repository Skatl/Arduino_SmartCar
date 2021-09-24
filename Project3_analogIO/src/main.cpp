#include <Arduino.h>

int potpin = 0;
int ledpin = 13;
int val = 0;
double v;

void setup()
{
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(ledpin, HIGH);
  delay(50);
  digitalWrite(ledpin, LOW);
  delay(50);
  val = analogRead(potpin);
  v = (val * 5) / 1023;
  Serial.println(val);
  Serial.println(v);
}
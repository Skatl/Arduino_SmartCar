#include <Arduino.h>
int ledpin = 13;
int inpin = 7;
int val;

void setup()
{
  pinMode(ledpin, OUTPUT);
  pinMode(inpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(inpin);
  if (val == LOW)
  {
    digitalWrite(ledpin, LOW);
  }
  else
  {
    digitalWrite(ledpin, HIGH);
  }
}
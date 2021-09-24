#include <Arduino.h>

int interruptPin = 2;
int ledpin = 13;
int period = 500;
void gofast();
void setup()
{

  pinMode(ledpin, OUTPUT);
  pinMode(interruptPin, OUTPUT);
  digitalWrite(interruptPin, HIGH);
  attachInterrupt(0, gofast, FALLING);
}

void loop()
{
  digitalWrite(ledpin, HIGH);
  delay(period);
  digitalWrite(ledpin, LOW);
  delay(period);
}

void gofast()
{
  period = 100;
}
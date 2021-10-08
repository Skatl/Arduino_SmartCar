#include <Arduino.h>
#include <LispMotor.h>

int left1 = 2;
int left2 = 4;
int right1 = 7;
int right2 = 8;
int leftEn = 3;
int rightEn = 5;

LispMotor car(2, 4, 7, 8, 3, 5);

void setup()
{
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(leftEn, OUTPUT);
  pinMode(rightEn, OUTPUT);
}

void loop()
{
  car.control(50, 50);
  delay(2000);
  car.control(0, 50);
  delay(2000);
}
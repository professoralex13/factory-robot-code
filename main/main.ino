#include <math.h>
//{PWMPin, control1, control2}
const int lMotorPins[3] = {3, 4, 5};
const int rMotorPins[3] = {11, 10, 9};

const float PWMMultiplier = 1;

void DriveMotors(int lSpeed, int rSpeed)
{
  analogWrite(lMotorPins[0], fabs(lSpeed * PWMMultiplier));
  analogWrite(rMotorPins[0], fabs(rSpeed * PWMMultiplier));
  if(lSpeed > 0)
  {
    digitalWrite(lMotorPins[1], LOW);
    digitalWrite(lMotorPins[2], HIGH);
  }
  else
  {
    digitalWrite(lMotorPins[1], HIGH);
    digitalWrite(lMotorPins[2], LOW);
  }
  if(rSpeed > 0)
  {
    digitalWrite(rMotorPins[1], LOW);
    digitalWrite(rMotorPins[2], HIGH);
  }
  else
  {
     digitalWrite(rMotorPins[1], HIGH);
     digitalWrite(rMotorPins[2], LOW);
  }
}
void setup() {
  for(int i = 0; i < 3; i++)
  {
    pinMode(lMotorPins[i], OUTPUT);
    pinMode(rMotorPins[i], OUTPUT);
  }
}

void loop() {
  DriveMotors(70, 70);
  delay(500);
  DriveMotors(-70, -70);
  delay(500);
  DriveMotors(70, -70);
  delay(500);
    DriveMotors(-70, 70);
  delay(500);
}

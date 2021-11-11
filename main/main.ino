/** This is the master script for my factory robot for electronics class, it controls all aspects of the robot */
/** Writtern by Alex Cutforth - 2021 */

#include <math.h>

// {PWMPin, control1, control2}
const int lMotorPins[3] = {10, 8, 9};
const int rMotorPins[3] = {5, 7, 6};

const int packageSensorPin = A1;

const int lIrPin = 12;
const int rIrPin = 11;

const int greenLedPin = 2;
const int redLedPin = 3;


const float PWMMultiplier = 1;

void DriveMotors(int lSpeed, int rSpeed)
{
  // Write the PWM signal, fabs keeps the value positive since the lSpeed and rSpeed can be negative, but the sign(positive or negative) of the value is only used for the directional pins
  analogWrite(lMotorPins[0], fabs(lSpeed * PWMMultiplier));
  analogWrite(rMotorPins[0], fabs(rSpeed * PWMMultiplier));

  // Set the direction control pins based on the sign(+ve or -ve) of the speed values
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
  Serial.begin(9600);

  // We can save space by iteratively setting the modes of the motor control pins
  for(int i = 0; i < 3; i++) {
    pinMode(lMotorPins[i], OUTPUT);
    pinMode(rMotorPins[i], OUTPUT);
  }
  
  pinMode(lIrPin, INPUT);
  pinMode(rIrPin, INPUT);
  
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // Less Light due to the package blocking the light means more resistance, using the voltage divider circuit this means a lower value for the analogRead
  const bool hasPackage = analogRead(packageSensorPin) < 300;
  digitalWrite(greenLedPin, hasPackage ? HIGH : LOW);
  
  // IR Sensors will return a HIGH digital value if they detect Black
  const bool lBlack = digitalRead(lIrPin) == HIGH;
  const bool rBlack = digitalRead(rIrPin) == HIGH;
  
  Serial.println(lBlack ? "L is black" : "L is white");
  Serial.println(rBlack ? "R is black" : "R is white");

  // If a given side is black, we set the motors to spin at speed 0, else spin at a speed of 60
  DriveMotors(lBlack ? 0 : 60, rBlack ? 0 : 60);
}

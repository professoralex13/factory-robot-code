/** This Code is used for raw testing, it is designed to have minimal abstraction in order to minimize problems caused by code during the component testing process */
/** Writtern by Alex Cutforth - 2021 */


//{PWMPin, control1, control2}
const int lMotorPins[3] = {3, 4, 5};
const int rMotorPins[3] = {11, 10, 9};


void setup() {
  for(int i = 0; i < 3; i++)
  {
    pinMode(lMotorPins[i], OUTPUT);
    pinMode(rMotorPins[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(lMotorPins[0], 100);
  analogWrite(rMotorPins[0], 100);
  digitalWrite(lMotorPins[1], HIGH);
  digitalWrite(lMotorPins[2], LOW);
   digitalWrite(rMotorPins[1], HIGH);
  digitalWrite(rMotorPins[2], LOW);
  delay(500);
   digitalWrite(lMotorPins[2], HIGH);
  digitalWrite(lMotorPins[1], LOW);
   digitalWrite(rMotorPins[2], HIGH);
  digitalWrite(rMotorPins[1], LOW);
  delay(500);
    digitalWrite(lMotorPins[1], HIGH);
  digitalWrite(lMotorPins[2], LOW);
   digitalWrite(rMotorPins[2], HIGH);
  digitalWrite(rMotorPins[1], LOW);
  delay(500);
    digitalWrite(lMotorPins[2], HIGH);
  digitalWrite(lMotorPins[1], LOW);
   digitalWrite(rMotorPins[1], HIGH);
  digitalWrite(rMotorPins[2], LOW); 
}

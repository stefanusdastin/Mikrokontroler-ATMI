#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution, 22, 24, 26, 28);

const int potPin = A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(30);
  Serial.println("Stepper Sweep with Potensio Meter");
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(potPin);
  int speed = map(potValue, 0, 1023, 1, 20);
  myStepper.setSpeed(speed);
  Serial.print("Pot Value : ");
  Serial.print(potValue);
  Serial.print(" >> Speed : ");
  Serial.println(speed);
  myStepper.step(stepsPerRevolution / 2);
  delay(200);
  myStepper.step(-stepsPerRevolution / 2);
  delay(200);


}

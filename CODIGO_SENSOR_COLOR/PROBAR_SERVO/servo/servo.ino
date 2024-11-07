#include <Servo.h>

Servo ServoMotor;


void setup() {
  // put your setup code here, to run once:
  ServoMotor.attach(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  ServoMotor.write(0);
  delay(2000);
  ServoMotor.write(60);
  delay(2000);
  ServoMotor.write(120);
  delay(2000);
  ServoMotor.write(180);
  delay(2000);

}

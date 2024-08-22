#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor_l(1);
AF_DCMotor motor_r(4);

void setup() {
  motor_l.setSpeed(175);
  motor_r.setSpeed(200);
  motor_l.run(RELEASE);
  motor_r.run(RELEASE);
}

void loop() {
  motor_l.run(FORWARD);
  motor_r.run(FORWARD);

  delay(2000);

  motor_l.run(RELEASE);
  motor_r.run(RELEASE);
  delay(1000);

  motor_l.run(BACKWARD);
  motor_r.run(BACKWARD);
  delay(2000);

  motor_l.run(RELEASE);
  motor_r.run(RELEASE);
  delay(1000);
}

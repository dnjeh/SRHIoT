
#include <AFMotor.h>

AF_DCMotor motor_L(1);
AF_DCMotor motor_R(4);

#define TrigPin A0
#define EchoPin A1;
long duration, distance;

void Obstacle_Check();
void Distance_Measurement();
void Forward();
void Backward();
void Right();
void Left();
void Stop();

void setup() {
  motor_L.setSpeed(0);
  motor_L.run(RELEASE);
  motor_R.setSpeed(0);
  motor_R.run(RELEASE);

  BTSerial.begin(9600);
}

void loop() {
  if(BTSerial.available()) {
    char val = BTSerial.read();
    if(val=='f') go_motor(170);
    else if(val=='b') back_motor(170);
    else if(val=='r') right_motor(150);
    else if(val=='l') left_motor(150);
    else if(val=='s') stop_motor();
    //else stop_motor();
  }
}

void go_motor(uint8_t speedSet) {
  motor_L.setSpeed(speedSet);
  motor_R.setSpeed(speedSet);
  motor_L.run(FORWARD);
  motor_R.run(FORWARD);
}

void back_motor(uint8_t speedSet) {
  motor_L.setSpeed(speedSet);
  motor_R.setSpeed(speedSet);
  motor_L.run(BACKWARD);
  motor_R.run(BACKWARD);
}

void right_motor(uint8_t speedSet) {
  motor_L.setSpeed(speedSet);
  motor_R.setSpeed(speedSet);
  motor_L.run(FORWARD);
  motor_R.run(BACKWARD);
}

void left_motor(uint8_t speedSet) {
  motor_L.setSpeed(speedSet);
  motor_R.setSpeed(speedSet);
  motor_L.run(BACKWARD);
  motor_R.run(FORWARD);
}

void stop_motor() {
  motor_L.run(RELEASE);
  motor_R.run(RELEASE);
}


#include <SoftwareSerial.h>
#include <AFMotor.h>
AF_DCMotor motor_L(1);
AF_DCMotor motor_R(4);

#define Lspeed 170
#define Rspeed 200

#define TrigPin A0
#define EchoPin A1
long duration, distance;

void Obstacle_Check();
void Distance_Measurement();
void Forward();
void Backward();
void Right();
void Left();
void Stop();

void setup() {
  Serial.begin(9600);
  Serial.println("Eduino Smart Car Start!");

  pinMode(EchoPin, INPUT);
  pinMode(TrigPin, OUTPUT);

  motor_L.setSpeed(Lspeed);
  motor_L.run(RELEASE);
  motor_R.setSpeed(Rspeed);
  motor_R.run(RELEASE);
}

void loop() {
  Forward();
  delay(50);
  Obstacle_Check();
}

void Obstacle_Check() {
  int val = random(2);
  Distance_Measurement();
  delay(50);
  Serial.println(distance);
  while(distance < 300) {
    if(distance < 150) {
      Backward();
      delay(800);
      Stop();
      delay(50);
      Distance_Measurement();
      delay(100);
    }
    else {
      if(!val) {
        Right();
        delay(400);
      }
      else {
        Left();
        delay(400);
      }
      Distance_Measurement();
      delay(100);
    }
  }
}
void Distance_Measurement() {
  digitalWrite(TrigPin, LOW);
  delay(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  duration = pulseIn(EchoPin, HIGH);
  distance = ((float)(340*duration)/1000)/2;
  delay(5);
}

void Forward() {
  motor_L.setSpeed(Lspeed);
  motor_R.setSpeed(Rspeed);
  motor_L.run(FORWARD);
  motor_R.run(FORWARD);
}

void Backward() {
  motor_L.setSpeed(Lspeed);
  motor_R.setSpeed(Rspeed);
  motor_L.run(BACKWARD);
  motor_R.run(BACKWARD);
}

void Right() {
  motor_L.setSpeed(Lspeed);
  motor_R.setSpeed(Rspeed);
  motor_L.run(FORWARD);
  motor_R.run(BACKWARD);
}

void Left() {
  motor_L.setSpeed(Lspeed);
  motor_R.setSpeed(Rspeed);
  motor_L.run(BACKWARD);
  motor_R.run(FORWARD);
}

void Stop() {
  motor_L.run(RELEASE);
  motor_R.run(RELEASE);
  motor_L.setSpeed(0);
  motor_R.setSpeed(0);
}

#include <SoftwareSerial.h> 
#define red_pin 7
#define yellow_pin 6
#define green_pin 5
#define blue_pin 4
SoftwareSerial btSerial = SoftwareSerial(9, 10);

void setup()
{
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}

void loop()
{
  if (btSerial.available() > 0)
  {
    char btData = btSerial.read();
    digitalWrite(red_pin, LOW);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(green_pin, LOW);
    digitalWrite(blue_pin, LOW);
    if(btData=='r') {
      digitalWrite(red_pin, HIGH);
    }
    else if(btData=='y') {
      digitalWrite(yellow_pin, HIGH);
    }
    else if(btData=='g') {
      digitalWrite(green_pin, HIGH);
    }
    else if(btData=='b') {
      digitalWrite(blue_pin, HIGH);
    }
  }
  if (Serial.available() > 0)
  {
    btSerial.write(Serial.read());
  }
}

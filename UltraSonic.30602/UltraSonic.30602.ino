int trigPin=3;
int echoPin=2;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340*duration)/10000)/2;
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
}

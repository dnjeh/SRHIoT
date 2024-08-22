void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    char sData= Serial.read();
    if(sData=='a') {
      digitalWrite(3, HIGH);
    }
    else if(sData=='b') {
      digitalWrite(3, LOW);
    }
  }
}

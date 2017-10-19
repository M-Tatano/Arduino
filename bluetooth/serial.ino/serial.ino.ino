
void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == 'n') {
      digitalWrite(13, HIGH);
    } else if(c == 'f') {
      digitalWrite(13, LOW);
    }
  }
}


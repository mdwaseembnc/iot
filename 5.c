int ledPin = 13;
char receivedData;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    receivedData = Serial.read();
    if (receivedData == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    } else if (receivedData == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    } else {
      Serial.println("Invalid Input");
    }
  }
}

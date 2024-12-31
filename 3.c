int intensity;

void setup() {
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  intensity = analogRead(A0);
  intensity = map(intensity, 0, 1023, 0, 255);
  analogWrite(9, intensity);
  delay(1000);
}

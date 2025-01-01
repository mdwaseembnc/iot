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
//2nd code
int ldrPin = A0;
int intensity;

void setup() {
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  intensity = analogRead(ldrPin);
  Serial.print("LDR Intensity: ");
  Serial.println(intensity);
  delay(500);
}

const int trigPin = 7;  
const int echoPin = 10;  
const int buzzer = 11;   
const int ledPin = 13;   

long duration;
int distance;
int safetyDistance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  safetyDistance = distance;
  if (safetyDistance <= 8) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
  }

  Serial.print("Distance: ");
  Serial.println(distance);
}
//2nd code
const int trigPin = 7;  
const int echoPin = 10;  
const int buzzer = 11;   

long duration;
int distance;
int safetyDistance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  safetyDistance = distance;
  if (safetyDistance <= 8) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  Serial.print("Distance: ");
  Serial.println(distance);
}


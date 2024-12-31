void setup() {

pinMode (12, OUTPUT);

digitalWrite(12, Low);

Serial.begin (9600);

}

void loop() {

if (Serial available() >0){

char letter = Serial.read();

if (letter == '1') {

digitalWrite (12, HIGH);

Serial.println("The LED ON");

}
}
}
else if (letter == '0') {

digitalWrite (12, LOW);

Serial.println("The LED of");

else {
  Serial.println("Invalid Input");
}
delay (200) 
}

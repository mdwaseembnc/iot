const int BUTTON_PIN = 7; 
const int LED_PIN    = 3; 

int ledState = LOW;     
int lastButtonState;    
int currentButtonState; 

void setup() {
  Serial.begin(9600);                
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  pinMode(LED_PIN, OUTPUT);          

  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      
  currentButtonState = digitalRead(BUTTON_PIN); 

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState); 
  }
}
.....................................................
  //2nd code

  int ledPin = 7;
int buttonPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}


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

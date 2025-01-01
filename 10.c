#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(7, 8);

void setup() {
  gsmSerial.begin(9600);
  Serial.begin(9600);
  delay(1000);

  gsmSerial.println("AT");
  delay(1000);
  gsmSerial.println("AT+CMGF=1");
  delay(1000);
  gsmSerial.println("AT+CSCS=\"GSM\"");
  delay(1000);

  sendSMS("+1234567890", "Hello from Arduino!");
}

void sendSMS(String phoneNumber, String message) {
  gsmSerial.print("AT+CMGS=\"");
  gsmSerial.print(phoneNumber);
  gsmSerial.println("\"");
  delay(1000);

  gsmSerial.print(message);
  delay(1000);

  gsmSerial.write(26);
  delay(1000);

  Serial.println("Message Sent");
}

void loop() {
  if (gsmSerial.available()) {
    Serial.write(gsmSerial.read());
  }

  if (Serial.available()) {
    gsmSerial.write(Serial.read());
  }
}

//2nd code.........
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);  
  Serial.begin(9600);    
  delay(100);
}

void loop()
{
  if (Serial.available() > 0)
    switch (Serial.read())
    {
      case 's':
        mySerial.println("AT+CMGF=1");
        delay(1000);
        mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
        delay(1000);
        mySerial.println("Technolab creation");
        delay(100);
        mySerial.println((char)26);
        delay(1000);
        break;

      case 'r':
        mySerial.println("AT+CNMI=2,2,0,0,0");
        delay(1000);
        break;
    }

  if (mySerial.available() > 0)
    Serial.write(mySerial.read());
}


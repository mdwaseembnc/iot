#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
RTC_DS3231 rtc;

char daysOfTheWeek[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int Day; 
int Month;
int Year; 
int Secs;
int Minutes;
int Hours;

String dofweek; 
String myDate; 
String myTime; 

#define rs 9 
#define en 8 
#define d4 7 
#define d5 6  
#define d6 5 
#define d7 4 
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup () 
{
  Serial.begin(9600);
  lcd.begin();
  delay(3000); 

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Tech Trends");
  lcd.setCursor(5,1);
  lcd.print("Shameer");
  delay(3000);
  lcd.clear();
}

void loop () 
{
  DateTime now = rtc.now();
  lcd.clear();        
  Day = now.day(); 
  Month = now.month(); 
  Year = now.year();
  Secs = now.second(); 
  Hours = now.hour(); 
  Minutes = now.minute(); 
  dofweek = daysOfTheWeek[now.dayOfTheWeek()];  

  myDate = myDate +dofweek+ " "+ Day + "/" + Month + "/" + Year; 
  myTime = myTime + Hours +":"+ Minutes +":" + Secs; 
  
  Serial.println(dofweek); 
  Serial.println(myDate); 
  Serial.println(myTime);
  
  lcd.setCursor(0,0);
  lcd.print(myDate); 
  lcd.setCursor(0,1); 
  lcd.print("Time:");
  lcd.setCursor(6,1);
  lcd.print(myTime); 
  
  myDate = "";   
  myTime = ""; 
  delay(1000);
}
..............................................................................
// tmep and humidity
#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
byte degree_symbol[8] = 
              {
                0b00111,
                0b00101,
                0b00111,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };

int pinDHT11 = 6;
SimpleDHT11 dht11(pinDHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
  
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print("Read DHT11 failed, err="); 
    Serial.println(err);
    delay(1000);
    return;
  }
  
  lcd.begin();
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("Temperature "); 
  lcd.print((int)temperature);
  
  lcd.setCursor(0, 1);
  lcd.print("Humidity    ");
  lcd.print((int)humidity);
  
  lcd.setCursor(14,0);
  lcd.write(1);
  
  lcd.createChar(1, degree_symbol);
  
  lcd.setCursor(15,0);
  lcd.print("C");
  
  lcd.setCursor(14,1);
  lcd.print("%");
  
  delay(1000);
}

//https://github.com/Tech-Trends-Shameer/Arduino-Projects/tree/main/Temperature-and-Humidity-Monitor

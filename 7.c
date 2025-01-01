#include<Stepper.h>
Stepper myStepper(2048,8,10,9,11);
int motorspeed=10;
void setup(){
myStepper.setSpeed(motorspeed);
}
void loop(){
myStepper.step(2048);
delay(1000);
myStepper.step(-2048);
delay(1000);
}
.............................................................
//dc motor
void setup(){
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
}
void loop(){
{
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
delay(1000);
}
{
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
delay(1000);
}
}

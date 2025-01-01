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

//2nd code without libray!!!!

int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;

int stepSequence[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};

int stepDelay = 2;
int stepIndex = 0;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() {
  for (int i = 0; i < 100; i++) {
    stepMotor(1);
    delay(stepDelay);
  }
  
  delay(1000);

  for (int i = 0; i < 100; i++) {
    stepMotor(-1);
    delay(stepDelay);
  }
  
  delay(1000);
}

void stepMotor(int direction) {
  if (direction == 1) {
    stepIndex++;
    if (stepIndex >= 4) {
      stepIndex = 0;
    }
  } else if (direction == -1) {
    stepIndex--;
    if (stepIndex < 0) {
      stepIndex = 3;
    }
  }

  digitalWrite(motorPin1, stepSequence[stepIndex][0]);
  digitalWrite(motorPin2, stepSequence[stepIndex][1]);
  digitalWrite(motorPin3, stepSequence[stepIndex][2]);
  digitalWrite(motorPin4, stepSequence[stepIndex][3]);
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

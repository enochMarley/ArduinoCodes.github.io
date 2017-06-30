#include <NewPing.h>
#include <Servo.h>  
     
#define TRIGGER_PIN  13
#define ECHO_PIN     12
#define MAX_DISTANCE 200

Servo servo; //initialize a servo object for the connected servo  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int angle = 90;

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(11);

  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(0);
  analogWrite(enA,50);
  analogWrite(enB,50);

  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

  analogWrite(enA,20);
  analogWrite(enB,20);

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  analogWrite(enA,50);
  analogWrite(enB,50);
  servo.write(90);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);

  delay(2000);
}

void moveForward(){
  analogWrite(enA,50);
  analogWrite(enB,50);

  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

  delay(4000);
}

void moveBack(){
  analogWrite(enA,100);
  analogWrite(enB,100);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void brake(){
  analogWrite(enA,0);
  analogWrite(enB,0);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}


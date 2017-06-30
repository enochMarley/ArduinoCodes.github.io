int enA = 10;
int in1 = 9;
int in2 = 8;

int enB = 5;
int in3 = 6;
int in4 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}

void _mBackward()
{
analogWrite (enA, 200); //DOLOČIŠ HTROST MOTORJA
digitalWrite(enA,HIGH);
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);

analogWrite (enB, 300);
digitalWrite(enB,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);

Serial.println("go Backward!");
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
// set speed to 200 out of possible range 0~255

}

void _mForward()
{
analogWrite (enA, 200); //DOLOČIŠ HTROST MOTORJA
digitalWrite(enA,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in1,HIGH);

analogWrite (enB, 300);
digitalWrite(enB,HIGH);
digitalWrite(in4,HIGH);
digitalWrite(in3,LOW);

Serial.println("go Forward!");
digitalWrite(in2, HIGH);
digitalWrite(in1, LOW);
// set speed to 200 out of possible range 0~255

}

void _break(){
  digitalWrite(enA,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in1,LOW);
  
  digitalWrite(enB,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in3,LOW);
  Serial.println("Breaking");
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  _mBackward();
  delay(4000);

  _break();
  delay(3000);
  
  _mForward();
  delay(4000);
}

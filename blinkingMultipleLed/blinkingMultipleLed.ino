// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11
//#define BLUE_LED 7
int red_on = LOW;
int yellow_on = LOW;
int green_on = LOW;
//int blue_on = LOW;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  //pinMode(BLUE_LED, OUTPUT);
  digitalWrite(RED_LED, red_on);
  digitalWrite(YELLOW_LED, yellow_on);
  digitalWrite(GREEN_LED, green_on);
  //digitalWrite(BLUE_LED, blue_on);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); 
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); // turn the LED on (HIGH is the voltage level)
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(1000); 
  digitalWrite(GREEN_LED, LOW);
}

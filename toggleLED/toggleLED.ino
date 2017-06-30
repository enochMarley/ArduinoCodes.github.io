//define digital pin numbers as constants
#define RED_LED 13 
#define YELLOW_LED 12
#define GREEN_LED 11
//#define BLUE_LED 10

//define the voltage state of all the digital pins as low
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
  
  //Pass the voltages initialized to the digital pins
  digitalWrite(RED_LED, red_on);
  digitalWrite(YELLOW_LED, yellow_on);
  digitalWrite(GREEN_LED, green_on);
  //digitalWrite(BLUE_LED, blue_on);
  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  if(Serial.available()){ //if something has been typed into the serial buffer
    char readLED = Serial.read(); //read what has been typed
    
    if(readLED == 'r'){ //if 'r' is typed in,
      //if the voltage state of red_on is HIGH, set it to LOW, else if it is LOW, let it be HIGH
      red_on = (red_on == HIGH) ? LOW : HIGH; 
      printLEDState(readLED, red_on); //print the LED state of the Red LED.
      
    }else if(readLED == 'y'){ //if 'y' is typed in,
      //if the voltage state of yellow_on is HIGH, set it to LOW, else if it is LOW, let it be HIGH
      yellow_on = (yellow_on == HIGH) ? LOW : HIGH;
      printLEDState(readLED, yellow_on); //print the LED state of the Yellow LED.
      
    }else if(readLED == 'g'){ //if 'g' is typed in,
      //if the voltage state of green_on is HIGH, set it to LOW, else if it is LOW, let it be HIGH
      green_on = (green_on == HIGH) ? LOW : HIGH;
      printLEDState(readLED, green_on); //print the LED state of the Green LED.
      
    } /*else  if(readLED == 'b'){ //if 'b' is typed in,
      //if the voltage state of blue_on is HIGH, set it to LOW, else if it is LOW, let it be HIGH
      blue_on = (blue_on == HIGH) ? LOW : HIGH;
      printLEDState(readLED, blue_on); //print the LED state of the Blue LED.
    }*/else{
      Serial.println("Incorrect input.Enter either 'r','y','g' or 'b'.");
    }
  }
  
  //Rewrite all the voltages to the digital pins again
  digitalWrite(RED_LED, red_on);
  digitalWrite(YELLOW_LED, yellow_on);
  digitalWrite(GREEN_LED, green_on);
  //digitalWrite(BLUE_LED, blue_on);
}


//the function to print the LED state (whether it is on or off)
//takes two parameters, the letter typed in by a user, and the voltage level
void printLEDState(char LED, int state){ 
 
  //if the voltage is low is HIGH, assign '1' (on) to it, else assign '0' (off to it)
  state = (state == HIGH) ? '1' : '0';
  
  //if the state is '1' (or HIGH or on)
  if(state == '1'){
    //print to the serial monitor the led color and the state as on
    if(LED == 'r')Serial.println("Red LED is on");
    if(LED == 'y')Serial.println("Yellow LED is on");
    if(LED == 'g')Serial.println("Green LED is on");
    //if(LED == 'b')Serial.println("Blue LED is on");
  }
  
  //if the state is '0' (or LOW or off)
   if(state == '0'){
     
     //print to the serial monitor the led color and the state as off
    if(LED == 'r')Serial.println("Red LED is off");
    if(LED == 'y')Serial.println("Yellow LED is off");
    if(LED == 'g')Serial.println("Green LED is off");
    //if(LED == 'b')Serial.println("Blue LED is off");
  }
}                     

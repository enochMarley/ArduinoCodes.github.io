    #include <NewPing.h>
    #include <Servo.h>  
     
    #define TRIGGER_PIN  13
    #define ECHO_PIN     12
    #define MAX_DISTANCE 200

    Servo servo_test;        //initialize a servo object for the connected servo  
                
    int angle = 0;
     
    NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
     
    void setup() {
      pinMode(TRIGGER_PIN, OUTPUT);
      pinMode(ECHO_PIN, INPUT);
      Serial.begin(9600);
      servo_test.attach(9);
    }
     
    void loop() {
      for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
      {                                  
        servo_test.write(angle);                 //command to rotate the servo to the specified angle
        Serial.print("Obstacle is ");
        Serial.print(sonar.ping_cm());
        Serial.print(" cm away at an angle of ");
        Serial.print(angle);
        Serial.println(" degrees");
        delay(50);                       
      } 
     
      delay(1000);
      
      for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
      {                                
        servo_test.write(angle);              //command to rotate the servo to the specified angle
        Serial.print("Obstacle is ");
        Serial.print(sonar.ping_cm());
        Serial.print(" cm away at an angle of ");
        Serial.print(angle);
        Serial.println(" degrees");
        delay(50);                       
      } 
    
        delay(1000);
      
 
    }


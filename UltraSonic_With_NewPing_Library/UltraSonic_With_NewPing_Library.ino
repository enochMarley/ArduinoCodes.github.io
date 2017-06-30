    #include <NewPing.h>
     
    #define TRIGGER_PIN  13
    #define ECHO_PIN     12
    #define MAX_DISTANCE 200
     
    NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
     
    void setup() {
      pinMode(TRIGGER_PIN, OUTPUT);
      pinMode(ECHO_PIN, INPUT);
      Serial.begin(9600);
    }
     
    void loop() {
      delay(50);
      Serial.print("Obstacle is ");
      Serial.print(sonar.ping_cm());
      Serial.println(" cm away");
    }


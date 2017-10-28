#include <Servo.h>

Servo myservo;

volatile unsigned long period;
volatile boolean done;
unsigned long start;

unsigned long currentMillis;

long previousMillis = 0;    // set up timers
long interval = 50;        // time constant for timers
void setup() {

  Serial.begin(57600);

  pinMode(2, INPUT);
  attachInterrupt(1, go, CHANGE);

  myservo.attach(2);


}



void loop() {

   currentMillis = millis();
         if (currentMillis - previousMillis >= interval) {  //start timed event
            previousMillis = currentMillis;


            if (!done)
              return;
            Serial.println (period);
            myservo.writeMicroseconds(period);
            done = false;

         } // end of timed event
}




void go() {


  if (digitalRead(3) == HIGH) {
    start = micros();
  }
  else {
    period = micros() - start;
    done = true;
  }
}






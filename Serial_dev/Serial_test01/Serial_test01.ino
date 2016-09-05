char iam = 'a';     // unique name
char ident;        // start data
char ident2;      //end data

int read1 = 0;
int read2 = 0;
int var1 = 0;
int var2 = 0;
int count = 0;

unsigned long previousMillis = 0;
const long interval = 10;
unsigned long lastDataTime;

void setup() {
        Serial1.begin(115200);     // opens serial port
        Serial.begin(115200);     // opens serial port

        pinMode(13,OUTPUT);
        digitalWrite(13,LOW);
}

void loop() {

   unsigned long currentMillis = millis();
     if (currentMillis - previousMillis >= interval) {  //start timed event
        previousMillis = currentMillis;

        if (Serial1.available()>=24) {  // check for enough serial data
                // read the incoming byte:
                ident = Serial1.read();
                read1 = Serial1.parseInt();
                read2 = Serial1.parseInt();
                ident2 = Serial1.read();

                if (ident == iam && ident2 == iam) {  // check data is for this device and in the right order
                    lastDataTime = millis(); // bookmark the time for safties                 
                    var1 = read1;   // if the data is right update to main loop variables
                    var2 = read2;   
                } 
        }

      if (millis() - lastDataTime <= 200) {  //saftey check - proceed if data is current enough
                              
              // main code goes in here
              digitalWrite(13,LOW); // LED off
              Serial.print(var1);
              Serial.print(" , ");
              Serial.print(var2);
              Serial.print(" , ");
              Serial.println(count);
              count = count+1;






              
              
              }   // end of main code
              
      else if (millis() - lastDataTime > 200) {  // safety check - do whatever because data has stopped
        
      // error state code goes here
                     
        Serial.println("error state");
        digitalWrite(13,HIGH);  //  LED on

      }  // end of error state - emergency stop etc

     }  // end of timed event
     
} //end of main loop

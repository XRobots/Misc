int var1 = 1;
int var2 = 1;

char youareA = 'a';  //identifiers for each slave device
char youareB = 'b';
char youareC = 'a';
char youareD = 'b';

unsigned long previousMillis = 0;
const long interval = 20;

void setup() {
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {
     unsigned long currentMillis = millis();
     if (currentMillis - previousMillis >= interval) {  // start timed event
        previousMillis = currentMillis;

  Serial1.print(youareA);  // send identifier
  Serial1.print(" , ");
  Serial1.print(var1);
  Serial1.print(" , ");
  Serial1.print(var2);
  Serial1.print(youareA);  // send identifier

  var1 = var1+1;           //modify data for testing
  var2 = var2-1;

     }

}

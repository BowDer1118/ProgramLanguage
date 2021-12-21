// Arduino code
int buttonState = 0;
int lastButtonState = 0;
int switchPin = 4; // Switch connected to pin 4
void setup() {
pinMode(switchPin, INPUT); // Set pin 0 as an input
Serial.begin(9600); // Start serial communication at 9600 bps
}
void loop() {
 int val;
 buttonState =digitalRead(switchPin);

if (buttonState != lastButtonState) { // If switch is ON,
  if (buttonState == HIGH)
     val=1;
   else  // If the switch is not ON,
     val=0;
Serial.write(val);
//Serial.println(val);
}

lastButtonState = buttonState;
delay(100); // Wait 100 milliseconds
}
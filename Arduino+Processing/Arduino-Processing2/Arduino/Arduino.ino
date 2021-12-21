int buttonState1 = 0;
int lastButtonState1 = 0;

int buttonState2 = 0;
int lastButtonState2 = 0;

int switchPin1 = 4; // Switch connected to pin 4
int switchPin2 = 3;
void setup() {
pinMode(switchPin1, INPUT);
pinMode(switchPin2, INPUT);// Set pin 0 as an input
Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
int i, j, k;

buttonState1=digitalRead(switchPin1);
buttonState2=digitalRead(switchPin2);


if (buttonState1 != lastButtonState1)
if (buttonState1 == HIGH) { // If switch is ON,
i=1;
} else { // If the switch is not ON,
i=0;
}

if (buttonState2 != lastButtonState2)
if (buttonState2 == HIGH) { // If switch is ON,
j=1;
} else { // If the switch is not ON,
j=0;
}

if (i==0 && j==0)
k =0;
if (i==1 && j==0)
k =1;
if (i==0 && j==1)
k =2;
if (i==1 && j==1)
k =3;

if (buttonState1 != lastButtonState1 || buttonState2 != lastButtonState2)
  Serial.write(k);

lastButtonState1 = buttonState1;
lastButtonState2 = buttonState2;

delay(100); // Wait 100 milliseconds
}
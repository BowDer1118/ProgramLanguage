int speakerOut = 12;
int freq;

void setup() {
  pinMode(speakerOut, OUTPUT);
  
}

void loop() {

freq = 2028;

digitalWrite(speakerOut,HIGH);
delayMicroseconds(freq / 2);
digitalWrite(speakerOut, LOW);
delayMicroseconds(freq / 2);

}

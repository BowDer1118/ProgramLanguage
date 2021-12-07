int bs1,bs2,bs3;
const int freq1=2864;
const int freq2=2550;
const int freq3=2272;

void setup() {
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  bs1=digitalRead(1);
  bs2=digitalRead(2);
  bs3=digitalRead(3);
  if(bs1==HIGH){
    digitalWrite(12,HIGH);
    delayMicroseconds(freq1 / 2);
    digitalWrite(12, LOW);
    delayMicroseconds(freq1 / 2);
  }
  if(bs2==HIGH){
    digitalWrite(12,HIGH);
    delayMicroseconds(freq2 / 2);
    digitalWrite(12, LOW);
    delayMicroseconds(freq2 / 2);
  }
  if(bs3==HIGH){
    digitalWrite(12,HIGH);
    delayMicroseconds(freq3 / 2);
    digitalWrite(12, LOW);
    delayMicroseconds(freq3 / 2);
  }
}

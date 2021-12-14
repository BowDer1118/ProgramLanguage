
int photocellPin = 2; // 光敏電阻 (photocell) 接在 anallog pin 2
int photocellVal = 0; // photocell variable
const int ledPin=8;
const int speakerPin=13;
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(speakerPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 讀取光敏電阻並輸出到 Serial Port 
  photocellVal = analogRead(photocellPin);
  Serial.println(photocellVal);  
  if(photocellVal<400){
    digitalWrite(ledPin,HIGH);
    delay(200);
  }else{
    digitalWrite(ledPin,LOW);
  }

  if(photocellVal>900){
    digitalWrite(speakerPin,HIGH);
    delayMicroseconds(2028/2);
    digitalWrite(speakerPin,LOW);
    delayMicroseconds(2028/2);
  }
  
  
}

/*
  900 火警
  700 正常
  <400 LED亮
*/

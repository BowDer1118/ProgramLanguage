
int photocellPin = 2; // 光敏電阻 (photocell) 接在 anallog pin 2
int photocellVal = 0; // photocell variable

void setup() {
  Serial.begin(9600);
}

void loop() {
  // 讀取光敏電阻並輸出到 Serial Port 
  photocellVal = analogRead(photocellPin);
  Serial.println(photocellVal);  
  delay(100);       
}

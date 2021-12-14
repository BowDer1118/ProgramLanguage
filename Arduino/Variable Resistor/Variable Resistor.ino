const byte analogPin = A0;

int value;

void setup() {

  Serial.begin(9600);

}

 

void loop() {

  value = analogRead(analogPin);

  Serial.println(value);

  delay(500);

}
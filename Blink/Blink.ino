/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for(int i=1;i<=5;i++){
    pinMode(i,OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  //PartA:全亮全暗
  for(int i=0;i<5;i++){
    for(int j=1;j<=5;j++){
      digitalWrite(j,HIGH);
    }
    delay(500);
     for(int j=1;j<=5;j++){
      digitalWrite(j,LOW);
    }
    delay(500);
  }
  //PartB:左到右依次亮
  delay(1000);
  for(int i=0;i<5;i++){
    for(int j=1;j<=5;j++){
      digitalWrite(j,HIGH);
      delay(100);
    }
    delay(300);
    for(int j=5;j>=1;j--){
      digitalWrite(j,LOW);
      delay(100);
    }
    delay(500);
  }
  delay(1000);
  //左到右 右到左
  for(int i=0;i<5;i++){
    for(int j=1;j<=5;j++){
      digitalWrite(j,HIGH);
      delay(200);
      digitalWrite(j,LOW);
    }
    for(int j=5;j>=1;j--){
      digitalWrite(j,HIGH);
      delay(200);
      digitalWrite(j,LOW);
    }
  }
  delay(1000);
}

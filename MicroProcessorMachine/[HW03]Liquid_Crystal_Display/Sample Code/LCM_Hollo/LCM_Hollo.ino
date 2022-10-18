/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);
  pinMode(BT4, INPUT);
  //pinMode(A0, INPUT);
  //pinMode(A1, INPUT);
  //pinMode(A2, INPUT);
  //pinMode(A3, INPUT);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("2021 Hello World!");
  lcd.setCursor(0, 1);
  lcd.print("Wellcom to Andes!");
}
int buttonState1,buttonState2,buttonState3,buttonState4 = 0;                                                 
int delay_number = 100;

void loop() {
  buttonState1 = digitalRead(BT1);
  buttonState2 = digitalRead(BT2);
  buttonState3 = digitalRead(BT3);
  buttonState4 = digitalRead(BT4);
if (buttonState1 == LOW) {
  // Serial.println("button A0 is pressed");
   //digitalWrite(LED1, LOW);
   lcd.clear();
   lcd.print("BT1 is pressed!");
    delay(delay_number);
}  else if (buttonState2 == LOW) {
    //Serial.println("button2 is pressed");
    //digitalWrite(LED2, LOW);
    lcd.clear();
    lcd.print("BT2");
     delay(delay_number);
}  else if (buttonState3 == LOW) {
     //Serial.println("button3 is pressed");
     //digitalWrite(LED3, LOW);
     lcd.clear();
     lcd.print("BT3");
     delay(delay_number);                    
} else if (buttonState4 == LOW) {             
     //Serial.println("button4 is pressed");
     //digitalWrite(LED4, LOW);
     lcd.clear();
     lcd.print("BT4");
     delay(delay_number);    
    }

  
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}



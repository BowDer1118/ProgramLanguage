/*

  LiquidCrystal Library - Autoscroll

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal

 library works with all LCD displays that are compatible with the

 Hitachi HD44780 driver. There are many of them out there, and you

 can usually tell them by the 16-pin interface.

 This sketch demonstrates the use of the autoscroll()

 and noAutoscroll() functions to make new text scroll or not.

 The circuit:

 * LCD RS pin to digital pin 8

 * LCD Enable pin to digital pin 9

 * LCD D4 pin to digital pin 4

 * LCD D5 pin to digital pin 5

 * LCD D6 pin to digital pin 6

 * LCD D7 pin to digital pin 7

 * LCD R/W pin to ground

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

 modified 7 Nov 2016

 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  // set up the LCD's number of columns and rows:

  lcd.begin(16, 2);
}

void loop() {

  // set the cursor to (0,0):

  lcd.setCursor(0, 0);
  lcd.cursor();

  // print from 0 to 9:

  for (int thisChar = 0; thisChar < 10; thisChar++) {

    lcd.print(thisChar);

    delay(500);

  }

  // set the cursor to (16,1):

  lcd.setCursor(10, 1);

  // set the display to automatically scroll:
  /*rightToLeft()+autoscroll()會造成cursor不會動新的數值最靠近cursor*/
  lcd.rightToLeft(); //數字從右邊往左邊擠
  lcd.autoscroll(); //cursor不會被數字推走

  // print from 0 to 9:

  for (int thisChar = 0; thisChar < 10; thisChar++) {

    lcd.print(thisChar);

    delay(500);

  }

  // turn off automatic scrolling

  lcd.noAutoscroll();

  // clear screen for the next loop:

  lcd.clear();
}

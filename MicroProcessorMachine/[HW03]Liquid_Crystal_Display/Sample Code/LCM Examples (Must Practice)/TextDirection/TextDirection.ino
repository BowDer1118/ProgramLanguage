/*

 LiquidCrystal Library - TextDirection

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal

 library works with all LCD displays that are compatible with the

 Hitachi HD44780 driver. There are many of them out there, and you

 can usually tell them by the 16-pin interface.

 This sketch demonstrates how to use leftToRight() and rightToLeft()

 to move the cursor.

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

 http://www.arduino.cc/en/Tutorial/LiquidCrystalTextDirection

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int thisChar = 'a';

void setup() {

  // set up the LCD's number of columns and rows:

  lcd.begin(16, 2);

  // turn on the cursor:

  lcd.cursor();
}

void loop() {

  // reverse directions at 'm':

  if (thisChar == 'm') {

    // go right for the next letter

    lcd.rightToLeft();

  }

  // reverse again at 's':

  if (thisChar == 's') {

    // go left for the next letter

    lcd.leftToRight();

  }

  // reset at 'z':

  if (thisChar > 'z') {

    // go to (0,0):

    //lcd.home();
    lcd.clear();

    // start again at 0

    thisChar = 'a';

  }

  // print the character

  lcd.write(thisChar);

  // wait a second:

  delay(500);

  // increment the letter:

  thisChar++;
}

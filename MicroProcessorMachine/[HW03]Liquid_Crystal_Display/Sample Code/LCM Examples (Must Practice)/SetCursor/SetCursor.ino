/*

  LiquidCrystal Library - setCursor

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal

 library works with all LCD displays that are compatible with the

 Hitachi HD44780 driver. There are many of them out there, and you

 can usually tell them by the 16-pin interface.

 This sketch prints to all the positions of the LCD using the

 setCursor() method:

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

 http://www.arduino.cc/en/Tutorial/LiquidCrystalSetCursor

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// these constants won't change.  But you can change the size of
// your LCD using them:

const int numRows = 2;

const int numCols = 16;

void setup() {

  // set up the LCD's number of columns and rows:

  lcd.begin(numCols, numRows);
}

void loop() {

  // loop from ASCII 'a' to ASCII 'z':

  for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {

    // loop over the columns:

    for (int  thisRow = 0; thisRow < numRows; thisRow++) {

      // loop over the rows:

      for (int thisCol = 0; thisCol < numCols; thisCol++) {

        // set the cursor position:

        lcd.setCursor(thisCol, thisRow);

        // print the letter:

        lcd.write(thisLetter);

        delay(200);

      }

    }

  }
}


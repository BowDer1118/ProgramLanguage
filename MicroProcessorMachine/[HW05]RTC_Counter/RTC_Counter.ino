// include the library code:
#include <LiquidCrystal.h>
#include <RTC.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/* Button1~Button4*/
int buttonState1, buttonState2, buttonState3, buttonState4 = 0;

/* Change these values to set the current initial time */
int month = 11;
int seconds = 55;
int minutes = 59;
int hours = 11;
int day = 22;
char timeBuffer[17];

/*紀錄碼表狀態*/
String countingState;
int countingHour, countingMin, countingSecond;



void setup() {
  /*BT1~BT4*/
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);
  pinMode(BT4, INPUT);

  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // set the time and start counting
  RTC.settime(day, hours, minutes, seconds);
  RTC.startcounting();

  countingState = "Term";
  countingHour = 0;
  countingMin = 0;
  countingSecond = 0;
}

void loop() {
  hours = RTC.gethours();
  minutes = RTC.getminutes();
  seconds = RTC.getseconds();
  day = RTC.getday();

  buttonState1 = digitalRead(BT1);
  buttonState2 = digitalRead(BT2);
  buttonState3 = digitalRead(BT3);
  buttonState4 = digitalRead(BT4);

  /*輸出時間*/
  lcd.setCursor(0, 0);
  //使用sprintf進行字串格式轉換
  sprintf(timeBuffer, "%02d/%02d   %02d:%02d:%02d", month, day, hours, minutes, seconds);
  lcd.print(timeBuffer);

  /*檢查按鈕是否被按下*/
  if (buttonState1 == LOW || buttonState2 == LOW) {
    countingState = "Stop";
  } else if (buttonState3 == LOW) {
    countingState = "Term";
  } else if (buttonState4 == LOW) {
    if (countingState == "Count") {
      countingState = "Pause";
      //補償該秒未計時
      doCounting();
    } else {
      countingState = "Count";
    }
  }

  /*依照狀態處理事件*/
  if (countingState != "Term") {
    if (countingState == "Count") {
      doCounting();
    } else if (countingState == "Stop") {
      countingHour = 0;
      countingMin = 0;
      countingSecond = 0;
    }
    sprintf(timeBuffer, "%02d:%02d:%02d   %5s", countingHour, countingMin, countingSecond, countingState.c_str());
    lcd.setCursor(0, 1);
    lcd.print(timeBuffer);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    countingHour = 0;
    countingMin = 0;
    countingSecond = 0;
  }

  delay(1000);
}

void doCounting() {
  /*處理計時狀態*/
  countingSecond += 1;
  if (countingSecond == 60) {
    countingSecond = 0;
    countingMin += 1;
  }
  if (countingMin == 60) {
    countingMin = 0;
    countingHour += 1;
  }
  if (countingHour == 24) {
    countingHour = 0;
  }
}

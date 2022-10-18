/*Created by ACET and Modified by 黃寶德*/
#include <LiquidCrystal.h>
#define DELAY_TIME 300
/*BT1~BT4*/
int buttonState1, buttonState2, buttonState3, buttonState4 = 0;

/*紀錄keyPad按鈕是否有功能*/
const bool IS_USE[] =
{
  true, false, false, true, // 1 2 3 A
  true, false, false, false, // 4 5 6 B
  false, false, false, false, // 7 8 9 C
  false, false, false, true, // * 0 # D
};
/*按鈕輸入檢查與位置紀錄*/
byte Row = 0, Col = 0;  //表示當前輸入的key_pads座標
byte Pad_Index; //紀錄位置

/*實例化LiquidCrystal物件*/
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/*要輸出的字串*/
const String str1 = "This is the first string with 40 bytes!!";
const String str2 = "And the second string also has 40 bytes!";

/*紀錄Cursor狀態*/
bool CurSorIsOn;

bool keyScan() {
  Row = 0;
  Col = 0;

  /* scan 第0個Col */
  digitalWrite(A0, LOW);  //將A0接地
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  /* 依次讀取第0~3個Row對應到的D10~D13腳位 */

  if (digitalRead(D10) == LOW) {  //讀取第0個Row:讀取D10腳位
    digitalWrite(A0, HIGH);       //取消讀取第0個Col
    Row = 0;
    Col = 0;
    return true;
  }

  if (digitalRead(D11) == LOW) {  //讀取第1個Row:讀取D11腳位
    digitalWrite(A0, HIGH);
    Row = 1;
    Col = 0;
    return true;
  }

  if (digitalRead(12) == LOW) {  //讀取第2個Row:讀取D12腳位
    digitalWrite(A0, HIGH);
    Row = 2;
    Col = 0;
    return true;
  }

  if (digitalRead(13) == LOW) {  //讀取第3個Row:讀取D13腳位
    digitalWrite(A0, HIGH);
    Row = 3;
    Col = 0;
    return true;
  }

  /* scan 第1個Col */
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);  //將A1接地
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  if (digitalRead(10) == LOW) {
    digitalWrite(A1, HIGH);
    Row = 0;
    Col = 1;
    return true;
  }

  if (digitalRead(11) == LOW) {
    digitalWrite(A1, HIGH);
    Row = 1;
    Col = 1;
    return true;
  }

  if (digitalRead(12) == LOW) {
    digitalWrite(A1, HIGH);
    Row = 2;
    Col = 1;
    return true;
  }

  if (digitalRead(13) == LOW) {
    digitalWrite(A1, HIGH);
    Row = 3;
    Col = 1;
    return true;
  }

  /* scan 第2個Col */
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  if (digitalRead(10) == LOW) {
    digitalWrite(A2, HIGH);
    Row = 0;
    Col = 2;
    return true;
  }

  if (digitalRead(11) == LOW) {
    digitalWrite(A2, HIGH);
    Row = 1;
    Col = 2;
    return true;
  }

  if (digitalRead(12) == LOW) {
    digitalWrite(A2, HIGH);
    Row = 2;
    Col = 2;
    return true;
  }

  if (digitalRead(13) == LOW) {
    digitalWrite(A2, HIGH);
    Row = 3;
    Col = 2;
    return true;
  }

  /* scan 第3個Col */
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  delayMicroseconds(100);

  if (digitalRead(10) == LOW) {
    digitalWrite(A3, HIGH);
    Row = 0;
    Col = 3;
    return true;
  }

  if (digitalRead(11) == LOW) {
    digitalWrite(A3, HIGH);
    Row = 1;
    Col = 3;
    return true;
  }

  if (digitalRead(12) == LOW) {
    digitalWrite(A3, HIGH);
    Row = 2;
    Col = 3;
    return true;
  }

  if (digitalRead(13) == LOW) {
    digitalWrite(A3, HIGH);
    Row = 3;
    Col = 3;
    return true;
  }
  //都沒有按下
  return false;
}

/*控制第一組文字顯示在第一列*/
void displayOnLine1() {
  lcd.setCursor(0, 0);
  lcd.print(str1);
}

/*控制第二組文字顯示在第二列*/
void displayOnLine2() {
  lcd.setCursor(0, 1);
  lcd.print(str2);
}

/*控制文字左移*/
void doLeftShift() {
  lcd.autoscroll();
  for (int i = 0; i < 40; i++) {
    lcd.scrollDisplayLeft();
    delay(DELAY_TIME);
  }
  lcd.noAutoscroll();
}

/*控制文字右移*/
void doRightShift() {
  lcd.autoscroll();
  for (int i = 0; i < 40; i++) {
    lcd.scrollDisplayRight();
    delay(DELAY_TIME);
  }
  lcd.noAutoscroll();
}

/*控制Clear Display*/
void ClearDisplay() {
  lcd.clear();
}

/*控制 Return Home*/
void ReturnHome() {
  lcd.home();
}

/*控制Cursor on/off*/
void ChangeCursorDisplayMode() {
  if (!CurSorIsOn) {
    lcd.cursor();
    CurSorIsOn = true;
  } else {
    lcd.noCursor();
    CurSorIsOn = false;
  }
}

void setup() {
  /*BT1~BT4*/
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);
  pinMode(BT4, INPUT);

  /*KeyPad:Set Read and Write IO*/
  //對照電路圖:要加電的腳位設定為輸出腳位(用來檢查每個Col)
  pinMode(A0, OUTPUT);  // A1
  pinMode(A1, OUTPUT);  // A2
  pinMode(A2, OUTPUT);  // A3
  pinMode(A3, OUTPUT);  // A4

  //對照電路圖:要讀取的腳位(用來讀取每個Row哪個案件被按下)
  pinMode(D10, INPUT);         // Row 0: (1,2,3,A)
  pinMode(D11, INPUT_PULLUP);  // R1:(4,5,6,B)
  pinMode(D12, INPUT_PULLUP);  // R2:(7,8,9,C)
  pinMode(D13, INPUT_PULLUP);  // R3:(*,0,#,D)

  lcd.begin(16, 2);
  CurSorIsOn = false;
}

void loop() {
  buttonState1 = digitalRead(BT1);
  buttonState2 = digitalRead(BT2);
  buttonState3 = digitalRead(BT3);
  buttonState4 = digitalRead(BT4);

  if (buttonState1 == LOW) {
   ClearDisplay();
   delay(DELAY_TIME);
  } else if (buttonState2 == LOW) {
    ReturnHome();
    delay(DELAY_TIME);
  } else if (buttonState4 == LOW) {
    ChangeCursorDisplayMode();
    delay(DELAY_TIME);
  }
  
  if (keyScan()) {
    Pad_Index = Row * 4 + Col;
    if (IS_USE[Pad_Index]) { //檢查按下的按鈕有沒有功能
      if (Pad_Index == 0) { //按下按鈕1
        displayOnLine1();
      } else if (Pad_Index == 3) {
        displayOnLine2();
      } else if (Pad_Index == 4) {
        doLeftShift();
      } else if (Pad_Index == 15) {
        doRightShift();
      }
    }
    delay(DELAY_TIME);
  }

}

/*Created by ACET-Tec and Modified by 黃寶德*/

/* Define shift register pins used for seven segment display */
#define LATCH_DIO D15  //電路圖:控制暫存器要在何時工作的CLOCK LCHCLK的腳位是D15 (racing edge triggered or falling edge triggered)
#define CLK_DIO D14    //電路圖:控制資料輸入的CLOCK SFTCLK的腳位
#define DATA_DIO D2    //電路圖:資料輸入的腳位D2
#define DELAY_TIME 250 //定義延遲時間

/* Segment Display MSB: dp g f e d c b a */
//參考7-segment圖形:https://en.wikipedia.org/wiki/Seven-segment_display

//Seven Segment Display digital number graph
const byte SEGMENT_MAP[] = {
  0x06, 0x5B, 0x4F, 0x00,  // 1 2 3 X
  0x66, 0x6D, 0x7D, 0x00,  // 4 5 6 X
  0x07, 0x7F, 0x6F, 0x00,  // 7 8 9 X
  0x00, 0x3F, 0x00, 0x00,  // X 0 L R
};
const byte DP = 0x80;  // Digit Point


/* Decoder Byte maps to select digit 1 to 4 (左到右) */    // 0111 1011 1101 1110
const byte SEGMENT_SELECT[] = { 0x0E, 0x0D, 0x0B, 0x07 };  // {0xFE,0xFD,0xFB,0xF7};  is OK, too.

/* 按鈕輸入檢查與位置紀錄 */
byte Row = 0, Col = 0;  //表示當前輸入的key_pads座標
byte Pad_Index; //紀錄位置

/* 紀錄最後4個數字 */
const byte RECORD_SIZE = 4;  //紀錄最後4個數字
byte SELECT_INDEX[RECORD_SIZE];


/* Write a decimal numberto one of the 4 digits of the display */
void WriteNumberToSegment(byte segment, byte value) {  //使用正向觸發的方式傳輸資料(LATCH_DIO->先給LOW->傳輸資料->再給HIGH){
  digitalWrite(LATCH_DIO, LOW);
  // The following order cannot be changed. MAP first and then SELECT. (因電路設計先傳輸要輸出的數字資料再傳輸要顯示的位置資料)
  // shiftOut(資料傳輸腳位,資料傳輸的clock腳位,資料傳輸方式,要傳輸的資料)
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[value]);       //要顯示的圖案(數字圖形)
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[segment]);  //要顯示的位置(要顯示的位置)
  digitalWrite(LATCH_DIO, HIGH);
}

void FlyNumbersFromLeftToRight() {
  //最末個數字到最初個數字
  for (int i = (RECORD_SIZE - 1); i >= 0; i--) {
    //從左往右飛出
    for (int pos = 0; pos < RECORD_SIZE; pos++) {
      delay(DELAY_TIME);
      WriteNumberToSegment(pos, SELECT_INDEX[i]);
    }
    //清除殘留圖形
    delay(DELAY_TIME);
    WriteNumberToSegment(3, 3);
  }
}

void FlyNumbersFromRightToLeft() {
  //最初個數字到最末個數字
  for (int i = (RECORD_SIZE - 1); i >= 0; i--) {
    //從右往左飛出
    for (int pos = (RECORD_SIZE-1); pos >= 0; pos--) {
      delay(DELAY_TIME);
      WriteNumberToSegment(pos, SELECT_INDEX[i]);
    }
    //清除殘留圖形
    delay(DELAY_TIME);
    WriteNumberToSegment(0, 3);
  }
}

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

void setup() {
  /* Seven Segmet:Set DIO pins to outputs */
  pinMode(LATCH_DIO, OUTPUT);
  pinMode(CLK_DIO, OUTPUT);
  pinMode(DATA_DIO, OUTPUT);

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

  //清除顯示器
  for (int i = 0; i < RECORD_SIZE; i++) {
    WriteNumberToSegment(i, 3);
  }

  //初始化紀錄
  for (int i = 0; i < RECORD_SIZE; i++) {  //將記錄的數值都清除
    SELECT_INDEX[i] = 3;              //SEGMENT_MAP[3]為0x00 代表清空圖形
  }
}



/* Main program */
void loop() {
  //偵測按鍵輸入
  if (keyScan() == true) {           //在讀取按鈕時 當按鈕被按下 會讀到的數值會是0 (原因:看電路圖 當按鈕按下時電路將導通接地 電位會輸出0)
    delay(DELAY_TIME);
    //清除顯示器
    for (int i = 0; i < RECORD_SIZE; i++) {
      WriteNumberToSegment(i, 3);
    }
    Pad_Index = Row * 4 + Col;  //取得key_pad位置索引值(透過IS_USEED來判斷是 數字 還是功能 按鈕被按下)
    if (SEGMENT_MAP[Pad_Index]) { //按鈕為數字
      for (int i = 0; i < (RECORD_SIZE - 1); i++) {
        SELECT_INDEX[i] = SELECT_INDEX[i + 1];
      }
      SELECT_INDEX[3] = Pad_Index;
    } else if (Pad_Index == 14) { //左往右飛出
      FlyNumbersFromLeftToRight();
    } else if (Pad_Index == 15) { //右往左飛出
      FlyNumbersFromRightToLeft();
    }
  }
  for (int i = (RECORD_SIZE - 1); i >= 0; i--) {
    WriteNumberToSegment(i, SELECT_INDEX[i]);
  }
}

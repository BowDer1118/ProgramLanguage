/* Define shift register pins used for seven segment display */
#define LATCH_DIO D15   //電路圖:控制暫存器要在何時工作的CLOCK LCHCLK的腳位是D15 (racing edge triggered or falling edge triggered)
#define CLK_DIO D14     //電路圖:控制資料輸入的CLOCK SFTCLK的腳位
#define DATA_DIO D2     //電路圖:資料輸入的腳位D2

/* Segment byte maps for numbers 0 to 10 */ // MSB: dp g f e d c b a
//參考7-segment圖形:https://en.wikipedia.org/wiki/Seven-segment_display
const byte SEGMENT_MAP[] = {0x3F, 0x06, 0x3C, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0X7F, 0X6F};
const int SEGMENT_MAP_SIZE = 10;
const byte DP = 0x80;   // Digit Point

/* Byte maps to select digit 1 to 4 (左到右) */
const byte SEGMENT_SELECT[] = {0x0E, 0x0D, 0x0B, 0x07}; // {0xFE,0xFD,0xFB,0xF7};  is OK, too.

//表示當前輸入的key_pads座標
byte Row = 0, Col = 0;

/* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
void WriteNumberToSegment(byte Segment, byte Value) { //使用正向觸發的方式傳輸資料(LATCH_DIO->先給LOW->傳輸資料->再給HIGH){
  digitalWrite(LATCH_DIO, LOW);
  if (Value < 0 || Value >= SEGMENT_MAP_SIZE) {
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, 0xFF); //清除顯示器內容
  } else {
    // The following order cannot be changed. MAP first and then SELECT. (因電路設計先傳輸要輸出的數字資料再傳輸要顯示的位置資料)
    //shiftOut(資料傳輸腳位,資料傳輸的clock腳位,資料傳輸方式,要傳輸的資料)
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]); //要顯示的圖案(數值)
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] ); //要顯示的位置(7-segment的位置)
  }
  digitalWrite(LATCH_DIO, HIGH);
}

void setup () {
  /* Seven Segmet:Set DIO pins to outputs */
  pinMode(LATCH_DIO,  OUTPUT);
  pinMode(CLK_DIO,  OUTPUT);
  pinMode(DATA_DIO, OUTPUT);

  /*KeyPad:Set Read and Write IO*/
  //對照電路圖:要加電的腳位設定為輸出腳位(用來檢查每個Col)
  pinMode(A0, OUTPUT); //A1
  pinMode(A1, OUTPUT); //A2
  pinMode(A2, OUTPUT); //A3
  pinMode(A3, OUTPUT); //A4

  //對照電路圖:要讀取的腳位(用來讀取每個Row哪個案件被按下)
  pinMode(D10, INPUT); //Row 0: (1,2,3,A)
  pinMode(D11, INPUT_PULLUP); //R1:(4,5,6,B)
  pinMode(D12, INPUT_PULLUP); //R2:(7,8,9,C)
  pinMode(D13, INPUT_PULLUP); //R3:(*,0,#,D)

  //清除顯示器
  WriteNumberToSegment(0, -1);
  WriteNumberToSegment(1, -1);
  WriteNumberToSegment(2, -1);
  WriteNumberToSegment(3, -1);
}

bool keyScan( ) {
  Row = 0; Col = 0;

  /* scan 第0個Col */
  digitalWrite(A0, LOW); //將A0接地
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  /* 依次讀取第0~3個Row對應到的D10~D13腳位 */
  //讀取第0個Row:讀取D10腳位
  if (digitalRead(D10) == LOW) {
    digitalWrite(A0, HIGH); //取消讀取第0個Col
    Row = 0; Col = 0;
    return true;
  }
  //讀取第1個Row:讀取D11腳位
  if (digitalRead(D11) == LOW) {
    digitalWrite(A0, HIGH);
    Row = 0; Col = 1;
    return true;
  }
  //讀取第2個Row:讀取D12腳位
  if (digitalRead(12) == LOW) {
    digitalWrite(A0, HIGH);
    Row = 0; Col = 2;
    return true;
  }
  //讀取第3個Row:讀取D13腳位
  if (digitalRead(13) == LOW) {
    digitalWrite(A0, HIGH);
    Row = 0; Col = 3;
    return true;
  }
  /* scan 第0個Col */
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  if (digitalRead(10) == LOW) {
    digitalWrite(A1, HIGH);
    Row = 1; Col = 0;
    return true;
  }

  if (digitalRead(11) == LOW) {
    digitalWrite(A1, HIGH);
    Row = 1; Col = 1;
    return true;
  }

  if (digitalRead(12) == LOW) {
    digitalWrite(A1, HIGH);
    Row = 1; Col = 2;
    return true;
  }
  //Read keys in row.4
  if (digitalRead(13) == LOW) {
    digitalWrite(A1, HIGH);
    Row = 1; Col = 3;
    return true;
  }

  //scan col 3
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);


  if (digitalRead(10) == LOW) {
    digitalWrite(A2, HIGH);
    Row = 2; Col = 0;
    return true;
  }
  //Read keys in row.2
  if (digitalRead(11) == LOW) {
    digitalWrite(A2, HIGH);
    Row = 2; Col = 1;
    return true;
  }

  if (digitalRead(12) == LOW) {
    digitalWrite(A2, HIGH);
    Row = 2; Col = 2;
    return true;
  }

  if (digitalRead(13) == LOW) {
    digitalWrite(A2, HIGH);
    Row = 2; Col = 3;
    return true;
  }

  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  delayMicroseconds(100);

  if (digitalRead(10) == LOW) {
    digitalWrite(A3, HIGH);
    Row = 3; Col = 0;
    return true;
  }

  if (digitalRead(11) == LOW) {
    digitalWrite(A3, HIGH);
    Row = 3; Col = 1;
    return true;
  }

  if (digitalRead(12) == LOW) {
    digitalWrite(A3, HIGH);
    Row = 3; Col = 2;
    return true;
  }

  if (digitalRead(13) == LOW) {
    digitalWrite(A3, HIGH);
    Row = 3; Col = 3;
    return true;
  }
  //都沒有按下
  return false;
}

/* Main program */
void loop() {
  /* Update the display with the current counter value */
  //在讀取按鈕時 當按鈕被按下 會讀到的數值會是0 (原因:看電路圖 當按鈕按下時電路將導通接地 電位會輸出0)
  if (keyScan() == true) {
    WriteNumberToSegment(3, Row * 4 + Col);
  }
}





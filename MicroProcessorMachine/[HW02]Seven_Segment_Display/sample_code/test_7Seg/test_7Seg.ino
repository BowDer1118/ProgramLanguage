/* Define shift register pins used for seven segment display */
#define LATCH_DIO D15   //電路圖:控制暫存器要在何時工作的CLOCK LCHCLK的腳位是D15 (racing edge triggered or falling edge triggered)
#define CLK_DIO D14     //電路圖:控制資料輸入的CLOCK SFTCLK的腳位
#define DATA_DIO D2     //電路圖:資料輸入的腳位D2
#define BUTTON1 BT1     //母板BTN1
#define BUTTON2 BT2     //母板BTN2
#define BUTTON3 BT3     //母板BTN3
#define BUTTON4 BT4     //母板BTN4
#define BUTTON_A0 A0   //對應key *
#define BUTTON_A1 A1   //對應key 0
#define BUTTON_A2 A2   //對應key #
#define BUTTON_A3 A3   //對應key D


/* Segment byte maps for numbers 0 to 9 , A, b , C*/ // MSB: dp g f e d c b a :LSB 參考7-segment圖形
const byte SEGMENT_MAP[] = {0x3F, 0x06, 0x3C, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0X7F, 0X6F, 0X77, 0X7C, 0X39};
const byte DP = 0x80;   // Digit Point

/* Byte maps to select digit 1 to 4 */ // E: 1110  D: 1101  B: 1011   7: 0111    // the 0's place (左到右分別為 E D B 7)
const byte SEGMENT_SELECT[] = {0x0E, 0x0D, 0x0B, 0x07}; // {0xFE,0xFD,0xFB,0xF7};  is OK, too.

/* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
void WriteNumberToSegment(byte Segment, byte Value) //使用正向觸發的方式傳輸資料(LATCH_DIO->先給LOW->傳輸資料->再給HIGH)
{
  digitalWrite(LATCH_DIO, LOW);
  if (Value == -1)
  {
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, 0xFF); //清除顯示器內容
  } else
  {
    // The following order cannot be changed. MAP first and then SELECT. (因電路設計先傳輸要輸出的數字資料再傳輸要顯示的位置資料)
    //shiftOut(資料傳輸腳位,資料傳輸的clock腳位,資料傳輸方式,要傳輸的資料)
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]); //要顯示的圖案(數值)
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] ); //要顯示的位置(7-segment的位置)
  }
  digitalWrite(LATCH_DIO, HIGH);
}

void setup ()
{
  /* Set DIO pins to outputs */
  pinMode(LATCH_DIO,  OUTPUT);
  pinMode(CLK_DIO,  OUTPUT);
  pinMode(DATA_DIO, OUTPUT);

  //清除顯示器
  WriteNumberToSegment(0, -1);
  WriteNumberToSegment(1, -1);
  WriteNumberToSegment(2, -1);
  WriteNumberToSegment(3, -1);
}

/* Main program */
void loop()
{
  /* Update the display with the current counter value */
  //在讀取按鈕時 當按鈕被按下 會讀到的數值會是0 (原因:看電路圖 當按鈕按下時電路將導通接地 電位會輸出0)
  if (!digitalRead(BUTTON1))
  {
    WriteNumberToSegment(3 , 1);
  }
  if (!digitalRead(BUTTON2))
  {
    WriteNumberToSegment(2 , 3);
  }
  if (!digitalRead(BUTTON3))
  {
    WriteNumberToSegment(1 , 5);
  }
  if (!digitalRead(BUTTON4))
  {
    WriteNumberToSegment(0 , 7);
  }
  if (!digitalRead(BUTTON_A0))
  {
    WriteNumberToSegment(0 , 9);
  }
  if (!digitalRead(BUTTON_A1))
  {
    WriteNumberToSegment(1 , 10);
  }
  if (!digitalRead(BUTTON_A2))
  {
    WriteNumberToSegment(2 , 11);
  }
  if (!digitalRead(BUTTON_A3))
  {
    WriteNumberToSegment(3 , 12);
  }
}





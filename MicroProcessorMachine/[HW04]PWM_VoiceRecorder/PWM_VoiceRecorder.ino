#include <LiquidCrystal.h>
#define INPUT_DELAY_TIME 300
#define RECORD_MAX_SIZE 300

int speakerPin = 3;

/*BT1~BT4*/
int buttonState1, buttonState2, buttonState3, buttonState4 = 0;

/*紀錄keyPad按鈕是否有功能*/
const bool IS_USE[] = {
  true, true, true, true,      // 1 2 3 A
  true, true, true, true,      // 4 5 6 B
  true, false, false, true,    // 7 8 9 C
  false, false, false, false,  // * 0 # D
};

/*按鈕輸入檢查與位置紀錄*/
byte row = 0, col = 0;  //表示當前輸入的key_pads座標
byte padIndex;          //紀錄位置

/*實例化LiquidCrystal物件*/
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


/* Speaker*/
int noteIndex;
// 1~7 對應到 Do~Si 0為休止符
String noteNames[] = { "Pause", "Do", "Re", "Mi", "Fa", "So", "La", "Si" };
int pitchIndex;                                     //0~2 對應到 高音~低音
String pitchNames[] = { "High", "Middle", "Low" };  //音高: 0=高音 1=中音 2=低音
int noteFreqs[3][7] = {
  //紀錄高中低 音調的頻率
  { 1046, 1175, 1318, 1397, 1568, 1760, 1976 },  //高音
  { 523, 587, 659, 698, 784, 880, 988 },         //中音
  { 261, 294, 330, 349, 392, 440, 494 }          //低音
};

/* State Record*/
bool hasNoteInput;                     //是否有輸入音高或音調
String recordingState;                 //當前錄音機狀態
int recordedNotes[RECORD_MAX_SIZE];    //已記錄的音調
int recordedPitches[RECORD_MAX_SIZE];  //已記錄的音高
int recordedNumber;                    //當前音符紀錄量
int tempo = 400;                       //每個音符的播放時間



void setup() {
  /*BT1~BT4*/
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);
  pinMode(BT4, INPUT);

  /*KeyPad:Set Read and Write IO*/
  //對照電路圖:要加電的腳位設定為輸出腳位(用來檢查每個col)
  pinMode(A0, OUTPUT);  // A1
  pinMode(A1, OUTPUT);  // A2
  pinMode(A2, OUTPUT);  // A3
  pinMode(A3, OUTPUT);  // A4

  //對照電路圖:要讀取的腳位(用來讀取每個row哪個案件被按下)
  pinMode(D10, INPUT);         // row 0: (1,2,3,A)
  pinMode(D11, INPUT_PULLUP);  // R1:(4,5,6,B)
  pinMode(D12, INPUT_PULLUP);  // R2:(7,8,9,C)
  pinMode(D13, INPUT_PULLUP);  // R3:(*,0,#,D)

  pinMode(speakerPin, OUTPUT);

  lcd.begin(16, 2);

  /*初始化錄音機狀態*/
  pitchIndex = 2;  //預設為低音
  noteIndex = 0;
  recordingState = "No Recording";
  recordedNumber = 0;
  hasNoteInput = false;

  updateLCDLine1(pitchIndex, noteIndex);
  updateLCDLine2(recordingState);
}

void loop() {
  hasNoteInput = false;

  buttonState1 = digitalRead(BT1);
  buttonState2 = digitalRead(BT2);
  buttonState3 = digitalRead(BT3);
  buttonState4 = digitalRead(BT4);

  /*檢查按鈕是否被按下*/
  if (buttonState1 == LOW) {
    //重新初始化錄音機紀錄
    recordingState = "Recording";
    //輸出錄音機當前狀態
    updateLCDLine2(recordingState);
    recordedNumber = 0;
    delay(INPUT_DELAY_TIME);
  } else if (buttonState2 == LOW) {
    recordingState = "No Recording";
    //輸出錄音機當前狀態
    updateLCDLine2(recordingState);
    delay(INPUT_DELAY_TIME);
  } else if (buttonState3 == LOW) {
    recordingState = "Playing";
    //輸出錄音機當前狀態
    updateLCDLine2(recordingState);
    //播放已記錄的聲音
    for (int i = 0; i < recordedNumber; i++) {
      updateLCDLine1(recordedPitches[i], recordedNotes[i]);
      playSound(recordedPitches[i], recordedNotes[i], tempo);
      // 每個音符之間的間隔，這邊設定的長短會有連音 or 段音的效果
      delay(tempo / 10);
    }
    delay(INPUT_DELAY_TIME);
  } else if (buttonState4 == LOW) {
    recordingState = "Playing a song";
    //輸出錄音機當前狀態
    updateLCDLine2(recordingState);
    defalutSong();
    delay(INPUT_DELAY_TIME);
  }



  /*檢查Pad是否被按下*/
  if (keyScan()) {
    padIndex = row * 4 + col;
    if (IS_USE[padIndex]) {
      //判斷輸入音高
      if (padIndex == 3) {  //High
        pitchIndex = 0;
      } else if (padIndex == 7) {  //Middle
        pitchIndex = 1;
      } else if (padIndex == 11) {  //Low
        pitchIndex = 2;
      }
      //判斷輸入的音調
      switch (padIndex) {
        case 0:  //Do
          noteIndex = 1;
          hasNoteInput = true;
          break;
        case 1:  //Re
          noteIndex = 2;
          hasNoteInput = true;
          break;
        case 2:  //Mi
          noteIndex = 3;
          hasNoteInput = true;
          break;
        case 4:  //Fa
          noteIndex = 4;
          hasNoteInput = true;
          break;
        case 5:  //So
          noteIndex = 5;
          hasNoteInput = true;
          break;
        case 6:  //La
          noteIndex = 6;
          hasNoteInput = true;
          break;
        case 8:  //Si
          noteIndex = 7;
          hasNoteInput = true;
          break;
        default:
          //不會存在不合法輸入
          //Do nothing
          break;
      }
      //更新音符顯示訊息
      updateLCDLine1(pitchIndex, noteIndex);
    } else {  //過濾不合法輸入
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("Invalid Input!");
      delay(INPUT_DELAY_TIME);
    }
  }


  //判斷是否有輸入音調
  if (hasNoteInput) {
    //判斷是否為錄音狀態
    if (recordingState == "Recording") {
      //紀錄當前音高與音調
      recordedNotes[recordedNumber] = noteIndex;
      recordedPitches[recordedNumber] = pitchIndex;
      //更新已記錄數量
      recordedNumber += 1;
    }
    //播放聲音
    playSound(pitchIndex, noteIndex, tempo);
  }
}


bool keyScan() {

  row = 0;
  col = 0;

  /* scan 第0個col */
  digitalWrite(A0, LOW);  //將A0接地
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  /* 依次讀取第0~3個row對應到的D10~D13腳位 */

  if (digitalRead(D10) == LOW) {  //讀取第0個row:讀取D10腳位
    digitalWrite(A0, HIGH);       //取消讀取第0個col
    row = 0;
    col = 0;
    return true;
  }

  if (digitalRead(D11) == LOW) {  //讀取第1個row:讀取D11腳位
    digitalWrite(A0, HIGH);
    row = 1;
    col = 0;
    return true;
  }

  if (digitalRead(12) == LOW) {  //讀取第2個row:讀取D12腳位
    digitalWrite(A0, HIGH);
    row = 2;
    col = 0;
    return true;
  }

  if (digitalRead(13) == LOW) {  //讀取第3個row:讀取D13腳位
    digitalWrite(A0, HIGH);
    row = 3;
    col = 0;
    return true;
  }

  /* scan 第1個col */
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);  //將A1接地
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  if (digitalRead(10) == LOW) {
    digitalWrite(A1, HIGH);
    row = 0;
    col = 1;
    return true;
  }

  if (digitalRead(11) == LOW) {
    digitalWrite(A1, HIGH);
    row = 1;
    col = 1;
    return true;
  }

  if (digitalRead(12) == LOW) {
    digitalWrite(A1, HIGH);
    row = 2;
    col = 1;
    return true;
  }

  if (digitalRead(13) == LOW) {
    digitalWrite(A1, HIGH);
    row = 3;
    col = 1;
    return true;
  }

  /* scan 第2個col */
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  if (digitalRead(10) == LOW) {
    digitalWrite(A2, HIGH);
    row = 0;
    col = 2;
    return true;
  }

  if (digitalRead(11) == LOW) {
    digitalWrite(A2, HIGH);
    row = 1;
    col = 2;
    return true;
  }

  if (digitalRead(12) == LOW) {
    digitalWrite(A2, HIGH);
    row = 2;
    col = 2;
    return true;
  }

  if (digitalRead(13) == LOW) {
    digitalWrite(A2, HIGH);
    row = 3;
    col = 2;
    return true;
  }

  /* scan 第3個col */
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  delayMicroseconds(100);

  if (digitalRead(10) == LOW) {
    digitalWrite(A3, HIGH);
    row = 0;
    col = 3;
    return true;
  }

  if (digitalRead(11) == LOW) {
    digitalWrite(A3, HIGH);
    row = 1;
    col = 3;
    return true;
  }

  if (digitalRead(12) == LOW) {
    digitalWrite(A3, HIGH);
    row = 2;
    col = 3;
    return true;
  }

  if (digitalRead(13) == LOW) {
    digitalWrite(A3, HIGH);
    row = 3;
    col = 3;
    return true;
  }
  //都沒有按下
  return false;
}

/*更新LCD第一行訊息:音符與音高*/
void updateLCDLine1(int pIndex, int nIndex) {
  //游標移至第一行
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  //輸出音符
  lcd.print(noteNames[nIndex]);

  //調整游標位置
  if (pIndex == 0) {
    lcd.setCursor(12, 0);
  } else if (pIndex == 1) {
    lcd.setCursor(10, 0);
  } else {
    lcd.setCursor(13, 0);
  }
  //輸出音高
  lcd.print(pitchNames[pIndex]);
}

/*更新LCD第二行訊息:當前狀態*/
void updateLCDLine2(String state) {
  //游標移至第二行
  lcd.setCursor(0, 1);
  //清除原本顯示內容
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(state);
}

/*播放音樂:透過音高與音調決定要輸出的頻率並設定延遲時間*/
void playSound(int pitchIndex, int noteIndex, unsigned long duration) {
  tone(speakerPin, noteFreqs[pitchIndex][noteIndex], duration);
  //下方的 delay() 及 noTone ()，測試過後一定要有這兩行，整體的撥放出來的東西才不會亂掉，可能是因為 Arduino 送出tone () 頻率後會馬上接著執行下個指令，不會等聲音播完，導致撥出的聲音混合而亂掉
  delay(duration);
  noTone(speakerPin);
}

/*輸出預錄的歌曲:周杰倫-夜曲*/
void defalutSong() {
  //輸出歌名
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print("JayChou-Nocturne");
  delay(2000);

  int notes[] = { 6, 7, 1, 1, 1, 1, 7, 3, 3, 6, 6, 6, 5, 4, 5, 1, 1, 4, 4, 4, 4, 3, 7, 3, 2, 2, 1, 7, 1, 1, 0, 3, 6, 7, 1, 1, 1, 1, 7, 3, 3, 6, 6, 6, 5, 4, 5, 1, 1, 4, 4, 4, 4, 3, 2, 1, 7 };
  //節奏使用簡譜的概念
  int tempos[] = { 1, 1, 1, 2, 2, 1, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1 };
  int len = sizeof(tempos) / sizeof(int);
  for (int i = 0; i < len; i++) {
    //都使用高音
    updateLCDLine1(0, notes[i]);
    playSound(0, notes[i], int(tempo / tempos[i]));
  }
}

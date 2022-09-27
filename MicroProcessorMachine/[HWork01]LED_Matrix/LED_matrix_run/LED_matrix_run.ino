#define NUM 16          // 首先定義LED的數目
#define DELAY_TIME 150  // 定義延遲的時間

int leds[NUM] = {  //使用0~15腳位的LED (之後會跳過3號腳位)
  D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15
};


/*
  [設計理念]
    步驟一:從中間往左右點亮
    步驟二:從左右往中間熄滅
    步驟三:從左右往中間點亮
    步驟四:從中間往左右熄滅

    Repeat:步驟一 步驟二 步驟三 步驟四

  [led燈的腳位如下]
    R R R R R R R R G G G G G G G G
    1 1 1 1 1 1 9 8 7 6 5 4 3 2 1 0
    5 4 3 2 1 0

*/

unsigned led_code;  //代表16顆led燈的狀態 0為熄滅 1為點亮

//傳入一個unsigned來設定led燈要如何運作
void set_led(unsigned code) {
  unsigned result;
  for (int i = 0; i < 16; i++) {
    //取得第i個位元的bit
    result = code << (31 - i);
    result >>= 31;
    //判斷該bit狀態
    if (result == 0) {  //熄滅該led燈
      digitalWrite(leds[i], HIGH);
    } else {  //點亮該led燈
      digitalWrite(leds[i], LOW);
    }
  }
  delay(DELAY_TIME);
}

void setup() {
  // 將每個腳位模式設為OUTPUT
  for (int i = 0; i < NUM; i++) {
    if (i == 3) {  //排除掉蜂鳴器腳位(不設定為OUTPUT模式)
      continue;
    }
    pinMode(leds[i], OUTPUT);
  }
  //將所有LED燈都熄滅
  set_led(0);
}


void loop() {
  //步驟一:從中間往左右點亮
  led_code = 0x180;  //led狀態為00000001 10000000
  for (int i = 0; i < 8; i++) {
    set_led(led_code);
    led_code = (led_code << 1) | (led_code >> 1);  //往左右兩邊擴散開一個1bit
  }


  //步驟二:從左右往中間熄滅
  for (int i = 0; i < 8; i++) {
    set_led(led_code);
    led_code = (led_code << (i + 2 + 16)); //移除最靠左的bit
    led_code = (led_code >> (i + 1 + 16)); //移除最靠右的bit
  }


  //步驟三:從左右往中間點亮
  led_code = 0x8001;  //led狀態為10000000 00000001
  for (int i = 0; i < 8; i++) {
    set_led(led_code);
    led_code = led_code | (led_code << 1) | (led_code >> 1);  //往中間擴散一個bit
  }


  //步驟四:從中間往左右熄滅
  led_code = 0x180;
  for (int i = 0; i < 8; i++) {
    set_led(~led_code); //傳入Not後的led_code就是步驟一的熄滅版本
    led_code = (led_code << 1) | (led_code >> 1);  //往左右兩邊擴散開一個1bit
  }

}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int colors[6];
} Mana;

typedef struct {
    char name[50];
    Mana cost;
    char type[50];
    int power;
    int toughness;
} Card;

Mana process_mana(char *mana_info) {          //傳入sub_string[1] 字串--->使用char型指標接收參數
    Mana m = {.colors = {0, 0, 0, 0, 0, 0}};  //臨時的Mana結構體 (colors={非顏色,白,紅,綠,藍,黑})

    //colorless是'x'
    if (*(mana_info) == 'x') {  //若字串第一個字元是'x'代表後面的值都是0
        m.colors[0] = 'x';      //更新陣列第0個位置
        return m;               //直接回傳Mana結構體
    }

    //colorless不是'x'
    char num[10] = {0};            //用來存放colorless的值(先使用字串處理 之後在使用atoi轉整數)
    int index = 0;                 //用來訪問num陣列的index
    while (isdigit(*mana_info)) {  //逐一字元掃描--->若當前指標指向的字元可轉成數字--->進入while處理
        num[index] = *mana_info;   //將當前字元放入num陣列中
        index++;                   //移動到下一個可用的num位置
        mana_info++;               //將指標往後走--->繼續檢查
    }
    num[index] = '\0';        //處理完畢後加上'\0'代表字串結尾
    m.colors[0] = atoi(num);  //將字串轉成整數

    //開始處理 白紅綠藍黑的mana消耗數值
    while (*mana_info != '\0') {                         //逐一字元掃描
        if (strncmp(mana_info, "White", 5) == 0) {       //比較當前字串前5個字元是否吻合White
            m.colors[1] += 1;                            //將代表White mana的數值+1
            mana_info += strlen("White");                //將指標往下走--->略過這個被我們解析完的字串
        } else if (strncmp(mana_info, "Red", 3) == 0) {  //以此類推...
            m.colors[2] += 1;
            mana_info += strlen("Red");
        } else if (strncmp(mana_info, "Green", 5) == 0) {
            m.colors[3] += 1;
            mana_info += strlen("Green");
        } else if (strncmp(mana_info, "Blue", 4) == 0) {
            m.colors[4] += 1;
            mana_info += strlen("Blue");
        } else if (strncmp(mana_info, "Black", 5) == 0) {
            m.colors[5] += 1;
            mana_info += strlen("Black");
        } else {
            mana_info++;  //預防while回圈卡死的default處理(當字串匹配失敗時)
        }
    }
    //Mana結構體解析完畢--->回傳Mana結構體
    return m;
}

void write_cards(Card *cards, int len) {  //批次輸出Card結構體陣列 共len個元素
    FILE *file = fopen("my_output_MTG21F.txt", "w");

    if (file == NULL) {
        puts("Output file open failure");
        return;
    }

    fputs("--------------------------------------------------------------------------------------------------------------------\n", file);
    fputs("Name                        Colorless   White   Red   Green   Blue   Black   Type                  Power   Toughness\n", file);
    fputs("--------------------------------------------------------------------------------------------------------------------\n", file);
    for (int i = 0; i < len; i++) {
        if (isalpha(cards[i].cost.colors[0])) {  //判斷Card結構體的colorless成員的值是'x'(字元)還是數字
            fprintf(file, "%-28s%9c%8d%6d%8d%7d%8d%3s%-22s%5d%12d\n", cards[i].name, cards[i].cost.colors[0], cards[i].cost.colors[1], cards[i].cost.colors[2], cards[i].cost.colors[3], cards[i].cost.colors[4], cards[i].cost.colors[5], "   ", cards[i].type, cards[i].power, cards[i].toughness);
        } else {
            fprintf(file, "%-28s%9d%8d%6d%8d%7d%8d%3s%-22s%5d%12d\n", cards[i].name, cards[i].cost.colors[0], cards[i].cost.colors[1], cards[i].cost.colors[2], cards[i].cost.colors[3], cards[i].cost.colors[4], cards[i].cost.colors[5], "   ", cards[i].type, cards[i].power, cards[i].toughness);
        }
    }

    fputs("--------------------------------------------------------------------------------------------------------------------", file);

    fclose(file);
}

int main() {
    FILE *file = fopen("test_input_MTG21F.txt", "r");

    if (file == NULL) {
        puts("Input file open failure");
        return -1;
    }

    Card cards[285];                          //存放排組的陣列
    int index = 0;                            //用來訪問cards的index(索引值)
    char input_string[300];                   //存放gets()函數抓到的字串
    while (fgets(input_string, 300, file)) {  //EOF
        Card c;                               //臨時的Card結構體(解析完成後會放入cards陣列)
        char *sub_string[5];                  //存放strtok回傳值的 指標陣列
        //string-token
        sub_string[0] = strtok(input_string, ",");
        for (int i = 1; i <= 4; i++) {
            sub_string[i] = strtok(NULL, ",");
        }

        //將sub_string[0]的字串 複製到c.name中
        strcpy(c.name, sub_string[0]);

        //對sub_string[1]字串處裡並將返回的Mana結構體指派入c.cost中
        c.cost = process_mana(sub_string[1]);

        //對sub_string[2]字串處裡並將返回值複製到c.type中
        strcpy(c.type, strtok(sub_string[2], "-"));

        //使用atoi處理字串--->atoi若可以轉成數字就會轉 不能轉換就會return 0
        c.power = atoi(sub_string[3]);
        c.toughness = atoi(sub_string[4]);

        //將解析完畢的臨時結構體c存入cards陣列中
        cards[index] = c;
        //移動到下一個能存放結構體的陣列位置
        index++;
    }

    fclose(file);

    //陣列解析完畢後 統一格式化輸出
    write_cards(cards, 285);
    return 0;
}
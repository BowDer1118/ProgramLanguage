#include <stdio.h>
#include <string.h>

/*
    字串取代邏輯:將字串拆開再重新組合 以下示範
    search="cd";
    replace="xyz";
    input="abcdefg";

    使用額外兩個陣列存放 要取代的前半部跟後半部子字串
    font="ab";
    back="efg";
    再將所有字串重新組合
    input-->Reset (記得要先清除input字串)
    input=font+replace+back
    -->input="ab"+"xyz"+"efg"="abxyzefg";
*/

int main() {
    while (1) {
        //要查找的字串
        char search_string[300] = {0};
        //要替換的字串
        char replace_string[300] = {0};
        //要處理的字串
        char input_string[300] = {0};

        gets(search_string);
        //檢查是否符合退出條件
        //提醒:字元使用單引號
        if (search_string[0] == '*') {
            break;
        }

        gets(replace_string);
        gets(input_string);

        //存放找到符合要求的字串記憶體位置
        char *position;
        //strstr():返回查找到的子字串 的第一次出現的記憶體位置
        //使用while迴圈處理所有可替換的字串 直到未找到符合的字串
        while ((position = strstr(input_string, search_string)) != NULL) {
            //存放要替換的前後子字串
            char font_string[300] = {0};
            char back_string[300] = {0};
            //複製input~position之間的字元到font_string中(存放要取代的前半部字串)
            strncpy(font_string, input_string, position - input_string);
            //移動指標到要取代的最後位置(也就是後半部子字串開始的位置)
            position += strlen(search_string);
            //將後半部的字串複製到back_string中
            strcpy(back_string, position);
            //重設input_string
            //memeset()
            //參數是:要處理的記憶體位置,要設置的數值,設置多少個byte
            memset(input_string, 0, sizeof(input_string));
            //將所有子字串拼接
            strcat(input_string, font_string);     //拼接前半部
            strcat(input_string, replace_string);  //拼接新的字串
            strcat(input_string, back_string);     //拼接後半部
        }
        //輸出結果
        puts(input_string);
    }
    return 0;
}
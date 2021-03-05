#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    //假設存在一字串 字串可能為特殊形態
    //但因為我先將str[0]轉成大寫 所以沒差(空格沒有大小寫)-->str[1]的前面依然是空格 所以可以正常轉
    char str[30] = " abc dEF gH";
    //轉手字符大寫-->先將字串的所有字元轉小寫
    int string_length = strlen(str);  //使用strlen(char *str)取得字串大小
    for (int i = 0; i < string_length; i++) {
        str[i] = tolower(str[i]);  //tolower(int c) 傳入字元 回傳小寫的字元
    }

    //已知字串第一個字元一定是大小
    str[0] = toupper(str[0]);
    //再來開始判斷是否需要大寫
    for (int i = 0; i < string_length; i++) {
        //防止存取出界
        /*
            char temp="ABC";
            temp[0]='A';
            ...
            temp[2]='C';
        */
        if (i < string_length - 1) {
            if (str[i] == ' ') {  //如果當前字元是空格那就將下一個字元轉大小
                str[i + 1] = toupper(str[i + 1]);
            }
        }
    }
    puts(str);
    return 0;
}

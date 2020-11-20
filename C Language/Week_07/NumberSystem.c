#include <stdio.h>

int main() {
    //陣列宣告語法:
    //資料類型 陣列名稱[空間大小]
    int result[200];  //宣告一個int類型的陣列，共有200個元素

    int num, base;                                //存放十進位數字與要轉換的進位系統
    while (scanf("%d %d", &num, &base) != EOF) {  //不解釋www
        //初始化陣列中的每個元素值為-1
        for (int i = 0; i < 200; i++) {
            //存取陣列元素語法:
            //陣列名稱[索引值](陣列索引值是從0開始)
            //所以陣列大小若為200則每個元素為result[0]~result[199]
            result[i] = -1;
        }
        int index = 0;  //用來存取陣列元素

        printf("Change %d to base %d number system: ", num, base);  //符合輸出格式

        //開始轉換
        while (num > 0) {                //若num大於零(代表未除完整)則繼續執行
            result[index] = num % base;  //將餘數存入陣列第index個元素中
            index++;                     //將索引值+1(移至下一個元素位置)
            num /= base;                 //同義於:num=num/base;
        }
        //將不等於-1的值輸出(從陣列後方往前方輸出，則做到將餘數反向輸出)
        for (int i = 199; i >= 0; i--) {
            if (result[i] != -1) {
                printf("%d", result[i]);
            }
        }
        //換行
        puts("");
    }
    return 0;
}

/*
    將十進位轉換成不同進位公式如下:
    另num代表10進位數值，base代表要轉換的進位
    1.紀錄num%base
    2.然後將num/base
    3.若num不等於0則回到1.
    4.將記錄下的來的餘數反向輸出
    example:
    將41轉成9進位
    solution:
    41/9=4...5
    4/9 =0...4
    41轉換成9進位後是45
*/
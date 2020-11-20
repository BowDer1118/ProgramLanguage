#include <stdbool.h>  //導入布林值的資料庫
#include <stdio.h>
/*
    function寫在main前面，不須宣告函數原型(prototype)
    補充一下此function的prototype:
    bool isCorrect(int n1,int n2);
*/
bool isCorrect(int n1, int n2) {  //有回傳值(布林值)並接受兩個參數的function
    int data[10] = {0};           //宣告一個大小為10的陣列，用來檢查0~9出現過的次數
    //開始檢查
    for (int i = 0; i < 10; i++) {
        if (i < 5) {  //前五次檢查n1
            //此時的n1%10就式最低位元值，剛好對應到陣列的索引值0~9
            data[n1 % 10]++;
            n1 /= 10;  //為獲取下一次最小位元數做準備
        } else {       //後五次檢查n2
            data[n2 % 10]++;
            n2 /= 10;
        }
    }
    //判斷0~9是否都出現過
    for (int i = 0; i < 10; i++) {
        //如果陣列元素值有出現等於零代表該數值未出現過
        //則代表n1,n2沒有滿足0~9都出現過，回傳布林值:false
        if (data[i] == 0) {
            return false;
        }
    }
    //或經過檢查未觸發if則代表0~9都出現過，回傳布林值:true
    return true;
}

int main() {
    int c;
    int count = 0;  //用來記錄執行幾次
    while (true) {  //使用布林值製造無限迴圈
        scanf("%d", &c);
        if (c == 0) {  //檢查c值，若等於零離開迴圈
            break;
        }
        if (count != 0) {  //為了滿足輸出格式
            puts("");
        }
        int n2;
        bool flag = true;  //用來標示是否有找到符合題目的結果(若有則會將此變數改成false)
        //使用for遍歷所有n1的可能性
        for (int n1 = 1234; n1 < 98765; n1++) {
            if (n1 % c == 0) {  //若整除代表存在一組可能的n2
                n2 = n1 / c;
                if (isCorrect(n1, n2)) {  //如果n1,n2滿足0~9則isCorrect會回傳true觸發if條件
                    //使用%05d的format輸出:代表輸出一個int占用5格空間，未滿5格則補0至5格
                    printf("%05d = %d * %05d\n", n1, c, n2);
                    flag = false;  //找到結果，將flag改成false;
                }
            }
        }
        //若此時flag依然為true代表未找到符合題目的結果
        if (flag) {
            printf("No pair for c = %d.\n", c);
        }
        count++;  //計數器+1
    }
    return 0;
}

/*
    存在一個數學式:
    n1=c*n2(所以邏輯上n1>=n2)
    n1,n2的數字要滿足0~9都出現過一遍
    且n1的值域為1234~98765
*/

/*
    如何獲取n1與n2每個數值呢?
    假設
    n2=1234;
    對n2%10就會得到最低位元數
    n2%10的結果為4
    此時將n2/10會等於123就可以在獲取最低位元
    以此類推，就可以會取所有數字了
*/
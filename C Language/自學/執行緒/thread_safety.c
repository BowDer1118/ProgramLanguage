/*記得將tinycthread.c一起編譯*/
#include <stdio.h>

#include "tinycthread.h"

// 全局變數讓所有thread都可以存取
int count;

int doCounting(void *dont_care) {
    printf("Do Counting!\n");
    for (int i = 0; i < 1000000; i++) {
        count += 1;
    }
    return 0;
}

int main() {
    /*thread物件(結構體)的變數*/
    thrd_t thread1, thread2;

    /*創建thread*/
    // thrd_create(thread物件指標,thread的工作內容,函數參數...) 返回創建的成功,失敗或其他狀態
    thrd_create(&thread1, doCounting, NULL);
    thrd_create(&thread2, doCounting, NULL);

    /*等待所有thread執行完畢*/
    thrd_join(thread1, NULL);
    thrd_join(thread2, NULL);

    // 發生問題
    printf("%d\n", count);
    return 0;
}
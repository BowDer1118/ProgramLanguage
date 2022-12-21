/*記得將tinycthread.c一起編譯*/
#include <stdio.h>

#include "tinycthread.h"

// thread要執行的函式物件 函數規定返回值為int參數為void*
int sayHello(void *name) {
    // 使用thrd_current()獲得當前thread的ID
    printf("Run in new thread[%#x]: Hello, %s\n", thrd_current(), (char *)name);
    return 0;
}

int main() {
    /*thread物件(結構體)的變數*/
    thrd_t new_thread;

    /*創建thread*/
    // thrd_create(thread物件指標,thread的工作內容,函數參數...) 返回創建的成功,失敗或其他狀態
    int ret = thrd_create(&new_thread, sayHello, "Hello C thread");

    /*檢查創建是否成功*/
    if (ret == thrd_success) {
        // 使用16進位輸出thread的ID
        printf("Run in Main thread[%#x], create new_thread[%#x]\n", thrd_current(), new_thread);
    }

    /* 阻塞main thread:讓main thread發呆一陣子，讓子thread執行完畢 */
    // thrd_sleep(timespec物件,剩餘未sleep的時間):讓當前thread等待timespec描述的時間長度，因各種原因thread未必會真正sleep到設定的時間 因此第二個參數為剩餘沒sleep的時間
    // struct timespec during = {.tv_sec = 1, .tv_nsec = 0};  // 1秒鐘
    // thrd_sleep(&during, NULL);                             // 第二個參數可以傳NULL代表不在乎剩下的時間

    /*阻塞當前thread直到等待指定thread結束才繼續執行*/
    // int return_value_from_sub_thread;
    // // thrd_join(要等待的thread,要等待的thread的函數返回值)
    // thrd_join(new_thread, &return_value_from_sub_thread);
    // printf("New thread return value: %d\n", return_value_from_sub_thread);

    /*讓出CPU時間片段，但是否讓出CPU要看作業系統與CPU決定*/
    // thrd_yield();

    /*分離子thread*/
    // thrd_detach(要分離的thread):用來將thread從當前thread分離出去，代表不考慮該thread的返回值，也不關心他，就算parent thread結束了，只要main thread尚未結束，則分離出去的thread會繼續執行
    thrd_detach(new_thread);

    /*detach和join只能選擇一個調用*/
    return 0;
}
#include <stdio.h>
#include <time.h>

// 獲取時間
void part1() {
    time_t current_time;
    // 獲取Epoch時間:從1900/1/1 00:00:00開始到目前所經過的秒數
    time(&current_time);
    printf("[Epoch Time] %lld\n", current_time);

    // 使用localtime()將Epoch時間轉換為本地時區的時間也就是日曆時間 會獲得tm結構體指標
    struct tm *calender_time = localtime(&current_time);
    // 輸出tm結構體中的成員(年月日時分秒...)
    printf("[Local time] %d/%d/%d %d:%d:%d\n", calender_time->tm_year, calender_time->tm_mon, calender_time->tm_mday, calender_time->tm_hour, calender_time->tm_min, calender_time->tm_sec);

    // 使用asctime將本地時間轉換為人類可讀時間
    char *str = asctime(calender_time);
    printf("[Human Readable Time] %s", str);

    // 使用mktime()將日曆時間轉換為Epoch時間
    time_t current_time2 = mktime(calender_time);

    printf("[Epoch Time] %d must equal to %d\n", current_time, current_time2);

    // 將Epoch時間轉換為UTC零時區的時間
    struct tm *utc_time = gmtime(&current_time);
    printf("[UTC Time] %d/%d/%d %d:%d:%d\n", utc_time->tm_year, utc_time->tm_mon, utc_time->tm_mday, utc_time->tm_hour, utc_time->tm_min, utc_time->tm_sec);
}

// 格式化時間
void part2() {
    time_t current_epoch_time = time(NULL);
    printf("[Epoch Time] %lld\n", current_epoch_time);
    struct tm *calender_time = localtime(&current_epoch_time);

    // 兩種顯示人類可讀時間的方法 返回的字串都是共享記憶體 如果並發或並行會有安全問題
    puts(asctime(calender_time));      // asctime()需傳入本地時間的結構體指標
    puts(ctime(&current_epoch_time));  // ctime()需傳入epoch時間的秒數指標

    // 依照我們的需求格式化人類可讀時間
    char current_time_str[30];
    // %Y為年,%m為月,%d為日,%H為小時,%M為分,%S為秒數 是固定的格式畫時間
    // 格式化時間string format time的函數:strftime(要存放結果的buffer,buffer的大小,格式,本地時間的tm結構體指標)
    size_t size_of_string = strftime(current_time_str, 30, "%Y/%m/%d %H:%M:%S", calender_time);
    printf("%s , string size=%d\n", current_time_str, size_of_string);

    // 產生一個一個時間字串格式為:年月日時分秒(ex:20221220161831)
    char buffer[30];
    size_of_string = strftime(buffer, 30, "%Y%m%d%H%M%S", calender_time);
    printf("%s\n", buffer);
}

// 解析時間
void part3() {
    char time_string[] = "2022/12/20 16:51:20";
    struct tm parsed_time;
    sscanf(time_string, "%4d/%2d/%2d %2d:%2d:%2d", &parsed_time.tm_year, &parsed_time.tm_mon, &parsed_time.tm_mday, &parsed_time.tm_hour, &parsed_time.tm_min, &parsed_time.tm_sec);
    printf("%d\n", parsed_time.tm_year);
    // 修正時間
    parsed_time.tm_year -= 1900;
    parsed_time.tm_mon -= 1;

    // 將時間轉換回epoch時間
    time_t epoch_time = mktime(&parsed_time);
    printf("%d\n", epoch_time);
}

void doHardWork() {
    double sum = 1.1;
    for (int i = 0; i < 10000000; i++) {
        sum *= 1.3;
    }
}

// 計算時間差
void part4() {
    // 計算使用多少clock時間
    clock_t start_time = clock();
    doHardWork();
    clock_t end_time = clock();
    // 總clock除以每秒能產生的clock
    double during = ((end_time - start_time) * 1.0) / CLOCKS_PER_SEC;
    printf("%lf\n", during);
}

int main() {
    // part1();
    // part2();
    // part3();
    part4();
    return 0;
}
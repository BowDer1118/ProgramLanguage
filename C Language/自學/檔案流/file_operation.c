#include <errno.h>  //errno
#include <stdio.h>
#include <string.h>  //strerror()

// 輸入輸出流
void part1() {
    // 輸出錯誤碼與該錯誤碼對應的字串
    for (int i = 0; i < 10; i++) {
        printf("%d %s\n", i, strerror(i));
    }

    // 使用fopen()開啟檔案並指定為讀取模式
    FILE *file = fopen("examples.txt", "r");

    // 檢查檔案是否出錯
    int is_err = ferror(file);  // 非0代表出錯
    // 檢查是否到達結尾
    int is_eof = feof(file);

    // 檢查檔案室否開啟
    if (file) {
        puts("Open successfully");
        // 關閉文件
        fclose(file);
    } else {
        char *error_message = strerror(errno);
        puts(error_message);
        // 輸出fopen相關錯誤到錯誤流
        // perror("fopen");
    }
}

// 文件的緩衝區
void part2() {
    // 使用fopen()開啟檔案並指定為讀取模式
    FILE *file = fopen("example.txt", "r");

    // 檢查檔案室否開啟
    if (file) {
        puts("Open successfully");

        // 設定緩衝區
        // char buf[BUFSIZ];  // BUFSIZ通常預設為512
        // setbuf(file, buf);

        // 較好的設定緩衝區方法
        /*
            緩衝方式
            _IOFBF:全部緩衝
            _IOLBF:每行緩衝
            _IONBF:禁用緩衝

            [注意]緩衝區的生命週期一定要大於等於文件流的生命週期，因為文件流還沒失效時，皆有可能使用緩衝區
        */
        char buf[8192];  // 自訂緩衝區
        // setvbuf(要設定的文件流,緩衝區位置,緩衝方式,緩衝區大小)
        setvbuf(file, buf, _IOFBF, 8192);

        // 關閉文件
        fclose(file);
    } else {
        char *error_message = strerror(errno);
        puts(error_message);
        // 輸出fopen相關錯誤到錯誤流
        // perror("fopen");
    }
}

// 緩衝區沖洗
void part3() {
    printf("%d\n", 123);
    printf("%s", "aabbcc");
    // 手動沖洗緩衝區
    fflush(stdout);
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += i;
    }
}

// 複製文件(回傳值代表執行結果，非0則代表出錯)
int copyFile(char const *src, char const *dest) {
    // 以二進位進行讀取
    FILE *src_file = fopen(src, "rb");
    if (!src_file) {
        perror("Source file open failed.");
        return -1;
    }
    FILE *dest_file = fopen(dest, "wb");
    if (!dest_file) {
        perror("Destination file open failed.");
        fclose(src_file);
        return -1;
    }

    // 開始讀取並寫入
    while (1) {
        int next_char = fgetc(src_file);
        // 檢查是否到達文件結尾
        if (next_char == EOF) {
            // 檢查檔案流有無錯誤(若出錯則返回非0)
            if (ferror(src_file)) {
                fclose(src_file);
                fclose(dest_file);
                return -1;
            }
            break;
        } else {
            fputc(next_char, dest_file);
        }
    }

    // 複製完畢 關閉檔案流
    fclose(src_file);
    fclose(dest_file);
    return 0;
}

// 複製檔案
void part4() {
    int ret = copyFile("example.txt", "test.txt");
    if (!ret) {
        puts("Copy success");
    } else {
        puts("Copy error");
    }
}

int main() {
    // part1();
    // part2();
    // part3();
    part4();
    return 0;
}
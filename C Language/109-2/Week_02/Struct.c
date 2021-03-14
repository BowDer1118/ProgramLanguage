#include <stdio.h>
#include <string.h>

int main() {
    char input_string[300] = {0};
    printf("%-13s%-12s%-12s%-6s%-9s%-30s%s\n", "First Name", "Last Name", "Nick Name", "Age", "Gender", "University", "Department");
    puts("----------------------------------------------------------------------------------------------------------------");
    while (gets(input_string)) {
        //存放 資料
        char *sub_string[7] = {'\0'};
        int index = 0;
        sub_string[index] = strtok(input_string, ",");
        //依照 資料 切割
        while (index < 6) {
            index++;
            sub_string[index] = strtok(NULL, ",");
        }
        //格式化輸出
        printf("%-13s%-12s%-13s%-7s%-7c%-30s%s\n", sub_string[0], sub_string[1], sub_string[2], sub_string[3], *(sub_string[4]), sub_string[5], sub_string[6]);
    }
    puts("----------------------------------------------------------------------------------------------------------------");

    return 0;
}
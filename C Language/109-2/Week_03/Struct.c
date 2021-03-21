#include <stdio.h>
#include <string.h>

int main() {
    puts("First Name   Last Name   Nick Name   Age   Gender   University                    Department");
    puts("----------------------------------------------------------------------------------------------------------------");
    char input[300] = {0};
    while (gets(input)) {
        char *sub_string[7];
        sub_string[0] = strtok(input, ",");
        for (int i = 1; i <= 6; i++) {
            sub_string[i] = strtok(NULL, ",");
        }
        printf("%-13s%-12s%-13s%-7s%-7c%-30s%s\n", sub_string[0], sub_string[1], sub_string[2], sub_string[3], *sub_string[4], sub_string[5], sub_string[6]);
    }
    puts("----------------------------------------------------------------------------------------------------------------");
    return 0;
}
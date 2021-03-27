#include <stdio.h>

int main() {
    //左移31bits獲得1bit(此時temp是1)
    unsigned int temp = 1 << 31;
    //左移24bits獲得8bits
    unsigned int num = 254 << 24;

    int result[32] = {0};
    int index = 0;

    //將num與temp做and運算--->獲得每個bit的值
    for (int i = 0; i < 8; i++) {
        if (num & temp) {
            result[index] = 1;
            index++;
        } else {
            result[i] = 0;
            index++;
        }
        num <<= 1;
    }

    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
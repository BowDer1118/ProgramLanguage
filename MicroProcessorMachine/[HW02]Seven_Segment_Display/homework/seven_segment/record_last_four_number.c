#include <stdio.h>
#define NUMBER 4

int values[NUMBER];
int count;
int input;

void init() {
    for (int i = 0; i < NUMBER; i++) {
        values[i] = 0;
    }
    count = 0;
}

void addValue(int input) {
    printf("Add data %d\n", count);
    printf("Value= %d\n", input);
    values[(count - 1) % NUMBER] = input;
}

void display() {
    // printf("Current array\n");
    // for (int i = 0; i < NUMBER; i++) {
    //     printf("%d ", values[i]);
    // }
    // printf("\n");

    printf("Output\n");
    if (count < NUMBER) {
        for (int i = 0; i < count; i++) {
            printf("%d ", values[i]);
        }
    } else {
        for (int i = 0; i < 4; i++) {
            printf("%d ", values[(count + i) % NUMBER]);
        }
    }

    printf("\n\n");
}

int main() {
    while (scanf("%d", &input)) {
        if (input < 0) {
            break;
        }
        count++;
        addValue(input);
        display();
    }
    return 0;
}
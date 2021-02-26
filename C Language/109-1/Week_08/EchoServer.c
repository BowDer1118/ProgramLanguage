#include <stdbool.h>
#include <stdio.h>

char echo() {
    char c;
    if ((c = getchar()) != '\n') {
        printf("%c", c);
        echo();
    }
}

char reserve() {
    char c;
    if ((c = getchar()) != '\n') {
        reserve();
        printf("%c", c);
    }
}

int main() {
    while (true) {
        char choice, c;
        scanf("%c", &choice);
        getchar();

        switch (choice) {
            case 'E':
                echo();
                break;
            case 'R':
                reserve();
                break;
            case 'O':
                return 0;
        }
        puts("");
    }
    return 0;
}
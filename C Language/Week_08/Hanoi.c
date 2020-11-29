#include <stdio.h>

void moveDisk(int n, int start, int end, int temp) {
    if (n == 1) {
        printf("Move disk %d from %d to %d\n", n, start, end);
    } else {
        moveDisk(n - 1, start, temp, end);
        printf("Move disk %d from %d to %d\n", n, start, end);
        moveDisk(n - 1, temp, end, start);
    }
}

int main() {
    int num;
    while (scanf("%d", &num) != EOF) {
        moveDisk(num, 1, 3, 2);
        puts("");
    }
    return 0;
}
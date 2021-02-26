#include <stdio.h>

int GCD(int x, int y) {
    if (x == 0) {
        return y;
    } else {
        return GCD(y % x, x);
    }
}

int LCM(int x, int y) {
    return x * y / GCD(x, y);
}

int main() {
    int x, y;  //x<y
    int gcd, lcm;
    while (scanf("%d %d", &x, &y) != EOF) {
        if (x > y) {
            gcd = GCD(y, x);
            lcm = LCM(y, x);
        } else {
            gcd = GCD(x, y);
            lcm = LCM(x, y);
        }
        printf("%d %d\n", gcd, lcm);
    }
    return 0;
}
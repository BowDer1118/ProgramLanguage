#include <math.h>

#include <iostream>

using namespace std;

/*
    紀錄每根棒子頂端的數字
*/

bool isSquare(int num) {
    int temp = (int)sqrt(num);
    return temp * temp == num;
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int pNumber;
        scanf("%d", &pNumber);
        if (pNumber == 1) {
            puts("1");
        } else {
            int pegs[pNumber] = {0};
            pegs[0] = 1;
            int pIndex = 0;
            int bNumber = 2;

            bool canContain = true;
            while (canContain) {
                canContain = false;
                for (int i = 0; i <= pIndex; i++) {
                    if (isSquare(pegs[i] + bNumber)) {
                        canContain = true;
                        pegs[i] = bNumber;
                        bNumber++;
                        break;
                    }
                }
                if (!canContain) {
                    if (pIndex < pNumber - 1) {
                        pIndex++;
                        canContain = true;
                        pegs[pIndex] = bNumber;
                        bNumber++;
                    }
                }
            }
            printf("%d\n", bNumber - 1);
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdbool.h>
//宣告外部程式
extern void asmMain();

/*
    Function structure

    returnType functionName(parameter){
        ***
            function code
        ***
    }
*/


int AllPrimeFactors(int N) {
    int counter = 0;
    bool flag;
    //Search all factors
    for (int i = 2; i <= N; i++) {
        flag = false;
        while (N % i == 0) {

            if (!flag) {
                printf("%d ", i);
                counter++;
            }
            flag = true;

            if (N / i == 1) {
                printf("\n");
            }
            N /= i;

        }
    }
    return counter;
}

int main() {
    //Call asmMain Function
    asmMain();
    return 0;
}

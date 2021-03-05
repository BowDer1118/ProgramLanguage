#include <iostream>
using namespace std;
/*
    4P 2T
    1234->2134->2143 
    5P 4T
    12345->12354->12534->21534->21543
    6P 6T
    123456->132456->312456->321456->321465->321645->312654

    
    Sort 3P 3T
    123->132->312->321
    Sort 4P 6T
    1234->1243->1423->4123->4132->4312->4321
    Sort 5P 10T
    12345->12354->12534->15234->51234->51243->51423->
    54123->54132->54312->54321

    A1=0
    A2=1=A1+1
    A3=3=A2+2
    A4=6=A3+3
    A5=10=A4+4
    An=A(n-1)+(n-1)
*/
int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int number;
        scanf("%d", &number);
        if (number % 2 == 0) {
            number /= 2;
        } else {
            number = (number - 1) / 2;
        }
    }
    return 0;
}
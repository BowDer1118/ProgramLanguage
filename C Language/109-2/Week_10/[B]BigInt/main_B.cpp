#include <iostream>
#include <string>

#include "BigInt.h"
using namespace std;

int main() {
    BigInt bigInt1, bigInt2, endSign("*");
    cin >> bigInt1;
    while (!(bigInt1 == endSign)) {
        cin >> bigInt2;

        /*** Output the two big integers ***/
        cout << "Big Integer 1: " << bigInt1 << endl;
        cout << "Big Integer 2: " << bigInt2 << endl;

        /*** Check and output their relation ***/
        if (bigInt1 > bigInt2)
            cout << "Big Integer 1 is greater than Big Integer 2." << endl;
        else if (bigInt1 < bigInt2)
            cout << "Big Integer 1 is less than Big Integer 2." << endl;
        else if (bigInt1 == bigInt2)
            cout << "Big Integer 1 equals to Big Integer 2." << endl;
        else
            cout << "An error occurs during comparisons." << endl;

        /*** Output their sum and difference ***/
        cout << "The sum of them is: " << bigInt1 + bigInt2 << endl;
        cout << "The difference of them is: " << bigInt1 - bigInt2 << endl;

        /*** Test for correctness ***/
        if (bigInt1 + bigInt2 - bigInt2 != bigInt1) cout << bigInt1 + bigInt2 - bigInt2 << " " << bigInt1 << "(1)Error addition and subtraction." << endl;
        if (bigInt1 + bigInt2 - bigInt1 != bigInt2) cout << bigInt1 + bigInt2 - bigInt1 << " " << bigInt2 << "(2)Error addition and subtraction." << endl;
        if (bigInt1 - bigInt2 + bigInt2 != bigInt1) cout << bigInt1 - bigInt2 + bigInt2 << " " << bigInt1 << "(3)Error addition and subtraction." << endl;
        if (bigInt2 - bigInt1 + bigInt1 != bigInt2) cout << bigInt2 - bigInt1 + bigInt1 << " " << bigInt2 << "(4)Error addition and subtraction." << endl;
        if (bigInt1 - bigInt1 != 0) cout << "(1)Error subtraction." << endl;
        if (bigInt2 - bigInt2 != 0) cout << "(2)Error subtraction." << endl;

        cout << endl;
        cin >> bigInt1;
    }

    /*** Test constructor from long long integer ***/
    // long long int ending1 = 1234567890, ending2 = -1234567890;
    // cout << BigInt(ending1) << " + " << BigInt(ending2) << " = " << BigInt(ending1) + BigInt(ending2) << endl;

    return 0;
}

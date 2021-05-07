#include <iostream>

#include "overloaded_functions.h"
using namespace std;

int main() {
    unsigned int num_cases;
    cin >> num_cases;

    unsigned int n, row, column;
    char character_1, character_2, character_3;

    for (unsigned int i = 0; i < num_cases; ++i) {
        input(n, character_1, row, column, character_2, character_3);
        output(n, character_1, row, column, character_2, character_3);
    }

    return 0;
}


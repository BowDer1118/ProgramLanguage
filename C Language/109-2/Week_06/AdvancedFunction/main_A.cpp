#include <iostream>

#include "function_header.h"

using namespace std;

int main() {
    unsigned int num_cases;
    unsigned int num_par, t, xv, xa, yv, ya, zv, za;
    cin >> num_cases;

    for (unsigned int i = 0; i < num_cases; ++i) {
        input(num_par, t, xv, xa, yv, ya, zv, za);
        output(num_par, t, xv, xa, yv, ya, zv, za);
    }

    return 0;
}

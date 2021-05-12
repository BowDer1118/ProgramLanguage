#include <iostream>
#include <vector>

#include "function_template.h"

using namespace std;

int main() {
    size_t num_elements = 0;
    unsigned int input_type;
    cin >> num_elements;

    while (num_elements != 0) {
        vector<char> array_char(num_elements);
        vector<int> array_int(num_elements);
        vector<double> array_double(num_elements);
        cin >> input_type;
        switch (input_type) {
            case 0:
                input(array_char);
                sorting(array_char);
                output(array_char);
                break;
            case 1:
                input(array_int);
                sorting(array_int);
                output(array_int);
                break;
            case 2:
                input(array_double);
                sorting(array_double);
                output(array_double);
                break;
        }

        cin >> num_elements;
    }

    return 0;
}

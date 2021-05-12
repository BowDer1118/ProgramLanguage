#include <iostream>
#include <string>

#include "myString.h"

using namespace std;

int main() {
    //被我魔改過(從500變成5)--->可用CMD a<test.txt看結果
    size_t num_cases = 5;
    string input("");
    MyString mystring(input);

    for (unsigned int i = 0; i < num_cases; ++i) {
        getline(cin, input);
        mystring.set_string(input);
        cout << "\"" << mystring.get_string() << "\""
             << " gets " << mystring.compact_sum() << "." << endl;
    }

    return 0;
}

#include <iomanip>
#include <iostream>

#include "calendar.h"

using namespace std;

int main() {
    Calendar calendar;             // default constructor: set elapsed seconds to zero
    calendar.getUniversalTime();   // 01/01/1970 00:00:00 Thursday
    Calendar calendar2(86401);     // constructor: with one argument of elapsed seconds
    calendar2.getUniversalTime();  // 01/02/1970 00:00:01 Friday
    unsigned long int elapsedSeconds(0);
    cin >> elapsedSeconds;
    while ((elapsedSeconds + 1) != 0) {
        calendar.setElapsedSeconds(elapsedSeconds);
        calendar.getUniversalTime();
        cin >> elapsedSeconds;
    }

    return 0;
}

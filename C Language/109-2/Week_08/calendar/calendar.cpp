#include "calendar.h"

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
//預設為非閏年
int Calendar::month_days[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Calendar::Calendar(unsigned long int seconds) : total_second(seconds) {}

void Calendar::setElapsedSeconds(unsigned long int seconds) {
    this->total_second = seconds;
}

void Calendar::update_array(int year) {
    //依照平閏年就修改值
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        month_days[1] = 29;
    } else {
        month_days[1] = 28;
    }
}

void Calendar::getUniversalTime() {
    int year = 1970;
    int month = 0;
    update_array(year);

    int day = total_second / 86400;
    //剩下的秒數
    int left_seconds = total_second - day * 86400;
    //獲取星期
    int weekday = 4;
    weekday += day;
    weekday %= 7;
    int index = 0;

    if (day >= 1) {
        //獲取年、月
        while (day >= month_days[index]) {
            day -= month_days[index];
            index++;
            if (index == 12) {
                year++;
                update_array(year);
                index = 0;
            }
        }
    }

    //獲取時
    int hr = 0;
    while (left_seconds >= 3600) {
        hr++;
        left_seconds -= 3600;
    }
    //獲取分
    int min = 0;
    while (left_seconds >= 60) {
        min++;
        left_seconds -= 60;
    }

    string str_weekday;
    switch (weekday) {
        case 0:
            str_weekday = "Sunday";
            break;

        case 1:
            str_weekday = "Monday";

            break;
        case 2:
            str_weekday = "Tuesday";

            break;
        case 3:
            str_weekday = "Wednesday";
            break;
        case 4:
            str_weekday = "Thursday";
            break;
        case 5:
            str_weekday = "Friday";

            break;
        case 6:
            str_weekday = "Saturday";
            break;
    }

    cout << setw(2) << setfill('0') << index + 1 << "/" << setw(2) << setfill('0') << day + 1 << "/" << year << " " << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << left_seconds << " " << str_weekday << endl;
}
#include "myString.h"

MyString::MyString(std::string _str) {
    str = _str;
}
std::string MyString::get_string(void) {
    return str;
}

void MyString::set_string(std::string _str) {
    str = _str;
}

int MyString::compact_sum(void) {
    std::vector<char> v(str.size());
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        //將每個字元轉小寫在-96後加入sum
        sum += tolower(str.at(i)) - 96;
    }

    //處理大於10的sum
    while (sum >= 10) {
        int temp = 0;
        while (sum > 0) {
            temp += sum % 10;
            sum /= 10;
        }
        sum = temp;
    }
    //返回結果
    return sum;
}
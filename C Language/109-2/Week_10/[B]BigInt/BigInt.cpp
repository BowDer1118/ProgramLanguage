#include "BigInt.h"

#include <algorithm>
using namespace std;

istream& operator>>(istream& input, BigInt& bi) {
    string str;

    cin >> str;

    if (str.at(0) == '-') {
        bi.setStringNum(str.substr(1));
        bi.setSignBit(false);
    } else {
        bi.setStringNum(str);
        bi.setSignBit(true);
    }

    return input;
}

ostream& operator<<(ostream& output, BigInt bi) {
    if (bi.getSignBit()) {
        cout << bi.getStringNum();
    } else {
        cout << "-" << bi.getStringNum();
    }
    return output;
}

BigInt::BigInt(string str) {
    if (str.at(0) == '-') {
        str_num = str.substr(1);
        positive = false;
    } else {
        str_num = str;
        positive = true;
    }
}

BigInt::BigInt(long long int integer) {
    if (integer < 0) {
        str_num = to_string(-integer);
        positive = false;
    } else {
        str_num = to_string(integer);
        positive = true;
    }
}

void BigInt::setStringNum(string s) {
    this->str_num = s;
}

void BigInt::setSignBit(bool b) {
    this->positive = b;
}

string BigInt::getStringNum(void) {
    return this->str_num;
}

bool BigInt::getSignBit(void) {
    return this->positive;
}

bool BigInt::operator==(BigInt bi) {
    if (this->positive ^ bi.positive) {  // exclusive or --->異號true
        return false;
    }

    if (this->str_num.size() != bi.str_num.size()) {
        return false;
    }

    int len = this->str_num.size();

    for (int i = 0; i < len; i++) {
        if (this->str_num.at(i) != bi.str_num.at(i)) {
            return false;
        }
    }

    return true;
}

bool BigInt::operator!=(BigInt bi) {
    return !(*this == bi);
}

bool BigInt::operator<(BigInt bi) {
    //排除相等
    if (*this == bi) {
        return false;
    }

    if ((!this->positive) && bi.positive) {  // 左邊- 右邊 +
        return true;
    } else if (this->positive && bi.positive) {  //兩邊都 +
        int size1 = this->str_num.size();        //左邊數字的位數
        int size2 = bi.str_num.size();           //右邊數字的位數
        if (size2 > size1) {                     //如果 右邊位數多於左邊
            return true;
        } else if (size1 == size2) {                     //位數一樣多
            for (int i = 0; i < size1; i++) {            //一個一個位數比較
                int value1 = this->str_num.at(i) - '0';  //左邊每個位數的值
                int value2 = bi.str_num.at(i) - '0';     //右邊每個位數的值
                if (value2 > value1) {                   //右邊大於左邊
                    return true;
                }
                if (value2 < value1) {  //如果右邊小於左邊
                    break;
                }
            }
            return false;
        } else {  //左邊位數比右邊多
            return false;
        }
    } else if ((!this->positive) && (!bi.positive)) {  //兩邊都 -
        int size1 = this->str_num.size();
        int size2 = bi.str_num.size();
        if (size1 > size2) {  //左邊的位數多餘右邊
            return true;
        } else if (size1 == size2) {
            for (int i = 0; i < size1; i++) {            //一個一個位數比較
                int value1 = this->str_num.at(i) - '0';  //左邊每個位數的值
                int value2 = bi.str_num.at(i) - '0';     //右邊每個位數的值
                if (value1 > value2) {                   //左邊大於右邊
                    return true;
                }
                if (value1 < value2) {  //右邊大於左邊
                    break;
                }
            }
            return false;

        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool BigInt::operator>(BigInt bi) {
    //排除相等
    if (*this == bi) {
        return false;
    }
    return !(*this < bi);
}

BigInt BigInt::operator+(BigInt bi) {
    BigInt b;
    if (this->positive && bi.positive) {  //A+B
        string str1 = this->str_num;
        string str2 = bi.str_num;
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        int len1 = str1.size();
        int len2 = str2.size();

        string str = "";
        int total_len = max(len1, len2) + 1;
        int carry = 0;
        for (int i = 0; i < total_len; i++) {
            int value1 = 0;
            int value2 = 0;

            if (i < len1) {
                value1 = str1.at(i) - '0';
            }
            if (i < len2) {
                value2 = str2.at(i) - '0';
            }

            int sum = value1 + value2 + carry;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            str += to_string(sum);
        }

        if (str.at(str.size() - 1) == '0') {
            str.pop_back();
        }
        reverse(str.begin(), str.end());
        b.str_num = str;
        b.positive = true;
    } else if ((!this->positive) && bi.positive) {  //-A+B
        //B-A
        BigInt temp1(this->str_num);
        BigInt temp2(bi.str_num);
        b = temp2 - temp1;
    } else if (this->positive && (!bi.positive)) {  //A+(-B)
        //A-B
        BigInt temp1(this->str_num);
        BigInt temp2(bi.str_num);
        b = temp1 - temp2;
    } else {  //-A+(-B)
        //-(A+B)
        BigInt temp1(this->str_num);  //+A
        BigInt temp2(bi.str_num);     //+B
        b = temp1 + temp2;            //A+B
        b.positive = false;           //-(A+B)
    }
    return b;
}

BigInt BigInt::operator-(BigInt bi) {
    BigInt b;

    if (*this == bi) {
        return BigInt(0);
    }

    if (this->positive && bi.positive) {  //都是 正數
        string str1 = this->str_num;
        string str2 = bi.str_num;
        int len1 = str1.size();
        int len2 = str2.size();
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        string str("");
        if (*this > bi) {         //A>B--->正數
            bool borrow = false;  //表示是否還有下一位數--->是否可以借位
            for (int i = 0; i < len1; i++) {
                int value1 = 0;
                int value2 = 0;

                if (i < len1) {
                    value1 = str1.at(i) - '0';
                }
                if (i < len2) {
                    value2 = str2.at(i) - '0';
                }

                if (borrow) {  //如果被之前借位
                    value1 -= 1;
                    borrow = false;
                }

                int result = value1 - value2;

                if (result < 0) {
                    borrow = true;
                    result += 10;
                }

                str += to_string(result);
            }
            reverse(str.begin(), str.end());
            //檢查字串 就是將00010--->10
            int count = 0;
            for (int i = 0; i < str.size(); i++) {
                if (str.at(i) != '0') {
                    count = i;
                    break;
                }
            }
            str.erase(0, count);
            b.str_num = str;
            b.positive = true;
        } else {  //A<B--->負數
            //-(B-A)
            b = bi - *this;
            b.positive = false;
        }

    } else if ((!this->positive) && (bi.positive)) {  //-A-B
        //-(A+B)
        BigInt temp1(this->str_num);                //+A
        BigInt temp2(bi.str_num);                   //+B
        b = temp1 + temp2;                          //A+B
        b.positive = false;                         //-(A+B)
    } else if (this->positive && (!bi.positive)) {  //A-(-B)
        //A+B
        BigInt temp1(this->str_num);
        BigInt temp2(bi.str_num);
        b = temp1 + temp2;                             //A+B
    } else if ((!this->positive) && (!bi.positive)) {  //-A-(-B)
        //B-A
        BigInt temp1(this->str_num);
        BigInt temp2(bi.str_num);
        b = temp2 - temp1;
    }

    return b;
}

bool BigInt::operator!=(long long int num) {
    return this->str_num.size() == 1 && this->str_num.at(0) == 0;
}
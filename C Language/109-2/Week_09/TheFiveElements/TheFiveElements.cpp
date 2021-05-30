#include "TheFiveElements.h"

using namespace std;

//初始化靜態成員與實作函式
array<string, 5> TheFiveElements::state_name = {"Wood", "Fire", "Earth", "Metal", "Water"};
string TheFiveElements::getNameOfElement(size_t t) {
    return state_name[t];
}

//構造方法
TheFiveElements::TheFiveElements(size_t t) : state(t) {}

//實作其他方法
void TheFiveElements::setState(size_t t) {
    this->state = t;
}

size_t TheFiveElements::getState(void) {
    return this->state;
}

/*
        木 generate 火 0-1==-1 true
        火 generate 土 1-2==-1 ture
        土 generate 金 2-3==-1 true
        金 generate 水 3-4==-1 true
        水 generate 木 4-0==4  true

        火 is generate by 木 1-0==1 true
        木 is generate by 木 0-4==-4 true
    */
bool TheFiveElements::operator>(const TheFiveElements &e) {
    int temp = this->state - e.state;
    if ((temp < 0 && temp == -1) || temp == 4) {
        return true;
    } else {
        return false;
    }

    if (temp > 0 || temp == -4) {
        return true;
    } else {
        return false;
    }

    return false;
}

/*
        木 overcome 土 0-2==-2 true
        火 overcome 金 1-3==-2 true
        土 overcome 水 2-4==-2 true
        金 overcomd 木 3-0==3 true
        水 overcome 火 4-1==3 true

        土 is overcome by 木 2-0==2
        金 is overcome by 火 3-1==2
        水 is overcome by 土 4-2==2
        木 is overcome by 金 0-3==-3
        火 is overcome by 水 1-4==-3
    */
bool TheFiveElements::operator<(const TheFiveElements &e) {
    int temp = this->state - e.state;

    if ((temp < 0 && temp == -2) || temp == 3) {
        return true;
    } else {
        return false;
    }
    if ((temp > 0 && temp == 2) || temp == -3) {
        return true;
    } else {
        return false;
    }
    return false;
}

//Prefix
TheFiveElements &TheFiveElements::operator++() {
    if (state == 4) {
        state = 0;
    } else {
        state++;
    }
    return *this;
}
TheFiveElements &TheFiveElements::operator--() {
    if (state == 0) {
        state = 4;
    } else {
        state--;
    }
    return *this;
}

//Postfix
TheFiveElements TheFiveElements::operator++(int t) {
    TheFiveElements temp = *this;
    if (state == 4) {
        state = 0;
    } else {
        state++;
    }
    return temp;
}

TheFiveElements TheFiveElements::operator--(int t) {
    TheFiveElements temp = *this;
    if (state == 0) {
        state = 4;
    } else {
        state--;
    }
    return temp;
}

//Cin
istream &operator>>(istream &input, TheFiveElements &e) {
    cin >> e.state;
    return input;
}
//Cout
ostream &operator<<(ostream &output, const TheFiveElements &e) {
    cout << e.getNameOfElement(e.state);
    return output;
}
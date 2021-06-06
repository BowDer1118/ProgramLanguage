#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>

class BigInt {
    friend std::istream& operator>>(std::istream&, BigInt&);
    friend std::ostream& operator<<(std::ostream&, BigInt);

   private:
    std::string str_num;
    bool positive;

   public:
    BigInt(std::string);
    BigInt(long long int = 0);

    void setStringNum(std::string s);
    void setSignBit(bool b);

    std::string getStringNum(void);
    bool getSignBit(void);

    bool operator==(BigInt);
    bool operator!=(BigInt);
    bool operator<(BigInt);
    bool operator>(BigInt);
    BigInt operator+(BigInt);
    BigInt operator-(BigInt);

    //Speical case
    bool operator!=(long long int);
};

#endif
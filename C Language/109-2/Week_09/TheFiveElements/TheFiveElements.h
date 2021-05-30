#ifndef THEFIVEELEMENTS_H
#define THEFIVEELEMENTS_H
#include <array>
#include <iostream>
#include <string>

class TheFiveElements {
    //Overload cin>>
    friend std::istream &operator>>(std::istream &input, TheFiveElements &element);
    //Overload cout<<
    friend std::ostream &operator<<(std::ostream &output, const TheFiveElements &element);

   private:
    size_t state;
    static std::array<std::string, 5> state_name;
    static std::string getNameOfElement(size_t);

   public:
    TheFiveElements(size_t = 0);
    void setState(size_t);
    size_t getState(void);
    //Overload >
    bool operator>(const TheFiveElements &);
    //Overload <
    bool operator<(const TheFiveElements &);
    //Overload ++element
    TheFiveElements &operator++();
    TheFiveElements &operator--();
    //Overload element++
    TheFiveElements operator++(int);
    TheFiveElements operator--(int);
};
#endif
#include "PokerCard.h"

#include <iostream>
#include <stdexcept>
using namespace std;

//初始化所有靜態成員
int PokerCard::face_num = 13;
int PokerCard::suit_num = 4;
array<string, 13> PokerCard::face_array = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
array<string, 4> PokerCard::suit_array = {"Spades", "Hearts", "Diamonds", "Clubs"};

//構造方法
PokerCard::PokerCard(int f, int s) : face(f), suit(s) {
}

//Setters
PokerCard PokerCard::setFace(int f) {
    if (f >= 0 && f <= 12) {
        this->face = f;
        return *this;
    } else {
        throw invalid_argument("Invalid face value");
    }
}

PokerCard PokerCard::setSuit(int s) {
    if (s >= 0 && s <= 3) {
        this->suit = s;
        return *this;
    } else {
        throw invalid_argument("Invalid suit color");
    }
}

//輸出
void PokerCard::show() {
    cout << face_array[face] << " of " << suit_array[suit] << endl;
}
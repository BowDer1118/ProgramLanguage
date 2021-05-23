#include <array>
#include <iostream>
#include <stdexcept>

// #include "PokerCard.h"

using namespace std;

//-----------------------------
class PokerCard {
    static int face_num;
    static int suit_num;
    static array<string, 13> face_array;
    static array<string, 4> suit_array;

   private:
    int face;
    int suit;

   public:
    PokerCard(int f, int s);
    PokerCard setFace(int f);

    PokerCard setSuit(int s);

    void show();
};

//初始化所有靜態成員
int PokerCard::face_num = 13;
int PokerCard::suit_num = 4;
array<string, 13> PokerCard::face_array = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
array<string, 4> PokerCard::suit_array = {"Spades", "Hearts", "Diamonds", "Clubs"};

//構造方法
PokerCard::PokerCard(int f = 0, int s = 0) : face(f), suit(s) {}

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

// -----------------------------

int main() {
    PokerCard pokerCard;  //default constructor: set face value and suit color to zero
    pokerCard.show();     // Ace of Spades

    PokerCard pokerCard2(12);  // constructor with one argument of face value, set suit color to zero
    pokerCard2.show();         // King of Spades

    PokerCard pokerCard3(0, 1);  // constructor with two arguments of face value and suit color
    pokerCard3.show();           // Ace of Hearts

    int face, suit;

    cin >> face;
    while (face >= 0) {
        cin >> suit;
        try {
            pokerCard.setFace(face).setSuit(suit).show();
        } catch (invalid_argument& e) {
            cout << e.what() << endl;
        }

        cin >> face;
    }

    return 0;
}

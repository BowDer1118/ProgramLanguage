#include <array>
#include <string>

class PokerCard {
    static int face_num;
    static int suit_num;
    static std::array<std::string, 13> face_array;
    static std::array<std::string, 4> suit_array;

   private:
    int face;
    int suit;

   public:
    //PokerCard的兩個參數constructor(不足的使用default argument補齊)
    PokerCard(int f = 0, int s = 0);
    PokerCard setFace(int f);

    PokerCard setSuit(int s);

    void show();
};
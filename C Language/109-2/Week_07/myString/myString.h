#include <string>
#include <vector>
class MyString {
   private:
    std::string str;

   public:
    MyString(std::string _str);
    std::string get_string(void);
    void set_string(std::string _str);
    int compact_sum(void);
};
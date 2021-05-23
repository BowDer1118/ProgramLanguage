#include <string>

class Calendar {
    static int month_days[];

   private:
    unsigned long int total_second;

   public:
    Calendar(unsigned long int seconds = 0);

    void setElapsedSeconds(unsigned long int seconds);

    void update_array(int year);

    void getUniversalTime();
};
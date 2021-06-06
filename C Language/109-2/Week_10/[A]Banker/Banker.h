#ifndef BANKER_H
#define BANKER_H
#include <iostream>
class Banker {
    friend std::istream &operator>>(std::istream &, Banker &);
    friend std::ostream &operator<<(std::ostream &, Banker);

   private:
    size_t threads;
    size_t resources;
    int **allocation;
    int **need;
    int *available;

   public:
    Banker(size_t, size_t);
    ~Banker();
    int **getAllocation();
    int **getNeed();
    int *getAvailable();
    bool safety();
    bool operator()(size_t);
    bool operator()(size_t, size_t);
};

#endif
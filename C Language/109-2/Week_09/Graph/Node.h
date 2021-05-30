#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
    //cin>>Node
    friend std::istream& operator>>(std::istream&, Node&);
    //cout<<Node
    friend std::ostream& operator<<(std::ostream&, Node&);

   private:
    int x;
    int y;

   public:
    //Constructor
    Node(int = 0, int = 0);
    //Getters
    int getX(void);
    int getY(void);
    //Setters
    void setX(int);
    void setY(int);
};
#endif
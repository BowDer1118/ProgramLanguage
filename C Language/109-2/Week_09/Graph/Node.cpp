#include "Node.h"

#include <iostream>
using namespace std;

//cin
istream &operator>>(istream &input, Node &node) {
    int x, y;
    cin >> x >> y;
    node.setX(x);
    node.setY(y);
    return input;
}
//cout
ostream &operator<<(ostream &output, Node &node) {
    //??
    return output;
}

//Constructor
Node::Node(int xx, int yy) : x(xx), y(yy) {}

//Getters
int Node::getX(void) {
    return this->x;
}
int Node::getY(void) {
    return this->y;
}

//Setters
void Node::setX(int x) {
    this->x = x;
}
void Node::setY(int y) {
    this->y = y;
}

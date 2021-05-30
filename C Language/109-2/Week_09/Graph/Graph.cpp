#include "Graph.h"

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

//cin
istream &operator>>(istream &input, Graph &g) {
    size_t numNodes;
    cin >> numNodes;
    Node *node_array = new Node[numNodes];

    for (unsigned int n = 0; n < numNodes; ++n) {
        cin >> *(node_array + n);
    }

    g.setNodeNum(numNodes).setNodeArray(node_array).setWegihts();

    return input;
}
//cout
ostream &operator<<(ostream &output, const Graph &g) {
    unsigned int **ptr_array = g.weights;
    size_t size = g.node_num;

    for (int i = 0; i < size; i++) {
        unsigned int *p = *(ptr_array + i);
        for (int j = 0; j < size; j++) {
            if (j == size - 1) {
                cout << setw(2) << *(p + j) << endl;
            } else {
                cout << setw(2) << *(p + j) << " ";
            }
        }
    }
    return output;
}

//Constructors
Graph::Graph(size_t num, Node *ptr_node, unsigned int **pptr_weight)
    : node_num(num), node_array(ptr_node), weights(pptr_weight) {}

Graph::Graph(Node *ptr_node, size_t num) : node_num(num), node_array(ptr_node) {
    this->setNodeNum(num).setNodeArray(ptr_node).setWegihts();
}

//Destructor
Graph::~Graph() {
    //釋放Node節點物件的陣列
    delete this->node_array;

    //釋放weights的動態配置
    unsigned int **pptr = this->weights;
    size_t size = this->node_num;

    //先釋放指標陣列所指到陣列
    for (int i = 0; i < size; i++) {
        delete[] * (pptr + i);
    }

    //最後再刪除外面的指標陣列
    delete[] pptr;
}

//Getters
size_t Graph::getNodeNum(void) {
    return this->node_num;
}
Node *Graph::getNodeArray(void) {
    return this->node_array;
}
unsigned int **Graph::getWeights(void) {
    return this->weights;
}
//Setters
Graph &Graph::setNodeNum(size_t n) {
    this->node_num = n;
    return *this;
}
Graph &Graph::setNodeArray(Node *ptr) {
    this->node_array = ptr;
    return *this;
}

Graph &Graph::setWegihts(void) {
    unsigned int num = this->getNodeNum();
    //Create 2D dynamic array
    unsigned int **array = new unsigned int *[num];  //配置存放每個陣列的 指標陣列

    for (int i = 0; i < num; i++) {
        *(array + i) = new unsigned int[num];  //配置每個指標所指到的陣列
    }

    //Calculate distance
    Node *ptr_node = this->getNodeArray();

    for (int i = 0; i < num; i++) {
        Node outer = *(ptr_node + i);
        for (int j = 0; j < num; j++) {
            Node inner = *(ptr_node + j);
            int rangeX = inner.getX() - outer.getX();
            int rangeY = inner.getY() - outer.getY();
            unsigned int result = (unsigned int)pow(rangeX * rangeX + rangeY * rangeY + 0.5, 0.5);
            *(*(array + i) + j) = result;  //存放結果
        }
    }

    weights = array;
    return *this;
}
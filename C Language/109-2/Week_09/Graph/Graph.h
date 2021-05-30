#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

#include "Node.h"

class Graph {
    //Overload cin
    friend std::istream& operator>>(std::istream&, Graph&);
    //Overload cout
    friend std::ostream& operator<<(std::ostream&, const Graph&);

   private:
    size_t node_num;
    Node* node_array;
    unsigned int** weights;

   public:
    //Constructor
    Graph(size_t = 0, Node* = NULL, unsigned int** weights = NULL);
    //Overload Constructor
    Graph(Node*, size_t);
    //Destructor
    ~Graph();
    //Getters
    size_t getNodeNum(void);
    Node* getNodeArray(void);
    unsigned int** getWeights(void);
    //Setters
    Graph& setNodeNum(size_t);
    Graph& setNodeArray(Node*);
    Graph& setWegihts(void);
};
#endif
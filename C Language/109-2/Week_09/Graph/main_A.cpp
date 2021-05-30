#include <cmath>
#include <iostream>

#include "Graph.h"
#include "Node.h"

using namespace std;

int main() {
    unsigned int numCases;  // number of input cases
    cin >> numCases;

    /*** input through an array of nodes ***/
    size_t numNodes;  // number of nodes
    cin >> numNodes;
    Node nodeArray[numNodes];  // array of Node objects

    for (unsigned int n = 0; n < numNodes; ++n) {
        cin >> nodeArray[n];  // overloaded >> operator for Node object
    }

    Graph tmpGraph(nodeArray, numNodes);  // initialize a graph object through array of nodes
    cout << tmpGraph << endl;             // overloaded << operator for Graph object
    /*** input through graph object ***/
    Graph graph;

    for (unsigned int i = 1; i < numCases; ++i) {
        cin >> graph;           // overloaded >> operator for Graph object
        cout << graph << endl;  // overloaded << operator for Graph object
    }

    return 0;
}

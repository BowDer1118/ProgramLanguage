#include <iostream>

#include "Banker.h"

using namespace std;

int main() {
    size_t numThreads, numResources;  // number of threads and resource types
    cin >> numThreads >> numResources;

    while (numThreads > 0 && numResources > 0) {
        Banker bankerObj(numThreads, numResources);    // constructor with two arguments of type size_t
        cin >> bankerObj;                              // overloaded stream insertion operator
        int **allocation = bankerObj.getAllocation();  // get function for private data member allocation
        int **need = bankerObj.getNeed();              // get function for private data member need
        int *available = bankerObj.getAvailable();     // get function for private data member available

        cout << allocation[numThreads / 2][numResources / 2] << " " << need[numThreads / 2][numResources / 2] << " " << available[numResources / 2] << endl;  // test data integrity

        if (bankerObj.safety() == true)  // check safety using safety algorithm
        {
            /*** overloaded parentheses () operators with one argument and two arguments ***/
            /*** for (argument1), request additional half resources that thread argument1 needed and see if it is still in safe sate, store the state back if it is an unsafe attempt ***/
            /*** for (argument1, argument2), request additional half resource of type argument2 that thread argument1 needed and see if it is still in safe sate, store the state back if it is an unsafe attempt ***/
            if (bankerObj(numThreads / 2) == true || bankerObj(numThreads / 2, numResources / 2) == true) {
                cout << "Safe state" << endl;
            } else {
                cout << "Unsafe state" << endl;
            }
        } else {
            cout << "Unsafe state" << endl;
        }

        cout << endl;
        cin >> numThreads >> numResources;
    }

    return 0;
}

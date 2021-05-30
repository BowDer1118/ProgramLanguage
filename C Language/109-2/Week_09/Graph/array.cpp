#include <cstring>
#include <iostream>
using namespace std;

class Test {
   private:
    int **array;

   public:
    Test(int **array) {
        this->array = array;
    }
    int getValue() {
        return *(*(this->array + 1) + 2);
    }
};

int main() {
    int array[2][3];
    memset(array, 0, sizeof(array));
    cout << array[0][1] << endl;

    int num = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = num;
            num++;
        }
    }

    cout << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    int *ptr[2] = {array[0], array[1]};

    cout << endl;
    Test t(ptr);
    cout << t.getValue() << endl;
    cout << endl;

    int **p = ptr;

    for (int i = 0; i < 2; i++) {
        int *pp = *(p + i);
        for (int j = 0; j < 3; j++) {
            cout << *(pp + j) << " ";
        }
        cout << endl;
    }

    return 0;
}
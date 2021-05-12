#include <iostream>
#include <vector>

template <class T>
void input(std::vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
}

template <class T>
void sorting(std::vector<T>& v) {
    std::vector<T> temp_vector(v.size());
    for (int i = 0, t_size = temp_vector.size(); i < t_size; i++) {
        int index = 0;
        T current_max = v[index];
        for (int j = 0, v_size = v.size(); j < v_size; j++) {
            if (v[j] > current_max) {
                current_max = v[j];
                index = j;
            }
        }
        temp_vector[i] = current_max;
        v[index] = -1;
    }
    v = temp_vector;
}

template <class T>
void output(std::vector<T>& v) {
    for (int i = 0, size = v.size(); i < size; i++) {
        if (i != size - 1) {
            std::cout << v[i] << " ";
        } else {
            std::cout << v[i] << std::endl;
        }
    }
}
#include "function_header.h"

#include <iostream>

void input(unsigned int &n, unsigned int &t, unsigned int &velocity_x, unsigned int &acceleration_x, unsigned int &velocity_y, unsigned int &acceleration_y, unsigned int &velocity_z, unsigned int &acceleration_z) {
    std::cin >> n;
    switch (n) {
        case 1:
            std::cin >> t;
            break;
        case 2:
            std::cin >> t >> velocity_x;
            break;
        case 3:
            std::cin >> t >> velocity_x >> acceleration_x;
            break;
        case 4:
            std::cin >> t >> velocity_x >> acceleration_x >> velocity_y;
            break;
        case 5:
            std::cin >> t >> velocity_x >> acceleration_x >> velocity_y >> acceleration_y;
            break;
        case 6:
            std::cin >> t >> velocity_x >> acceleration_x >> velocity_y >> acceleration_y >> velocity_z;
            break;
        case 7:
            std::cin >> t >> velocity_x >> acceleration_x >> velocity_y >> acceleration_y >> velocity_z >> acceleration_z;
            break;
        default:
            std::cout << "input failed" << std::endl;
            break;
    }
}

inline void display_result(unsigned int t, unsigned int velocity_x, unsigned int acceleration_x, unsigned int velocity_y, unsigned int acceleration_y, unsigned int velocity_z, unsigned int acceleration_z) {
    int x = velocity_x * t + (acceleration_x * t * t) / 2;
    int y = velocity_y * t + (acceleration_y * t * t) / 2;
    int z = velocity_z * t + (acceleration_z * t * t) / 2;
    std::cout << x << " " << y << " " << z << std::endl;
}

void output(unsigned int &n, unsigned int &t, unsigned int &velocity_x, unsigned int &acceleration_x, unsigned int &velocity_y, unsigned int &acceleration_y, unsigned int &velocity_z, unsigned int &acceleration_z) {
    switch (n) {
        case 1:
            display_result(t);
            break;
        case 2:
            display_result(t, velocity_x);
            break;
        case 3:
            display_result(t, velocity_x, acceleration_x);
            break;
        case 4:
            display_result(t, velocity_x, acceleration_x, velocity_y);
            break;
        case 5:
            display_result(t, velocity_x, acceleration_x, velocity_y, acceleration_y);
            break;
        case 6:
            display_result(t, velocity_x, acceleration_x, velocity_y, acceleration_y, velocity_z);
            break;
        case 7:
            display_result(t, velocity_x, acceleration_x, velocity_y, acceleration_y, velocity_z, acceleration_z);
            break;
        default:
            std::cout << "output  failed" << std::endl;
            break;
    }
}
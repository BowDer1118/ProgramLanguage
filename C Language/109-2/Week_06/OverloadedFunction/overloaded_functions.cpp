#include "overloaded_functions.h"

#include <iostream>

void input(unsigned int& n, char& character_1, unsigned int& row, unsigned int& column, char& character_2, char& character_3) {
    std::cin >> n;
    switch (n) {
        case 1:
            std::cin >> character_1;
            break;
        case 2:
            std::cin >> character_1 >> row;
            break;
        case 3:
            std::cin >> character_1 >> row >> column;
            break;
        case 4:
            std::cin >> character_1 >> row >> column >> character_2;
            break;
        case 5:
            std::cin >> character_1 >> row >> column >> character_2 >> character_3;
            break;
        default:
            break;
    }
}

void output(unsigned int& n, char& character_1, unsigned int& row, unsigned int& column, char& character_2, char& character_3) {
    switch (n) {
        case 1:
            displayResult(n, character_1);
            break;
        case 2:
            displayResult(n, character_1, row);

            break;
        case 3:
            displayResult(n, character_1, row, column);
            break;
        case 4:
            displayResult(n, character_1, row, column, character_2);
            break;
        case 5:
            displayResult(n, character_1, row, column, character_2, character_3);
            break;
        default:
            break;
    }
}

void displayResult(unsigned int& n, char& character_1) {
    std::cout << character_1 << std::endl;
    std::cout << std::endl;
}
void displayResult(unsigned int& n, char& character_1, unsigned int& row) {
    for (int i = 0; i < row; i++) {
        std::cout << character_1 << std::endl;
    }
    std::cout << std::endl;
}
void displayResult(unsigned int& n, char& character_1, unsigned int& row, unsigned int& column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j == column - 1) {
                std::cout << character_1 << std::endl;
            } else {
                std::cout << character_1 << " ";
            }
        }
    }
    std::cout << std::endl;
}
void displayResult(unsigned int& n, char& character_1, unsigned int& row, unsigned int& column, char& character_2) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j - i == 0) {
                if (j == column - 1) {
                    std::cout << character_1 << std::endl;
                } else {
                    std::cout << character_1 << " ";
                }
            } else {
                if (j == column - 1) {
                    std::cout << character_2 << std::endl;
                } else {
                    std::cout << character_2 << " ";
                }
            }
        }
    }
    std::cout << std::endl;
}
void displayResult(unsigned int& n, char& character_1, unsigned int& row, unsigned int& column, char& character_2, char& character_3) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j - i == 0) {
                if (j == column - 1) {
                    std::cout << character_1 << std::endl;
                } else {
                    std::cout << character_1 << " ";
                }
            } else if (j - i < 0) {
                if (j == column - 1) {
                    std::cout << character_3 << std::endl;
                } else {
                    std::cout << character_3 << " ";
                }
            } else {
                if (j == column - 1) {
                    std::cout << character_2 << std::endl;
                } else {
                    std::cout << character_2 << " ";
                }
            }
        }
    }
    std::cout << std::endl;
}
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int colors[6];
} Mana;

typedef struct {
    char name[60];
    Mana mana;
    char type[60];
    int power;
    int toughless;
} Card;

int main() {
    int num;
    scanf("%d\n", &num);

    while (num--) {
        Card c;
        char input_string[300] = {0};
        char *sub_string[15];
        int index = 0;

        gets(input_string);

        sub_string[index] = strtok(input_string, " ");
        index++;

        while (1) {
            sub_string[index] = strtok(NULL, " ");

            if (sub_string[index] == NULL) {
                break;
            }
            index++;
        }

        for (int i = 0; i < index; i++) {
            if (((*sub_string[i]) == 'x' && strlen(sub_string[i]) == 1) || isdigit(*sub_string[i])) {
                index = i;
                break;
            } else {
                if (i == 0) {
                    strcpy(c.name, sub_string[i]);
                } else {
                    strcat(c.name, " ");
                    strcat(c.name, sub_string[i]);
                }
            }
        }

        for (int i = 0; i < 6; i++) {
            if (i == 0) {
                if (isalpha(*sub_string[index])) {
                    c.mana.colors[i] = (int)'x';
                } else {
                    c.mana.colors[i] = atoi(sub_string[index]);
                }
            } else {
                c.mana.colors[i] = atoi(sub_string[index]);
            }
        }
        index++;
        }

    return 0;
}
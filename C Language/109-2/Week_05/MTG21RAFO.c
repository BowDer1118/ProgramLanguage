#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int colors[6];
} Mana;

typedef struct {
    char name[50];
    Mana cost;
    char type[50];
    int power;
    int toughless;
} Card;

Mana process_mana(char *string) {
    Mana m = {0, 0, 0, 0, 0, 0};
    if (*string == 'x') {
        m.colors[0] = (int)'x';
        return m;
    }

    m.colors[0] = atoi(string);

    while (!isalpha(*string)) {
        string++;
    }

    while (*string != '\0') {
        if (strncmp(string, "White", 5) == 0) {
            m.colors[1] += 1;
            string += 5;
        } else if (strncmp(string, "Red", 3) == 0) {
            m.colors[2] += 1;
            string += 3;
        } else if (strncmp(string, "Green", 5) == 0) {
            m.colors[3] += 1;
            string += 5;
        } else if (strncmp(string, "Blue", 4) == 0) {
            m.colors[4] += 1;
            string += 4;
        } else if (strncmp(string, "Black", 5) == 0) {
            m.colors[5] += 1;
            string += 5;
        } else {
            string++;
        }
    }
    return m;
}

void write_cards(Card *cards, int len) {
    FILE *file = fopen("my_output_MTG21RAFO.txt", "wb");

    if (!file) {
        puts("Output file open failure.");
    }

    fwrite(cards, sizeof(Card), len, file);

    fclose(file);
}

int main() {
    FILE *file = fopen("test_input_MTG21RAFO.txt", "r");
    Card cards[300];
    int counter = 0;
    char input_string[300];

    if (!file) {
        puts("Input file open failure.");
        return -1;
    }

    memset(cards, 0, sizeof(cards));

    while (fgets(input_string, 300, file)) {
        char *sub_string[5];
        Card c;

        sub_string[0] = strtok(input_string, ",");
        for (int i = 1; i < 5; i++) {
            sub_string[i] = strtok(NULL, ",");
        }

        strcpy(c.name, sub_string[0]);
        c.cost = process_mana(sub_string[1]);

        strcpy(c.type, strtok(sub_string[2], "-"));

        c.power = atoi(sub_string[3]);
        c.toughless = atoi(sub_string[4]);

        cards[counter] = c;
        counter++;
    }
    fclose(file);
    write_cards(cards, counter);
    return 0;
}
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
    FILE *file = fopen("my_output_MTG21F.txt", "w");

    if (!file) {
        puts("Output file open failure.");
    }

    Card c;
    fputs("--------------------------------------------------------------------------------------------------------------------\n", file);
    fputs("Name                        Colorless   White   Red   Green   Blue   Black   Type                  Power   Toughness\n", file);
    fputs("--------------------------------------------------------------------------------------------------------------------\n", file);
    for (int i = 0; i < len; i++) {
        c = *(cards + i);
        if (isalpha(c.cost.colors[0])) {
            fprintf(file, "%-28s%9c%8d%6d%8d%7d%8d   %-22s%5d%12d\n", c.name, c.cost.colors[0], c.cost.colors[1], c.cost.colors[2], c.cost.colors[3], c.cost.colors[4], c.cost.colors[5], c.type, c.power, c.toughless);
        } else {
            fprintf(file, "%-28s%9d%8d%6d%8d%7d%8d   %-22s%5d%12d\n", c.name, c.cost.colors[0], c.cost.colors[1], c.cost.colors[2], c.cost.colors[3], c.cost.colors[4], c.cost.colors[5], c.type, c.power, c.toughless);
        }
    }
    fputs("--------------------------------------------------------------------------------------------------------------------\n", file);

    fclose(file);
}

int main() {
    FILE *file = fopen("test_input_MTG21F.txt", "r");
    Card cards[300];
    int counter = 0;
    char input_string[300];

    if (!file) {
        puts("Input file open failure.");
        return -1;
    }

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
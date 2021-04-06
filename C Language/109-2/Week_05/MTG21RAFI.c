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

void write_cards(Card *cards, int len) {
    FILE *file = fopen("my_output_MTG21RAFI.txt", "w");

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
    FILE *file = fopen("test_input_MTG21RAFI.txt", "rb");
    Card cards[285];
    char input_string[300];

    if (!file) {
        puts("Input file open failure.");
        return -1;
    }

    for (int i = 0; i < 285; i++) {
        fread(cards + i, sizeof(Card), 1, file);
        Card c = *(cards + i);
    }

    fclose(file);

    write_cards(cards, 285);
    return 0;
}
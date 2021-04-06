#include <ctype.h>
#include <stdbool.h>
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

int compare(const void *o1, const void *o2) {
    Card c1 = *(Card *)o1;
    Card c2 = *(Card *)o2;

    //降序:白紅綠藍黑無力韌type
    //升序:Name

    if (c2.mana.colors[1] == c1.mana.colors[1]) {
        if (c2.mana.colors[2] == c1.mana.colors[2]) {
            if (c2.mana.colors[3] == c1.mana.colors[3]) {
                if (c2.mana.colors[4] == c1.mana.colors[4]) {
                    if (c2.mana.colors[5] == c1.mana.colors[5]) {
                        if (c2.mana.colors[0] == c1.mana.colors[0]) {
                            if (c2.power == c1.power) {
                                if (c2.toughless == c1.toughless) {
                                    if (strcmp(c2.type, c1.type) == 0) {
                                        if (strcmp(c2.name, c1.name) == 0) {
                                            return 0;
                                        } else {
                                            return -strcmp(c2.name, c1.name);
                                        }
                                    } else {
                                        return strcmp(c2.type, c1.type);
                                    }
                                } else {
                                    return c2.toughless - c1.toughless;
                                }
                            } else {
                                return c2.power - c1.power;
                            }
                        } else {
                            return c2.mana.colors[0] - c1.mana.colors[0];
                        }
                    } else {
                        return c2.mana.colors[5] - c1.mana.colors[5];
                    }
                } else {
                    return c2.mana.colors[4] - c1.mana.colors[4];
                }
            } else {
                return c2.mana.colors[3] - c1.mana.colors[3];
            }
        } else {
            return c2.mana.colors[2] - c1.mana.colors[2];
        }
    } else {
        return c2.mana.colors[1] - c1.mana.colors[1];
    }
}

void displayCards(Card *cards, int len) {
    for (int i = 0; i < len; i++) {
        Card c = *(cards + i);
        if (isalpha(c.mana.colors[0])) {
            printf("%-28s%9c%8d%6d%8d%7d%8d%3s%-22s%5d%12d\n", c.name, c.mana.colors[0], c.mana.colors[1], c.mana.colors[2], c.mana.colors[3], c.mana.colors[4], c.mana.colors[5], "   ", c.type, c.power, c.toughless);
        } else {
            printf("%-28s%9d%8d%6d%8d%7d%8d%3s%-22s%5d%12d\n", c.name, c.mana.colors[0], c.mana.colors[1], c.mana.colors[2], c.mana.colors[3], c.mana.colors[4], c.mana.colors[5], "   ", c.type, c.power, c.toughless);
        }
    }
}

int main() {
    while (1) {
        Card cards[285];
        int counter = 0;
        int num;
        scanf("%d\n", &num);
        if (num == 0) {
            break;
        }

        while (num--) {
            Card c;
            char input_string[300] = {0};
            char *sub_string[15];
            int index = 0;

            gets(input_string);

            sub_string[index] = strtok(input_string, " ");
            index++;

            //獲取所有子字串
            while (1) {
                sub_string[index] = strtok(NULL, " ");

                if (sub_string[index] == NULL) {
                    break;
                }
                index++;
            }

            //處理c.name
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

            //處理Mana
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
                index++;
            }

            //處理type
            strcpy(c.type, sub_string[index]);
            index++;
            while (!isdigit(*sub_string[index])) {
                strcat(c.type, " ");
                strcat(c.type, sub_string[index]);
                index++;
            }

            c.power = atoi(sub_string[index]);
            index++;
            c.toughless = atoi(sub_string[index]);
            cards[counter] = c;
            counter++;
        }
        qsort(cards, counter, sizeof(Card), compare);

        displayCards(cards, counter);
        puts("");
    }
    return 0;
}
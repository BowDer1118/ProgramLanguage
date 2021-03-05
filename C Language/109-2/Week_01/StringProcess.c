#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Customized comparator
int ascending_compare(const void *o1, const void *o2) {
    char c1 = *(char *)o1;
    char c2 = *(char *)o2;
    //Check c1 c2 is upper or lower
    int s1 = isupper(c1);
    int s2 = isupper(c2);
    //Cast to lower to compare
    c1 = tolower(c1);
    c2 = tolower(c2);
    //If characters are the same alpha
    if (c1 == c2) {
        //Upper-case is bigger
        if (s1 && s2) {
            return 0;
        } else if (s2) {
            return -1;
        } else {
            return 1;
        }
    } else {
        return strcmp(&c1, &c2);
    }
}

int descending_compare(const void *o1, const void *o2) {
    char c1 = *(char *)o1;
    char c2 = *(char *)o2;
    int s1 = isupper(c1);
    int s2 = isupper(c2);
    c1 = tolower(c1);
    c2 = tolower(c2);
    if (c1 == c2) {
        if (s1 && s2) {
            return 0;
        } else if (s2) {
            return 1;
        } else {
            return -1;
        }
    } else {
        return -strcmp(&c1, &c2);
    }
}

int main() {
    int cases;
    scanf("%d", &cases);
    getchar();
    while (cases--) {
        char decision[20];
        char input_string[110];

        gets(decision);
        gets(input_string);

        char *ptr_string = input_string;
        if (strstr(decision, "UPPERCASE")) {
            while (*ptr_string != '\0') {
                *ptr_string = toupper(*ptr_string);
                ptr_string++;
            }
        } else if (strstr(decision, "LOWERCASE")) {
            while (*ptr_string != '\0') {
                *ptr_string = tolower(*ptr_string);
                ptr_string++;
            }
        } else if (strstr(decision, "CAPITALIZATION")) {
            while (*ptr_string != '\0') {
                *ptr_string = tolower(*ptr_string);
                ptr_string++;
            }
            input_string[0] = toupper(input_string[0]);
            ptr_string = input_string;
            while (*ptr_string != '\0') {
                if (isspace(*ptr_string)) {
                    *(ptr_string + 1) = toupper(*(ptr_string + 1));
                }
                ptr_string++;
            }
        } else if (strstr(decision, "ASCENDING")) {
            //Use customized comparator to sort characters
            qsort(input_string, strlen(input_string), sizeof(char), ascending_compare);
        } else if (strstr(decision, "DESCENDING")) {
            //Use customized comparator to sort characters
            qsort(input_string, strlen(input_string), sizeof(char), descending_compare);
        }
        puts(input_string);
    }
}
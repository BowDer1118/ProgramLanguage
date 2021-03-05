#include <stdio.h>
#include <string.h>

int main() {
    while (1) {
        char search_string[60] = {0};
        char replace_string[60] = {0};
        char input_string[300] = {0};

        gets(search_string);
        if (search_string[0] == '*') {
            break;
        }
        gets(replace_string);
        gets(input_string);
        //Record first substring position
        char *position;
        while ((position = strstr(input_string, search_string)) != NULL) {
            //Record those string which before and after search_string
            char font_string[300] = {0};
            char back_string[300] = {0};
            //Before search_string
            strncpy(font_string, input_string, position - input_string);

            //After search_string
            position += strlen(search_string);
            int index = 0;
            while (*position != '\0') {
                back_string[index] = *position;
                index++;
                position++;
            }
            //Reset input_string
            memset(input_string, 0, sizeof(input_string));
            //Re-assemble input_string
            strcat(input_string, font_string);
            strcat(input_string, replace_string);
            strcat(input_string, back_string);
        }
        puts(input_string);
    }
    return 0;
}

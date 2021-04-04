#include <stdbool.h>
#include <stdio.h>

int main() {
    int num;
    bool format = false;
    while (scanf("%d", &num) && num != 0) {
        unsigned int domain = 0;
        unsigned int ta, tb, tc, td, len;
        scanf("%u.%u.%u.%u/%u", &ta, &tb, &tc, &td, &len);

        if (format) {
            puts("");
        }
        puts("--------------------------------------------------------------------------------");
        printf("The following addresses are within the subnetwork %u.%u.%u.%u/%u:\n", ta, tb, tc, td, len);

        domain += (ta << 24);
        domain += (tb << 16);
        domain += (tc << 8);
        domain += td;

        domain >>= (32 - len);

        for (unsigned int i = 0; i < num; i++) {
            scanf("%u.%u.%u.%u", &ta, &tb, &tc, &td);
            unsigned int temp = 0;
            temp += (ta << 24);
            temp += (tb << 16);
            temp += (tc << 8);
            temp += td;

            temp >>= (32 - len);

            if (domain == temp) {
                printf("%u.%u.%u.%u\n", ta, tb, tc, td);
            }
        }
        puts("--------------------------------------------------------------------------------");
        format = true;
    }
    return 0;
}
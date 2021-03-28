#include <stdbool.h>
#include <stdio.h>
#define SIZE 300

void get_binary(unsigned int *num, unsigned int *binary) {
    unsigned int temp = 1 << 31;
    int index = 0;

    for (int i = 0; i < 4; i++) {
        unsigned int n = (*(num + i)) << 24;
        for (int j = 0; j < 8; j++) {
            if (n & temp) {
                binary[index] = 1;
            } else {
                binary[index] = 0;
            }
            n <<= 1;
            index++;
        }
    }
}

int main() {
    bool flag = false;

    while (1) {
        int num;
        scanf("%d", &num);
        if (num == 0) {
            break;
        }

        unsigned int domain[4] = {0};
        unsigned int bin_domain[32] = {0};
        unsigned int sub_net[4] = {0};
        unsigned int bin_sub_net[32] = {0};
        unsigned int compare_len;
        scanf("%u.%u.%u.%u/%u", &domain[0], &domain[1], &domain[2], &domain[3], &compare_len);
        get_binary(domain, bin_domain);

        if (flag) {
            puts("");
        }

        puts("--------------------------------------------------------------------------------");
        printf("The following addresses are within the subnetwork %u.%u.%u.%u/%d:\n", domain[0], domain[1], domain[2], domain[3], compare_len);

        for (int i = 0; i < num; i++) {
            scanf("%u.%u.%u.%u", &sub_net[0], &sub_net[1], &sub_net[2], &sub_net[3]);
            get_binary(sub_net, bin_sub_net);

            bool same = true;
            for (int j = 0; j < compare_len; j++) {
                if (bin_domain[j] != bin_sub_net[j]) {
                    same = false;
                    break;
                }
            }

            if (same) {
                printf("%d.%d.%d.%d\n", sub_net[0], sub_net[1], sub_net[2], sub_net[3]);
            }
        }

        puts("--------------------------------------------------------------------------------");
        flag = true;
    }
    return 0;
}
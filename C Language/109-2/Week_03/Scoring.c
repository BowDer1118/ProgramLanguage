#include <stdbool.h>
#include <stdio.h>

double doDivAndRoundDown(int num, int div) {
    num *= 100;
    num /= div;
    return num / 100.0;
}

int main() {
    bool flag = false;
    while (true) {
        int std_num;
        scanf("%d", &std_num);

        if (std_num == 0) {
            break;
        }

        if (flag) {
            puts("");
        }

        puts("==================================================");
        puts("Index   Attendance   Practice   Exam   Final Score");
        puts("==================================================");

        int total_score[4] = {0};  //出席 練習 考試 最終分數

        for (int i = 0; i < std_num; i++) {
            int ta, tb, tc;
            scanf("%d %d %d", &ta, &tb, &tc);
            total_score[0] += ta;
            total_score[1] += tb;
            total_score[2] += tc;
            total_score[3] += ta + tb * 3 + tc * 6;

            printf("%05d%13d%11d%7d%14.2lf\n", (i + 1), ta, tb, tc, (ta + tb * 3 + tc * 6) * 0.1);
        }
        puts("==================================================");
        printf("%4s%14.2lf%11.2lf%7.2lf%14.2lf\n", "Mean", doDivAndRoundDown(total_score[0], std_num), doDivAndRoundDown(total_score[1], std_num), doDivAndRoundDown(total_score[2], std_num), doDivAndRoundDown(total_score[3], std_num * 10));
        puts("==================================================");
        flag = true;
    }
    return 0;
}
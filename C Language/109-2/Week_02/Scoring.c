#include <stdbool.h>
#include <stdio.h>

//小數點下兩位無條件省略
double get_average(double total, int num) {
    double d_temp = total / num;
    int i_temp = (int)(d_temp * 100);
    return (double)i_temp / 100;
}

int main() {
    //控制換行
    bool flag = false;
    while (1) {
        int std_num;
        scanf("%d", &std_num);

        if (std_num == 0) {
            break;
        }

        //每一筆資料空一行
        if (flag) {
            puts("");
        }

        puts("==================================================");
        printf("%-8s%-13s%-11s%-7s%s\n", "Index", "Attendance", "Practice", "Exam", "Final Score");
        puts("==================================================");
        //儲存 出席 練習 考試 的總成績 (整數總和)
        int total_scores[4] = {0};

        for (int i = 0; i < std_num; i++) {
            int ta, tb, tc;
            scanf("%d %d %d", &ta, &tb, &tc);
            //輸出才使用除法-->避免儲存問題造成結果誤差
            printf("%05d%13d%11d%7d%14.2lf\n", (i + 1), ta, tb, tc, (ta * 1 + tb * 3 + tc * 6) * 0.1);
            total_scores[0] += ta;
            total_scores[1] += tb;
            total_scores[2] += tc;
            total_scores[3] += ta * 1 + tb * 3 + tc * 6;
        }

        puts("==================================================");
        //輸出時才做除法-->避免誤差
        printf("%-13s%-11.2lf%-7.2lf%-14.2lf%-5.2lf\n", "Mean", get_average(total_scores[0], std_num), get_average(total_scores[1], std_num), get_average(total_scores[2], std_num), get_average(total_scores[3] * 0.1, std_num));
        puts("==================================================");

        flag = true;
    }
    return 0;
}
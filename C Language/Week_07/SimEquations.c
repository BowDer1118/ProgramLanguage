#include <math.h>     //導入function pow所在的資料庫
#include <stdbool.h>  //導入boolean value所在的資料庫
#include <stdio.h>
int main() {
    int u, v, w;
    while (scanf("%d %d %d", &u, &v, &w) != EOF) {
        bool flag = true;  //未找到答案則表示true
        //使用x^3+y^2+z=w改寫成x=(int)(pow(w,1.0/3)+1)
        //可以讓x的最大值最大
        //由大往小找
        if (flag) {                                                 //沒有找到才要繼續找
            for (int x = (int)(pow(w, 1.0 / 3) + 1); x > 0; x--) {  //因為pow回傳值是double類型，為避免精度問題導致資料不正確，則+1再強制取整
                if (flag) {
                    //使用x^3+y^2+z=w改寫成y=(int)(pow(w-x*x*x,1.0/2)+1)
                    //可以讓y的最大值最大
                    for (int y = (int)(pow(w - x * x * x, 1.0 / 2) + 1); y > 0; y--) {
                        if (flag) {
                            //x,y都假設好了,使用x+2*y+3*z=u會讓z最大
                            for (int z = u - x - 2 * y; z > 0; z--) {
                                //若x,y,z滿足聯立方程式
                                if (x + 2 * y + 3 * z == u && x * y * z == v && x * x * x + y * y + z == w) {
                                    int t1, t2, t3;  //存放最小到最大值
                                    //三數比大小
                                    if (x > y && x > z) {  //假設x最大
                                        t3 = x;
                                        if (y > z) {
                                            t2 = y;
                                            t1 = z;
                                        } else {
                                            t2 = z;
                                            t1 = y;
                                        }
                                    } else if (y > x && y > z) {  //假設y最大
                                        t3 = y;
                                        if (x > z) {
                                            t2 = x;
                                            t1 = z;
                                        } else {
                                            t2 = z;
                                            t1 = x;
                                        }
                                    } else {
                                        t3 = z;
                                        if (x > y) {
                                            t2 = x;
                                            t1 = y;
                                        } else {
                                            t2 = y;
                                            t1 = x;
                                        }
                                    }
                                    printf("%d %d %d\n", t1, t2, t3);
                                    flag = false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

/*  Q:
    如何有"效率地"找出所有x,y,z?
    Sol:
    假設x為最大，再假設y為最大，這樣z的值域就會被固定出來了
*/
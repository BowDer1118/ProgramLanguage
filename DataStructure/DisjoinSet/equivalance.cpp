#include <bits/stdc++.h>
#define maxN 10000
using namespace std;

//能容納maxN個元素(編號:0~maxN-1)
class DisjoinSet {
private:
    int parent[maxN];
    int range;

public:
    DisjoinSet(int range) {  //有range個(0~range-1)
        this->range = range;
        for (int i = 0; i < range; i++) {
            parent[i] = -1;  //初始化每個set都只有abs(parent[i])個
        }
    }
    //找index=p的元素的根結點index--->返回根節點index
    int do_find(int p) {
        int pRoot;
        //找到根結點
        for (pRoot = p; parent[pRoot] >= 0; pRoot = parent[pRoot]) {
        }
        //優化路徑上元素的根節點
        int head, tail;
        //將p往pRoot經過的節點的父節點都指向pRoot
        for (tail = p; tail != pRoot; tail = head) {
            head = parent[tail];
            parent[tail] = pRoot;
        }
        return pRoot;
    }
    //小set往大set做union
    void do_union(int p, int q) {
        //先找根節點
        int pRoot = do_find(p);
        int qRoot = do_find(q);

        if (pRoot > qRoot) {  //負數比大小:pRoot數量<qRoot數量
            //將p接到q
            parent[qRoot] += parent[pRoot];  //更新set大小
            parent[pRoot] = qRoot;           //union
        } else {
            parent[pRoot] += parent[qRoot];
            parent[qRoot] = pRoot;
        }
    }
    //查看p與q的根節點是否相同
    bool isConnect(int p, int q) {
        return do_find(p) == do_find(q);
    }
    //顯示每個set中的元素
    void show() {
        //對每個元素都查找一遍(將元素整理到指向樹根)
        for (int i = 0; i < range; i++) {
            do_find(i);
        }
        for (int i = 0; i < range; i++) {
            if (parent[i] < 0) {  //為root
                printf("Set: %d ", i);
                for (int j = 0; j < range; j++) {
                    if (parent[j] == i) {
                        printf("%d ", j);
                    }
                }
                printf("\n");
            }
        }
    }
};

int n, p;  //數量、組數
int ta, tb;

int main() {
    freopen("test.txt", "r", stdin);
    scanf("%d %d", &n, &p);

    DisjoinSet s(n);  //共n個元素

    for (int i = 0; i < p; i++) {
        scanf("%d %d", &ta, &tb);
        s.do_union(ta, tb);
    }
    s.show();
    return 0;
}
#include "Banker.h"
using namespace std;

istream &operator>>(istream &input, Banker &b) {
    for (int i = 0; i < b.threads; i++) {
        for (int j = 0; j < b.resources; j++) {
            cin >> (*(*(b.allocation + i) + j));
        }
    }

    for (int i = 0; i < b.threads; i++) {
        for (int j = 0; j < b.resources; j++) {
            cin >> (*(*(b.need + i) + j));
        }
    }

    for (int i = 0; i < b.resources; i++) {
        cin >> *(b.available + i);
    }

    return input;
}

Banker::Banker(size_t n, size_t m) {
    threads = n;
    resources = m;
    int **ptr_allocation = new int *[n];
    int **ptr_need = new int *[n];
    int *ptr_available = new int[m];

    for (int i = 0; i < n; i++) {
        *(ptr_allocation + i) = new int[m];
        *(ptr_need + i) = new int[m];
    }

    this->allocation = ptr_allocation;
    this->need = ptr_need;
    this->available = ptr_available;
}

Banker::~Banker() {
    int len = threads;
    for (int i = 0; i < len; i++) {
        delete[] * (allocation + i);
        delete[] * (need + i);
    }
    delete[] allocation;
    delete[] need;
    delete[] available;
}

int **Banker::getAllocation() {
    return allocation;
}

int **Banker::getNeed() {
    return need;
}

int *Banker::getAvailable() {
    return available;
}

bool Banker::safety() {
    //配置暫存陣列
    bool *finish = new bool[threads];  //Threads狀態
    int *work = new int[resources];    //當前可用資源(包括已回收的)
    //初始化需要的資料
    for (int i = 0; i < threads; i++) {
        finish[i] = false;
    }
    for (int i = 0; i < resources; i++) {
        work[i] = *(available + i);
    }
    //開始banker演算法
    bool checked = false;                              //是否掃描過所有thread(控制是否再次掃描)
    while (!checked) {                                 //如果沒有被檢查
        checked = true;                                //已經掃描過
        for (int i = 0; i < threads; i++) {            //掃描所有thread
            int *contain = *(allocation + i);          //當前threads所含的資源陣列
            int *needed = *(need + i);                 //當前threads所需的資源陣列
            if (!finish[i]) {                          //當前thread還沒執行
                bool canCover = true;                  //當前work是否可提供此threads所需
                for (int j = 0; j < resources; j++) {  //檢查是否真的可提供資源
                    if (*(needed + j) > work[j]) {
                        canCover = false;
                        break;
                    }
                }
                if (canCover) {  //可以提供資源執行
                    //回收threads所含有的資源--->刷新work陣列
                    for (int j = 0; j < resources; j++) {
                        work[j] += contain[j];
                    }
                    finish[i] = true;
                    checked = false;  //將sanned設置成false--->要求再次掃描
                }
            }
        }
    }
    //嘗試過所有可能後--->判斷系統是否安全
    bool safe = true;  //假設安全
    for (int i = 0; i < threads; i++) {
        if (!finish[i]) {
            safe = false;
        }
    }

    //先釋放動態記憶體
    delete[] finish;
    delete[] work;
    return safe;  //回傳最後的判斷結果
}

bool Banker::operator()(size_t mid_thread) {
    //先備份所有資料
    int *copy_allocation = new int[resources];
    int *copy_need = new int[resources];
    int *copy_available = new int[resources];

    for (int i = 0; i < resources; i++) {
        copy_allocation[i] = *(*(allocation + mid_thread) + i);
        copy_need[i] = *(*(need + mid_thread) + i);
        copy_available[i] = *(available + i);
    }

    for (int i = 0; i < resources; i++) {
        //取resource值
        int value = *(*(need + mid_thread) + i) / 2;
        //Allocation加值
        (*(*(allocation + mid_thread) + i)) += value;
        //Need減值
        (*(*(need + mid_thread) + i)) -= value;
        //Available減值
        *(available + i) -= value;
    }

    bool result = this->safety();

    //將被更動的值存回來(取備份)
    for (int i = 0; i < resources; i++) {
        *(*(allocation + mid_thread) + i) = copy_allocation[i];
        *(*(need + mid_thread) + i) = copy_need[i];
        *(available + i) = copy_available[i];
    }

    //釋放動態記憶體
    delete[] copy_allocation;
    delete[] copy_need;
    delete[] copy_available;
    return result;
}

bool Banker::operator()(size_t mid_thread, size_t mid_resource) {
    //備份值
    int copy_allocation = *(*(allocation + mid_thread) + mid_resource);
    int copy_need = *(*(need + mid_thread) + mid_resource);
    int copy_available = *(available + mid_resource);

    int value = copy_need / 2;

    //改變值
    *(*(allocation + mid_thread) + mid_resource) += value;
    *(*(need + mid_thread) + mid_resource) -= value;
    *(available + mid_resource) -= value;

    bool result = this->safety();

    //存回值
    *(*(allocation + mid_thread) + mid_resource) = copy_allocation;
    *(*(need + mid_thread) + mid_resource) = copy_need;
    *(available + mid_resource) = copy_available;

    return result;
}
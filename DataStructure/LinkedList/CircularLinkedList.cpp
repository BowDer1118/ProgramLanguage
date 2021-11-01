#include <algorithm>
#include <iostream>
using namespace std;

//只記錄最後一個節點位置 可以實現一般LinkedList的插入 而且後方插入時間複雜度是O(1)
template <typename Item>
class CircularLinkedList {
    friend ostream &operator<<(ostream &os, CircularLinkedList<Item> list) {
        Node *temp = list.last->next;  //獲取第一個節點位置
        while (temp != list.last) {
            cout << temp;
            temp = temp->next;
        }
        cout << temp;
        return os;
    }

private:
    struct Node {
        Item data;
        Node *next;
        Node(Item data, Node *next_pos) : data(data), next(next_pos) {}
        Node(Item item) : data(item), next(NULL) {}
        Node() {}
        ~Node() {}
        friend ostream &operator<<(ostream &os, Node *node) {
            cout << node->data << "\n";
            return os;
        }
    };
    Node *last;
    int count;

public:
    CircularLinkedList() : last(NULL), count(0) {}
    ~CircularLinkedList() {
        Node *temp = last->next;
        Node *del;  //紀錄要被刪除的點
        while (temp != last) {
            del = temp;
            temp = temp->next;
            cout << "Free " << del;
            delete del;
        }
        cout << "Free " << temp;
        delete temp;
    }
    bool isEmpty() {
        if (last) {
            return false;
        } else {
            return true;
        }
    }
    int size() {
        return count;
    }
    void front_insert(Item item) {
        if (!last) {  //串列為空
            Node *node = new Node(item, NULL);
            last = node;
            last->next = last;  //自己接自己
            return;
        } else {
            //新的第一個節點指向舊的第一個節點
            Node *node = new Node(item, last->next);
            last->next = node;  //舊的最後一個位置指向新的第一個位置
        }
    }
    void back_insert(Item item) {
        if (!last) {
            Node *node = new Node(item, NULL);
            last = node;
            last->next = last;
        } else {
            //新的最後一個節點指向第一個節點
            Node *node = new Node(item, last->next);
            last->next = node;  //舊的最後一個節點指向新的最後一個節點
            last = node;        //更新 最後節點的位置
        }
    }
    //查詢串列是否含有item
    bool contain(Item item) {
        if (last->data == item) {
            return true;
        }
        Node *temp = last->node;  //獲取第一個節點位置
        while (temp != last) {    //還沒走訪過一輪
            if (temp->data == item) {
                return true;
            }
        }
        return false;
    }
    //刪除傳入的資料(如果有)
    void remove(Item item) {
        if (!last) {  //串列為空
            return;
        }

        Node *prev = last;        //指向最後一個節點
        Node *temp = last->next;  //指向第一節點
        while (temp != last) {
            if (temp->data == item) {  //找到要刪除的節點
                prev->next = temp->next;
                last = prev;  //更新最後一個節點位置
                delete temp;
                return;
            } else {
                prev = temp;        //當前節點變成上個節點
                temp = temp->next;  //前往下一個節點
            }
        }

        if (temp->data == item) {  //如果最後一個節點是要刪除的節點
            prev->next = temp->next;
            last = prev;
            delete temp;
        }
    }
};

void sample1() {
    CircularLinkedList<int> list;
    int arr[] = {3, 1, 5, 4, 2, 6};
    for (int i = 0; i < 6; i++) {
        if (i < 3) {
            list.front_insert(arr[i]);
        } else {
            list.back_insert(arr[i]);
        }
    }
    cout << list;  //5 1 3 4 2 6
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sample1();
    return 0;
}
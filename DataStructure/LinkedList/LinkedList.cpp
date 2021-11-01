#include <algorithm>
#include <iostream>
using namespace std;

template <typename Item>
class LinkedList {
    //Overload cout
    friend ostream &operator<<(ostream &os, LinkedList<Item> list) {
        while (list.head) {
            os << list.head;
            list.head = list.head->next;
        }
        return os;
    }

private:
    //私有struct(不給外部調用)
    struct Node {
        //Overload cout
        friend ostream &operator<<(ostream &os, Node *node) {  //注意傳入的是node指標
            os << node->data << "\n";
            return os;
        }
        Item data;
        Node *next;
        Node(Item data, Node *next) : data(data), next(next) {}
        Node() {}
        ~Node() {}
    };
    Node *head;  //LinkedList的第一個節點位置
    int count;   //LinkedList的節點總數
public:
    LinkedList() : head(NULL), count(0) {}
    ~LinkedList() {
        while (head) {          //還有節點
            Node *temp = head;  //暫存要被刪掉的節點位置
            head = head->next;  //移動到下一個節點
            cout << "Free node " << temp;
            delete temp;  //釋放上一個節點
            count--;      //更新節點數量
        }
    }
    int size() {
        return count;
    }
    bool isEmpty() {
        if (count) {
            return false;
        } else {
            return true;
        }
    }
    //從最後的位置插入
    void insert(Item item) {
        //沒有任何節點
        if (!head) {
            Node *node = new Node(item, NULL);
            head = node;
            count++;
            return;
        }
        //存在節點
        Node *temp = head;            //拷貝起點(用來向後走訪)
        while (temp->next != NULL) {  //先到最後一個節點
            temp = temp->next;
        }
        Node *node = new Node(item, NULL);
        temp->next = node;
        count++;
    }

    //檢查是否有儲存item
    bool contain(Item item) {
        if (!head) {  //LinkedList為空
            return false;
        }
        Node *temp = head;
        while (temp) {  //檢查每個節點
            if (temp->data == item) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    //移除特定資料(如果有)
    void remove(Item item) {
        if (!head) {  //LinkedList為空
            return;
        }
        Node *prev = NULL;
        Node *current = head;
        //第一個節點就是要被刪除的節點
        if (current->data == item) {
            if (current->next) {  //如果LinkedList的長度>1
                Node *temp = current;
                current = current->next;
                delete temp;     //釋放第一個節點
                head = current;  //更新LinkedList第一個節點
            } else {             //如果只有1個節點
                delete head;
                head = NULL;
            }
            count--;  //更新節點數量
            return;
        }

        while (current) {
            if (current->data == item) {  //如果當前節點要被刪除
                //刪除Node
                prev->next = current->next;  //將上一個節點指向下一個節點
                delete current;              //釋放當前節點
                count--;
                return;
            }
            prev = current;           //將當前節點變成上一個節點
            current = current->next;  //往下一個節點走
        }
    }
    //翻轉LinkedList
    void invert() {
        Node *p, *c, *n;  //previous current next position
        c = NULL;
        n = head;

        while (n) {
            p = c;
            c = n;
            n = n->next;
            c->next = p;
        }
        head = c;
    }
};

//basic data type
void sample1() {
    LinkedList<int> list;
    int arr[] = {3, 1, 5, 4, 2};
    //將arr的元素加入list中
    for (int i = 0; i < 5; i++) {
        list.insert(arr[i]);
    }
    cout << "List size:" << list.size() << "\n";
    cout << "List elements:\n";
    cout << list;  //3 1 5 4 2
    cout << "After invert:\n";
    list.invert();
    cout << list;  // 2 4 5 1 3
}

int main() {
    //加速cin cout
    ios::sync_with_stdio(false);  //取消與stdio同步
    cin.tie(NULL);                //取消cin cout綁定(避免觸發flush)

    sample1();
    return 0;
}
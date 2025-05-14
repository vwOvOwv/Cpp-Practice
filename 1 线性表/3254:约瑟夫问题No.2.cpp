// http://bailian.openjudge.cn/practice/3254/

// simulation with list

#include <cstddef>
#include <iostream>

using namespace std;

int n, p, m;

class listNode{
public:
    int index;
    listNode *next;
    listNode(){}
    listNode(int index=0, listNode *next=nullptr){
        this->index = index;
        this->next = next;
    }
};

void josephus(int n, int p, int m){
    listNode * head = nullptr;
    listNode *cur = nullptr;
    listNode * start = nullptr;
    for (int i = 1; i <= n; i++){
        listNode *node = new listNode(i, NULL);
        if(i == 1){
            head = node;
            cur = node;
        }
        else{
            cur->next = node;
            cur = node;
        }

        if(i == p)
            start = node;
    }
    cur->next = head;
    // cout << head->index << endl;
    // cout << cur->index << endl;
    // cout << start->index << endl;
    int killed_num = 0;
    while(killed_num < n){
        listNode *p = start;
        for(int i = 0; i < m - 2; i++)
            p = p->next;
        start = p->next->next;
        cout << p->next->index;
        delete p->next;
        p->next = start;
        killed_num++;
        if(killed_num != n){
            cout <<',';
        }
    }
    cout << endl;
}

int main(){
    while(cin >> n >> p >> m){
        if(n == 0 && p == 0 && m == 0){
            return 0;
        }
        josephus(n, p, m);
    }
}
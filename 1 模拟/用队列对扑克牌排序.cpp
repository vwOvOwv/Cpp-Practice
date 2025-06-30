// http://dsa.openjudge.cn/stack/0303/

#include <bits/stdc++.h>

using namespace std;

class Card{
public:
    char color;
    int point;
    Card(char _color, int _point): color(_color), point(_point){}
};

int main(){
    int N1 = 9, N2 = 4;
    vector<queue<Card>> q1(N1, queue<Card>());
    vector<queue<Card>> q2(N2, queue<Card>());
    vector<Card> record;

    int n;
    string card;
    cin >> n;
    int tmp = n;
    while(tmp--){
        cin >> card;
        Card new_card = Card(card[0], card[1] - '0');
        q1[new_card.point - 1].push(new_card);
    }
    for(int i = 0; i < N1; i++){
        cout << "Queue" << i + 1 << ":";
        while(!q1[i].empty()){
            Card cur_card = q1[i].front();
            q1[i].pop();
            q2[cur_card.color - 'A'].push(cur_card);
            cout << cur_card.color << cur_card.point;
            if(q1[i].size() >= 1)
                cout << ' ';
        }
        cout << endl;
    }
    for(int i = 0; i < N2; i++){
        cout << "Queue" << char('A' + i) << ":";
        while(!q2[i].empty()){
            Card cur_card = q2[i].front();
            q2[i].pop();
            cout << cur_card.color << cur_card.point;
            if(q2[i].size() >= 1)
                cout << ' ';
            record.push_back(cur_card);
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        cout << record[i].color << record[i].point;
        if(i < n - 1)
            cout << ' ';
    }
    cout << endl;
    return 0;
}
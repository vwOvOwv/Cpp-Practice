// http://dsa.openjudge.cn/linearlist/0206/
// simulation

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec;

void add(int d){
    for(int i = 0; i < N; i++){
        vec[i] = (vec[i] + d) % 65536;
    }
    return;
}

int query(int j){
    int ans = 0;
    for(int i = 0; i < N; i++){
        if((vec[i] >> j) & 1)
            ans++;
    }
    return ans;
}

int main(){
    cin >> N >> M;
    vec.resize(N, 0);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }
    char oper;
    int operand;
    for(int i = 0; i < M; i++){
        cin >> oper >> operand;
        if(oper == 'Q')
            cout << query(operand) << endl;
        else
            add(operand);
    }
    return 0;
}
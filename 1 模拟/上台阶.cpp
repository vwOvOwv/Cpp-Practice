// http://noi.openjudge.cn/ch0203/3525/

#include <bits/stdc++.h>

using namespace std;

int N = 30;
vector<int> rec(N, 0);

int main(){
    rec[1] = 1;
    rec[2] = 2;
    rec[3] = 4;
    for(int i = 4; i < N; i++){
        rec[i] = rec[i - 3] + rec[i - 2] + rec[i - 1];
    }
    int n;
    while(cin >> n && n){
        cout << rec[n] << endl;
    }
    return 0;
}
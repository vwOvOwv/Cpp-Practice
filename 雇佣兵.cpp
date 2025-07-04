// http://noi.openjudge.cn/ch0105/37/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int M, N, X;
    cin >> M >> N >> X;
    int cur_n = N;
    while(true){
        if(X * cur_n < M)
            break;
        X -= (M / cur_n + (M % cur_n != 0));
        cur_n += (M / cur_n);
    }
    cout << cur_n << endl;
    return 0;
}
// http://bailian.openjudge.cn/xly2019/A/

#include<bits/stdc++.h>

using namespace std;

int N = 1e6 + 1;
vector<int> rec(N, 0);

char str_a[10];
char str_b[10];

int string_max(int a, int b){
    int res;
    itoa(a, str_a, 10);
    itoa(b, str_b, 10);
    string string_a(str_a);
    string string_b(str_b);
    if(string_a > string_b)
        return a;
    else
        return b;
}

int main(){
    for(int i = 1; i <= 9; i++){
        rec[i] = i;
    }
    for(int i = 10; i < N; i++){
        rec[i] = string_max(rec[i - 1], i);    
    }

    int n;
    while(cin >> n && n){
        cout << rec[n] << endl;
    }
    return 0;
}
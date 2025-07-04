// http://bailian.openjudge.cn/practice/2000/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int remain = n;
        int ans = 0;
        int cur = 0;
        while(remain > 0){
            cur++;
            ans += cur * cur;
            remain -= cur;
        }
        remain += cur;
        ans -= cur * cur;
        ans += remain * cur;
        cout << n << ' ' << ans << endl;
    }
    return 0;
}
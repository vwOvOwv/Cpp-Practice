// http://bailian.openjudge.cn/xly2024062702/A/
// 求平方和

#include <iostream>

using namespace std;

long ans = 0;

int main(){
    int n, cnt = 0, i;
    cin >> n;
    for(i = 1; i < n; i++){
        ans += i * i;
        cnt += i;   // 记录发了多少天工资
        if(cnt > n) // 天数够了
            break;
    }
    ans -= i * i;   // 减掉多发的
    cnt -= i;
    ans += i * (n - cnt);
    cout << ans << endl;
    return 0;
}
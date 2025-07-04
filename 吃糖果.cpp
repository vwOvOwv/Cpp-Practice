// http://noi.openjudge.cn/ch0206/1944/
// dp[k]:k块巧克力的方案数
// dp[k] = dp[k - 1] + dp[k - 2]
// dp[1] = 1, dp[2] = 2

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << endl;
    return 0;
}
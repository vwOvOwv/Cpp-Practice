// http://noi.openjudge.cn/ch0206/8785/
// dp[i][j]: 箱子容量为i且考虑前j个物品时可装入的最大体积
// dp[i][j] = max{dp[i][j-1], dp[i-v[j]][j-1] + v[j]}
// dp[0][*] = 0, dp[*][0] = 0

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int v_box, n;
    cin >> v_box >> n;
    vector<int> v_obj(n + 1, 0);
    vector<vector<int>> dp(v_box + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        cin >> v_obj[i];
    }
    for(int i = 1; i <= v_box; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j - 1];
            if(i - v_obj[j] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - v_obj[j]][j - 1] + v_obj[j]);
            }
        }
    }
    cout << v_box - dp[v_box][n] << endl;
    return 0;
}
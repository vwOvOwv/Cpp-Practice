// http://noi.openjudge.cn/ch0206/1775/
// 0-1背包

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T, M;
    cin >> T >> M;
    vector<int> times(M + 1, 0);
    vector<int> values(M + 1, 0);
    for(int i = 1; i <= M; i++){
        cin >> times[i] >> values[i];
    }
    vector<vector<int>> dp(T + 1, vector<int>(M + 1, 0));
    for(int t = 1; t <= T; t++){
        for(int m = 1; m <= M; m++){
            dp[t][m] = dp[t][m - 1];
            if(times[m] <= t){
                dp[t][m] = max(dp[t][m], dp[t - times[m]][m - 1] + values[m]);
            }
        }
    }
    cout << dp[T][M] << endl;
    return 0;
}
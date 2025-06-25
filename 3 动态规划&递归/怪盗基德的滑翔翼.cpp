// http://noi.openjudge.cn/ch0206/4977/
// dp[i][0]: 从第i栋建筑开始向左的最长下降序列长度
// dp[i][1]: 从第i栋建筑开始向右的最长下降序列长度
// dp[i][0] = max{dp[j][0] + 1}, h[j] < h[i], j < i
// dp[i][1] = max{dp[j][1] + 1}, h[j] < h[i], j > i

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int K;
    cin >> K;
    while(K--){
        int N;
        cin >> N;
        vector<int> h(N + 1, 0x7fffffff);
        for(int i = 1; i <= N; i++){
            cin >> h[i];
        }
        vector<vector<int> > dp(N + 1, vector<int>(2, 0));
        for(int i = 2; i <= N; i++){
            int max_len = 0;
            for(int j = i - 1; j >= 1; j--){
                if(h[j] < h[i]){
                    max_len = max(max_len, dp[j][0] + 1);
                }
                // else {       // 题目没说清楚，实际上可以绕过高的建筑，即可以不连续下降
                //     break;
                // }
            }
            dp[i][0] = max_len;
        }
        for(int i = N - 1; i >= 1; i--){
            int max_len = 0;
            for(int j = i + 1; j <= N; j++){
                if(h[j] < h[i]){
                    max_len = max(max_len, dp[j][1] + 1);
                }
                // else {
                //     break;
                // }
            }
            dp[i][1] = max_len;
        }
        int ans = -1;
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < 2; j++){
                ans = max(ans, dp[i][j]);
                // cout << dp[i][j] << ' ';
            }
            // cout << endl;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
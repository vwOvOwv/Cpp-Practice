// http://noi.openjudge.cn/ch0206/1768/
// 转换为最大子段和，注意数据预处理

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> nums(N, vector<int>(N, 0));
    vector<vector<vector<int>>> sum(N, vector<vector<int>>(N, vector<int>(N, 0)));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> nums[i][j];
        }
        sum[i][i] = nums[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = 0; k < N; k++)
                sum[i][j][k] = sum[i][j - 1][k] + nums[j][k];
        }
    }
    int max_val = 0x80000000;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            vector<int> summed_nums = sum[i][j];
            vector<int> dp(N, 0);
            dp[0] = summed_nums[0];
            for(int k = 1; k < N; k++){
                dp[k] = max(dp[k - 1] + summed_nums[k], summed_nums[k]);
                if(dp[k] > max_val){
                    max_val = dp[k];
                }
            }
        }
    }
    cout << max_val << endl;
    return 0;
}
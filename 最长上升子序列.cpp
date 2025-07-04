// http://noi.openjudge.cn/ch0206/1759/
// dp[i]: 以nums[i]结尾的最长上升子序列

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main(){
    cin >> N;
    vector<int> dp(N,1);
    vector<int> nums(N, 0);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int res = 0x80000000;
    for(int i = 0; i < N; i++){
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}
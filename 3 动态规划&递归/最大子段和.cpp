// https://leetcode.cn/problems/maximum-subarray/
// dp[i]: 以nums[i]结尾的子段的最大子段和
// dp[0] = nums[0], dp[i] = max(dp[i - 1] + nums[i], nums[i])

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
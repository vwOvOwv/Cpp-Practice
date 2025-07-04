// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
// dp[i]: 前i天可得到的最大利润
// min_price[i]: 前i天内的股票最低价
// price[i]: 第i天股票的价格
// min_price[0] = +inf, min_price[i] = min(price[i], min_price[i - 1])
// dp[0] = 0, dp[i] = max(dp[i - 1], price[i] - min_price[i])

#include <vector>

using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> dp(n + 1, -1);
//         vector<int> min_price(n + 1, 0x7fffffff);
//         for(int i = 1; i <= n; i++){
//             min_price[i] = min(min_price[i - 1], prices[i - 1]);
//             dp[i] = max(dp[i - 1], prices[i - 1] - min_price[i]);
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, -1);
        int min_price = 0x7fffffff;
        for(int i = 1; i <= n; i++){
            min_price = min(min_price, prices[i - 1]);
            dp[i] = max(dp[i - 1], prices[i - 1] - min_price);
        }
        return dp[n];
    }
};
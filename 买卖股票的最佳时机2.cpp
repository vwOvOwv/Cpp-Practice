// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
// 交易次数无限制且最多只能持有一只股票
// 因此只要price[i] > price[i - 1]就在第i - 1天买入，第i天卖出
// 一次可获得price[i] - price[i - 1]的利润

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for(int i = 1; i < n; i++){
            int diff = prices[i] - prices[i - 1];
            if(diff > 0){
                ans += diff;
            }
        }
        return ans;
    }
};
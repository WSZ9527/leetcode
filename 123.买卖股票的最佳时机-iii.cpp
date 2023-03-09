/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1000000)));
        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == 0 && k < 2)
                        dp[i + 1][1][k + 1] = max(dp[i + 1][1][k + 1], dp[i][0][k] - prices[i + 1]);
                    else if (j == 1)
                        dp[i + 1][0][k] = max(dp[i + 1][0][k], dp[i][1][k] + prices[i + 1]);
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                }
            }
        }

        int ans = 0;
        for (int k = 1; k < 3; k++)
            ans = max(ans, dp[n][0][k]);

        return ans;
    }
};
// @lc code=end

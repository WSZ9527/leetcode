/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(int c, vector<int> &prices)
    {
        int n = prices.size();
        prices.insert(prices.begin(), INT_MIN);

        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(2, vector<int>(c + 1, -1000000000)));
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k <= c; k++)
                {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j == 0)
                        f[i][0][k] = max(f[i][0][k], f[i - 1][1][k] + prices[i]);
                    if (j == 1 && k > 0)
                        f[i][1][k] = max(f[i][1][k], f[i - 1][0][k - 1] - prices[i]);
                }
            }
        }
        int ans = 0;
        for (int k = 1; k <= c; k++)
            ans = max(ans, f[n][0][k]);
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int low = INT_MAX, ans = 0;
        for(auto price:prices){
            ans = max(ans, price - low);
            low = min(low, price);
        }

        return ans;
    }
};
// @lc code=end

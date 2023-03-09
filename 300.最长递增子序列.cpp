/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = n - 1; i > 0; --i)
            for (int j = i - 1; j >= 0; --j)
                if (nums[i] > nums[j])
                    dp[j] = max(dp[j], dp[i] + 1);

        int ans = 0;
        for (auto &n : dp)
            ans = max(ans, n);
        return ans;
    }
    int lengthOfLIS1(vector<int> &nums)
    {
        n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ans = max(dfs(nums, i), ans);
            // cout << ans << endl;
        }
        return ans;
    }

    int dfs(vector<int> &nums, int index)
    {
        if (mem.find(index) != mem.end())
            return mem[index];

        int cans = 1;
        for (int i = index + 1; i < n; ++i)
        {
            if (nums[index] < nums[i])
                cans = max(cans, dfs(nums, i) + 1);
        }

        mem[index] = cans;
        return cans;
    }

    int n;
    int ans = 1;
    unordered_map<int, int> mem;
};
// @lc code=end

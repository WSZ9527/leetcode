/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        //first 记录长度
        //second 记录个数
        vector<pair<int, int>> dp(n, {1, 1});
        //用于记录最大长度
        int maxl = 1;
        for (int i = n - 1; i > 0; --i)
        {
            //自底向上推
            for (int j = i - 1; j >= 0; --j)
            {
                //寻找比自己小的
                if (nums[j] < nums[i])
                {
                    //向前+1步
                    int l = dp[i].first + 1;
                    //取更长的长度
                    if (dp[j].first < l)
                        dp[j] = {l, dp[i].second};
                    else if (dp[j].first == l)//等长，那么累加个数
                        dp[j].second += dp[i].second;
                }
            }
            maxl = max(maxl, dp[i - 1].first);
        }
        int ans = 0;
        //迭代累加最大长度的个数
        for (auto &[ml, mn] : dp)
            if (maxl == ml)
                ans += mn;

        return ans;
    }
};

// @lc code=end
int main(int argc, char const *argv[])
{
    // vector<int> nums{1,3,5,4,7};
    // vector<int> nums{2,2,2,2,2};
    // vector<int> nums{-74,-38,-96,36,48,100,-22,82,-42,38};
    vector<int> nums{1, 1, 1, 2, 2, 2, 3, 3, 3};
    Solution s;
    cout << s.findNumberOfLIS(nums) << endl;
    return 0;
}
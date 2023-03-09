/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int nmax=nums[0], nmin=nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++){
            if (nums[i] < 0)
                swap(nmax, nmin);
            nmax = max(nmax*nums[i], nums[i]);
            nmin = min(nmin*nums[i], nums[i]);
            ans = max(ans, max(nmax, nmin));
        }

        return ans;
    }
};
// @lc code=end

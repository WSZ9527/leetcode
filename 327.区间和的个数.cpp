/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        n = nums.size();
        this->lower = lower;
        this->upper = upper;
        dfs(nums, 0);
        return ans;
    }

    int dfs(vector<int> &nums, int index) {
        if (valid(nums[index]))
            ++ans;
        
    }

    bool valid(int num){
        return num >= lower && num <= upper;
    }
private:
    int lower, upper;
    int n;
    int ans = 0;
};
// @lc code=end

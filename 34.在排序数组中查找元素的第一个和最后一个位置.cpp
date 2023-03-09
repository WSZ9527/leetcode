/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int mid, left = 0, right = nums.size();
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        ans.push_back(right);
        left = -1, right = nums.size() - 1;
        while (left < right)
        {
            mid = left + (right - left) / 2 + 1;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }

        ans.push_back(left);
        if (ans[0] > ans[1])
            return {-1,-1};
        return ans;
    }
};
// @lc code=end

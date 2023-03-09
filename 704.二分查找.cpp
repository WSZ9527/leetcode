/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int mid, left = -1, right = nums.size() - 1;
        while (left < right)
        {
            mid = left + (right - left) / 2 + 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid;
            else
                right = mid - 1;
        }
        return -1;
    }
};
// @lc code=end

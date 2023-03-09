/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int leftMid = left + (right - left) / 2;
            int rightMid = leftMid + 1;
            if (nums[leftMid] < nums[rightMid])
                left = leftMid + 1;
            else
                right = rightMid - 1;
        }

        return left;
    }
};
// @lc code=end

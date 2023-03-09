/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int left = 0, right = 0, mid;
        for (auto &num : nums)
        {
            right += num;
            left = max(left, num);
        }

        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (valid(nums, mid, m))
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }

    bool valid(vector<int> &nums, int val, int m)
    {
        int group = 1, total = 0;
        for (auto &num : nums)
        {
            if (total + num <= val)
                total += num;
            else
            {
                ++group;
                total = num;
            }
        }

        // cout << "val " << val
        //  << " m " << m
        //  << " group " << group << endl;

        return group <= m;
    }
};
// @lc code=end

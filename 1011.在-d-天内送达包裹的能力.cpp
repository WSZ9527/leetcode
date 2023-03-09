/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = INT_MIN, right = 0, mid;
        for (auto &weight : weights)
        {
            left = max(left, weight);
            right += weight;
        }

        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (valid(weights, days, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }

    bool valid(vector<int> &weights, int days, int maxWeight)
    {
        // cout << "maxWeight " << maxWeight << endl;
        int td = 1, tw = 0;
        for (auto weight : weights)
        {
            if (tw + weight <= maxWeight)
                tw += weight;
            else
            {
                ++td;
                tw = weight;
            }
        }
        // cout << "days " << td << endl;
        return td <= days;
    }
};
// @lc code=end

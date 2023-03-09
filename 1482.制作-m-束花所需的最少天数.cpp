/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int left = 1, right = 1000000001, mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (valid(bloomDay, m, k, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return right == 1000000001 ? -1 : right;
    }

    bool valid(vector<int> &bloomDay, int m, int k, int maxDay)
    {
        int tm=0, tk=0;
        for(auto day : bloomDay){
            if (day <= maxDay)
                ++tk;
            else
                tk = 0;
            if (tk == k){
                tk = 0;
                ++tm;
            }
        }
        return tm >= m;
    }
};
// @lc code=end

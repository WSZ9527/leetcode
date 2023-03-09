/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long long mid, left = 0, right = x;
        while (left < right)
        {
            mid = (left + right + 1) / 2;
            if (mid * mid <= x)
                left = mid;
            else
                right = mid - 1;
        }

        return left;
    }
};
// @lc code=end

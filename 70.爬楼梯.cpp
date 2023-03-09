/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int n1 = 1, n2 = 2;
        for(int i = 3; i < n; i++){
            n2 += n1;
            n1 = n2 - n1;
        }

        return n1 + n2;
    }

    int dfs(int n)
    {
        if (n <= 2)
            return n;
        if (mem.find(n) != mem.end())
            return mem[n];

        return (mem[n] = climbStairs(n - 1) + climbStairs(n - 2));
    }
    unordered_map<int, int> mem;
};
// @lc code=end

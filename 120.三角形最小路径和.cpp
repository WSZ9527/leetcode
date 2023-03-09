/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct HashFunc
{
    template <typename T, typename U>
    size_t operator()(const std::pair<T, U> &p) const
    {
        return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
    }
};

// 键值比较，哈希碰撞的比较定义，需要直到两个自定义对象是否相等
struct EqualKey
{
    template <typename T, typename U>
    bool operator()(const std::pair<T, U> &p1, const std::pair<T, U> &p2) const
    {
        return p1.first == p2.first && p1.second == p2.second;
    }
};

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        level = triangle.size();
        // return dfs(triangle, 0, 0);
        for (int l = level - 1; l > 0; --l)
            for (int i = 0; i < triangle[l].size() - 1; ++i)
                triangle[l - 1][i] += min(triangle[l][i], triangle[l][i + 1]);
        return triangle[0][0];
    }

    int dfs(vector<vector<int>> &triangle, int i, int j)
    {
        if (i + 1 == level)
            return triangle[i][j];
        auto pos = make_pair(i, j);
        if (mem.find(pos) != mem.end())
            return mem[pos];

        return (mem[pos] = triangle[i][j] + min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)));
    }

    int level;
    unordered_map<pair<int, int>, int, HashFunc, EqualKey> mem;
};
// @lc code=end

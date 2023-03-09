/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        mem = vector<vector<long>>(n, vector<long>(m, 0));
        if (obstacleGrid[n - 1][m - 1])
            return 0;
        mem[n - 1][m - 1] = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (j > 0 && obstacleGrid[i][j - 1] == 0)
                    mem[i][j - 1] += mem[i][j];
                if (i > 0 && obstacleGrid[i - 1][j] == 0)
                    mem[i - 1][j] += mem[i][j];
            }
        }

        return mem[0][0];
    }

    //递归
    int uniquePathsWithObstacles1(vector<vector<int>> &obstacleGrid)
    {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        mem = vector<vector<long>>(n, vector<long>(m, -1));
        return dfs(obstacleGrid, 0, 0);
    }

    int dfs(vector<vector<int>> &obstacleGrid, int x, int y)
    {
        if (x >= n || y >= m || obstacleGrid[x][y] == 1)
            return 0;
        if (x + 1 == n && y + 1 == m)
            return 1;
        if (mem[x][y] != -1)
            return mem[x][y];

        return (mem[x][y] = dfs(obstacleGrid, x + 1, y) + dfs(obstacleGrid, x, y + 1));
    }

    int n, m;
    vector<vector<long>> mem;
};
// @lc code=end

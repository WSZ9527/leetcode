/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        hashStep = vector<vector<int>>(m, vector<int>(n, -1));
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                ans = max(ans, dfs(matrix, x, y));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>> &matrix, int x, int y)
    {
        if (hashStep[x][y] != -1)
            return hashStep[x][y];
        hashStep[x][y] = 1;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if (matrix[nx][ny] > matrix[x][y])
            {
                hashStep[x][y] = max(hashStep[x][y], dfs(matrix, nx, ny) + 1);
            }
        }

        return hashStep[x][y];
    }

private:
    int m;
    int n;
    int ans = INT_MIN;
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
    vector<vector<int>> hashStep;
};
// @lc code=end
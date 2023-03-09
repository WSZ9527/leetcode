/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= m; j++)
            {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

private:
    vector<vector<int>> dp;
};
// class Solution
// {
// public:
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         hashAns = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
//         return dfs(text1, text2, 0, 0);
//     }

//     int dfs(string& text1, string& text2, int i, int j)
//     {
//         if (text1.size() == i || text2.size() == j)
//             return 0;
//         if (hashAns[i][j] != -1)
//             return hashAns[i][j];
//         int ans;
//         if (text1[i] == text2[j])
//             ans = dfs(text1, text2, i + 1, j + 1) + 1;
//         else
//             ans = max(dfs(text1, text2, i + 1, j), dfs(text1, text2, i, j + 1));
//         hashAns[i][j] = ans;
//         return ans;
//     }

// private:
//     vector<vector<int>> hashAns;
// };
// @lc code=end

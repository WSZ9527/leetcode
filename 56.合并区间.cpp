/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& lhs, vector<int>& rhs){
            return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
        });

        vector<vector<int>> ans;
        int left = intervals[0][0],right = intervals[0][1];
        for(size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= right) 
                right = max(right, intervals[i][1]);
            else{
                ans.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }

        ans.push_back({left, right});
        return ans;
    }
};
// @lc code=end


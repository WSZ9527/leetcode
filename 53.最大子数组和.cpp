/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        n = nums.size();
        for(int i=0; i<n; i++) {
            ans = max(ans, dfs(nums, i));
        }

        return ans;
    }

    int dfs(vector<int>& nums, int index) {
        int cans = nums[index];
        for(int i = index + 1; i< n;++i){
            
        }
    }

    int n;
    int ans = INT_MIN;
};
// @lc code=end


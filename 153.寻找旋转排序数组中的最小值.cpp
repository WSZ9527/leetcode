/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int mid,left = 0, right = nums.size() - 1;
        while(left < right){
            mid = left + (right - left) / 2;
            //3,4,5 | 1,2
            if (nums[mid] <= nums[right])
                right = mid;
            else    
                left = mid + 1;
        }
        return nums[right];
        // return dfs(nums, 0, nums.size() - 1);
    }
    //4,5,6,7 | 0,1,2
    int dfs(vector<int> &nums, int left, int right)
    {
        if (left +1 == right)
            return min(nums[left], nums[right]);
        if (nums[left] < nums[right])
            return nums[left];
        int mid = (left + right) / 2;
        return min(dfs(nums, left, mid), dfs(nums, mid, right));
    }
};
// @lc code=end

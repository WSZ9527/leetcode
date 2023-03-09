/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSort(nums, nums.size() - k, 0, nums.size() - 1);
    }

    int quickSort(vector<int> &nums, int k, int start, int end)
    {
        if (start == end)
            return nums[start];
        auto pivot = partition(nums, start, end);
        if (pivot >= k)
            return quickSort(nums, k, start, pivot);
        else
            return quickSort(nums, k, pivot + 1, end);
    }

    int partition(vector<int> &nums, int start, int end)
    {
        int pivot = start + rand() % (end - start + 1);
        int pivotVal = nums[pivot];
        while (start <= end)
        {
            while (nums[start] < pivotVal)
                ++start;
            while (nums[end] > pivotVal)
                --end;
            if (start <= end)
            {
                swap(nums[start], nums[end]);
                ++start;
                --end;
            }
        }
        return end;
    }
};
// @lc code=end

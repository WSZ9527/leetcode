/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <bits/stdc++.h>
using namespace std;
struct Lt
{
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.first < rhs.first;
    }
};

bool compare(const pair<int, int> &lhs, const pair<int, int>& rhs){
     return lhs.first < rhs.first;
}
// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        priority_queue<pair<int, int>> q;
        int n = nums.size();
        for(int i = 0;  i < k - 1; ++i)
            q.push({nums[i], i});
        for (int i = k - 1; i < n; ++i)
        {
            q.push({nums[i], i});
            while(q.top().second <= i - k)
                q.pop();
            result.push_back(q.top().first);
        }

        return move(result);
    }
};
// @lc code=end

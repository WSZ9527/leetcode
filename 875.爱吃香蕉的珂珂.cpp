/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT_MIN,mid;
        for(auto pile:piles)
            right = max(right, pile);

        while(left < right){
            mid = left + (right - left) / 2;
            if (valid(piles, h, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }

    bool valid(vector<int>& piles, int h, int k){
        int th = 0;
        for(auto pile:piles){
            if (pile <= k)
                ++th;
            else
                th += pile / k + (pile % k?1:0);
        }
        
        return th <= h;
    }
};
// @lc code=end


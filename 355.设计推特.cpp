/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start

struct Tweet
{
    Tweet(int userId, int tweetId, int t)
        : userId(userId), tweetId(tweetId), t(t)
    {
    }
    int userId;
    int tweetId;
    int t;
};

bool operator<(const Tweet &a, const Tweet &b)
{
    return a.t < b.t;
}

class Twitter
{
    int t = 0;

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        userTweetMap[userId].push_front({userId, tweetId, ++t});
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<Tweet> q;
        auto &posts = userTweetMap[userId];
        for (auto &post : posts)
            q.push(post);
        auto &follows = followMap[userId];
        for (auto &followId : follows)
            for (auto &post : userTweetMap[followId])
                q.push(post);

        vector<int> result;
        // cout << q.size() << endl;
        while (!q.empty() && result.size() < 10)
        {
            auto tweetId = q.top().tweetId;
            q.pop();
            result.push_back(tweetId);
        }
        return move(result);
    }

    void follow(int followerId, int followeeId)
    {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followMap[followerId].erase(followeeId);
    }

    unordered_map<int, deque<Tweet>> userTweetMap;
    unordered_map<int, unordered_set<int>> followMap;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

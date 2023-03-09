/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

template <typename T>
struct Lt
{

    bool operator()(const T *lhs, const T *rhs)
    {
        return operator()(*lhs, *rhs);
    }

    bool operator()(const T &lhs, const T &rhs)
    {
        return lhs->val > rhs->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Lt<ListNode *>> q;
        for (auto &list : lists)
        {
            auto header = list;
            while (header)
            {
                q.push(new ListNode(header->val));
                header = header->next;
            }
        }

        auto list = new ListNode;
        auto header = list;
        while (!q.empty())
        {
            header->next = q.top();
            header = header->next;
            q.pop();
        }

        return list->next;
    }
    // ListNode *mergeKLists(vector<ListNode *> &lists)
    // {
    //     auto n = lists.size();
    //     if (!n)
    //         return nullptr;
    //     return mergeKLists(lists, 0, n);
    // }

    // ListNode *mergeKLists(vector<ListNode *> &lists, size_t start, size_t end)
    // {
    //     if (!start && !end)
    //         return nullptr;
    //     if (start + 1 == end)
    //         return lists[start];
    //     auto mid = start + (end - start) / 2;
    //     auto llist = mergeKLists(lists, start, mid);
    //     auto rlist = mergeKLists(lists, mid, end);
    //     return mergeKLists(llist, rlist);
    // }

    // ListNode *mergeKLists(ListNode *a, ListNode *b)
    // {
    //     auto list = new ListNode;
    //     auto header = list;
    //     while (a || b)
    //     {
    //         if (a && b)
    //         {
    //             if (a->val < b->val)
    //                 appendNode(header, a);
    //             else
    //                 appendNode(header, b);
    //         }
    //         else if (a)
    //             appendNode(header, a);
    //         else
    //             appendNode(header, b);
    //     }
    //     return list->next;
    // }
    // void appendNode(ListNode *(&header), ListNode *(&node))
    // {
    //     header->next = node;
    //     header = header->next;
    //     node = node->next;
    // }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        //找到要删除的节点
        if (root->val == key)
        {
            //有右子树
            if (root->right)
            {
                //探索其后继节点
                auto header = root->right;
                while (header->left)
                    header = header->left;
                //找到后继节点，值相互交换，递归删除后继节点
                swap(header->val, root->val);
                root->right = deleteNode(root->right, key);
            }
            else if (root->left)
            { //只有左子树，直接换
                auto r = root->left;
                delete root;
                return r;
            }
            else
            { //孤儿，直接干掉
                delete root;
                return nullptr;
            }
        }

        //要找的值在左子树
        if (root->val > key)
            //左子树为空，那么当前节点为根节点的后继节点
            if (!root->left)
                return root;
            else
                root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include <bits/stdc++.h>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
   public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recurseTree(root, p, q);
        return ans;
    }

    bool recurseTree(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        int left = recurseTree(root->left, p, q) ? 1 : 0;
        int right = recurseTree(root->right, p, q);
        int mid = (root == q || root == p) ? 1 : 0;
        if (mid + left + right >= 2) ans = root;
        return mid + left + right > 0;
    }
};
// @lc code=end

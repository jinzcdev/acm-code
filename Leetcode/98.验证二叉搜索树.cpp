/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (28.32%)
 * Likes:    396
 * Dislikes: 0
 * Total Accepted:    65K
 * Total Submissions: 226.2K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 *
 * 假设一个二叉搜索树具有如下特征：
 *
 *
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 * 示例 1:
 *
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
class Solution {
   public:
    bool solve(TreeNode* root, long low, long high) {
        if (root == NULL) return true;
        if (root->val <= low || root->val >= high) return false;
        return solve(root->left, low, root->val) &&
               solve(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) { return solve(root, LONG_MIN, LONG_MAX); }
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        long preValue = LONG_MIN;
        while (!s.empty() || p != NULL) {
            for (; p != NULL; p = p->left) s.push(p);
            p = s.top();
            s.pop();
            if (p->val <= preValue) return false;
            preValue = p->val;
            p = p->right;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        TreeNode* p = root->left;
        if (p) {
            while (p->right) p = p->right;
            if (root->val <= p->val) return false;
        }
        p = root->right;
        if (p) {
            while (p->left) p = p->left;
            if (root->val >= p->val) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
// @lc code=end

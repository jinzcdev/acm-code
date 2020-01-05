/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (57.92%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    25K
 * Total Submissions: 43.1K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 *
 *
 * 返回:
 *
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 *
 *
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
class Solution {
   public:
    vector<vector<int>> ans;
    vector<TreeNode *> path;
    void solve(TreeNode *root, int sum) {
        if (root == NULL) return;
        path.push_back(root);
        if (!root->left && !root->right) {
            vector<int> temp;
            int tempSum = 0;
            for (auto it : path) {
                temp.push_back(it->val);
                tempSum += it->val;
            }
            if (tempSum == sum) ans.push_back(temp);
            path.pop_back();
            return;
        }
        solve(root->left, sum);
        solve(root->right, sum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        solve(root, sum);
        return ans;
    }
};
// @lc code=end
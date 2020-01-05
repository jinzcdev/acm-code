/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (61.39%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    21.3K
 * Total Submissions: 34.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例:
 *
 * 输入:
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 * 输出: ["1->2->5", "1->3"]
 *
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<TreeNode *> path;
    vector<string> ans;
    void traverse(TreeNode *root) {
        if (root == NULL) return;
        path.push_back(root);
        if (root->left == NULL && root->right == NULL) {
            string s;
            for (int i = 0; i < path.size(); i++) {
                if (i != 0) s += "->";
                s += to_string(path[i]->val);
            }
            ans.push_back(s);
            path.pop_back();
            return;
        }
        traverse(root->left);
        traverse(root->right);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        traverse(root);
        return ans;
    }
};
// @lc code=end

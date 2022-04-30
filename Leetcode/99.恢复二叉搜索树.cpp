/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Medium (60.63%)
 * Likes:    687
 * Dislikes: 0
 * Total Accepted:    93.4K
 * Total Submissions: 154.1K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,3,null,null,2]
 * 输出：[3,1,null,null,2]
 * 解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,1,4,null,null,2]
 * 输出：[2,1,4,null,null,3]
 * 解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树上节点的数目在范围 [2, 1000] 内
 * -2^31 <= Node.val <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用 O(1) 空间的解决方案吗？
 * 
 */

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
class Solution {
public:

    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                if (!prev) {
                    prev = cur;
                } else {
                    if (prev->val > cur->val) {
                        if (!first) {
                            first = prev;
                        }
                        second = cur;
                    }
                    prev = cur;
                }
                cur = cur->right;
            } else {
                TreeNode* tmp = cur->left;
                while (tmp->right && tmp->right != cur) {
                    tmp = tmp->right;
                }
                if (!tmp->right) {
                    tmp->right = cur;
                    cur = cur->left;
                } else {
                    tmp->right = nullptr;
                    if (!prev) {
                        prev = cur;
                    } else {
                        if (prev->val > cur->val) {
                            if (!first) {
                                first = prev;
                            }
                            second = cur;
                        }
                        prev = cur;
                    }
                    cur = cur->right;
                }
            }
        }
        if (first && second) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
};
// @lc code=end


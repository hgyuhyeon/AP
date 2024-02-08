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
    bool dfs(TreeNode* node, int p, int t) {
        if (!node) return false;
        if (!node->left && !node->right) return p + node->val == t;
        return dfs(node->left, p+node->val, t) || dfs(node->right, p+node->val, t);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, 0, targetSum);
    }
};
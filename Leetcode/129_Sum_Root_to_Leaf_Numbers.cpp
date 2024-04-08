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
    void helper(TreeNode* node, int& ans, int sum) {
        if (!node) return;
        sum = sum * 10 + node->val;
        helper(node->left, ans, sum);
        helper(node->right, ans, sum);
        if (!node->left && !node->right) ans += sum;
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, ans, 0);
        return ans;
    }
};
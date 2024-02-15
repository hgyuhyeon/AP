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
    int prev = INT_MIN;
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* node) {
        if (node->left) getMinimumDifference(node->left);
        if (prev != INT_MIN && node->val - prev < ans) ans = node->val - prev;
        prev = node->val;
        if (node->right) getMinimumDifference(node->right);
        return ans;
    }
};
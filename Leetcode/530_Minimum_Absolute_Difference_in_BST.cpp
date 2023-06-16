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

    void search(TreeNode* node) {
        if (node->left) search(node->left);
        
        if (prev == INT_MIN || node->val - prev >= ans) prev = node->val;
        else {
            ans = node->val - prev;
            prev = node->val;
        }

        if (node->right) search(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        search(root);
        return ans;
    }
};
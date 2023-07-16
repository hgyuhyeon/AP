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
    int ans = INT_MAX;
    void dfs(TreeNode* node, int d) {
        if (node->left == NULL && node->right == NULL && d < ans) ans = d;
        if (node->left != NULL) dfs(node->left, d+1);
        if (node->right != NULL) dfs(node->right, d+1);
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        dfs(root, 1);
        return ans;
    }
};
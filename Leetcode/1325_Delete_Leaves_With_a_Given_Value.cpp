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
    void dfs(TreeNode* node, int& target) {
        if (node->left != NULL) {
            dfs(node->left, target);
            if (!node->left->val) node->left = NULL;
        }
        if (node->right != NULL) {
            dfs(node->right, target);
            if (!node->right->val) node->right = NULL;
        }
        if (!node->left && !node->right && node->val == target) node->val = 0;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root, target);
        if (root->val == 0) return NULL;
        return root;
    }
};
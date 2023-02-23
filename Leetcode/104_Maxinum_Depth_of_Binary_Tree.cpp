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
    int depth = 0;
    void calDepth(TreeNode* node, int d) {
        if (node->left != NULL) calDepth(node->left, d+1);
        if (node->right != NULL) calDepth(node->right, d+1);
        if (depth < d) depth = d;
    }

    int maxDepth(TreeNode* root) {
        if (root != NULL) calDepth(root, 1);
        return depth;
    }
};
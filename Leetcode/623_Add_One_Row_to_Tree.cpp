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
    void dfs(TreeNode* node, int val, int depth, int d) {
        if (!node) return;
        if (d == depth) {
            TreeNode* l = node->left, *r = node->right;
            node->left = new TreeNode(val, l, NULL);
            node->right = new TreeNode(val, NULL, r);
        }
        else {
            dfs(node->left, val, depth, d+1);
            dfs(node->right, val, depth, d+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, NULL);
        dfs(root, val, depth-1, 1);
        return root;
    }
};
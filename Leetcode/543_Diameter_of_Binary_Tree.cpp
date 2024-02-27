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
    int search(TreeNode* node, int& d) {
        if (!node) return 0;
        int left = search(node->left, d);
        int right = search(node->right, d);
        d = max(d, left + right);
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int d = 0;
        search(root, d);
        return d;
    }
};
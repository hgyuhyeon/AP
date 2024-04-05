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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int lo, int hi) {
        if (lo > hi) return NULL;
        TreeNode* node = new TreeNode(preorder[idx++]);
        int i = 0;
        while (inorder[i] != node->val) i++;
        node->left = build(preorder, inorder, idx, lo, i-1);
        node->right = build(preorder, inorder, idx, i+1, hi);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder, inorder, idx, 0, inorder.size()-1);
    }
};
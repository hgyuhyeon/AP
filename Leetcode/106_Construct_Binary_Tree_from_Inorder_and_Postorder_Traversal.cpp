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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& idx, int lo, int hi) {
        if (lo > hi) return NULL;
        TreeNode* node = new TreeNode(postorder[idx--]);
        int i = inorder.size()-1;
        while (inorder[i] != node->val) i--;
        node->right = build(inorder, postorder, idx, i+1, hi);
        node->left = build(inorder, postorder, idx, lo, i-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        return build(inorder, postorder, idx, 0, idx);
    }
};
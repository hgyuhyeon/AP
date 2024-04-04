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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preidx, int inlo, int inhi) {
        if (preidx >= preorder.size() || inlo > inhi) return NULL;
        TreeNode* node = new TreeNode(preorder[preidx++]);
        int i = -1;
        for (i = 0; i < inorder.size(); i++) if (inorder[i] == node->val) break;
        if (i >= inorder.size()) i = -1;
        node->left = build(preorder, inorder, preidx, inlo, i-1);
        node->right = build(preorder, inorder, preidx, i+1, inhi);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0, inlo = 0, inhi = inorder.size()-1;
        return build(preorder, inorder, preidx, inlo, inhi);
    }
};
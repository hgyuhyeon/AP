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
    bool dfs(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        else if (left != nullptr && right != nullptr) {
            if (left->val != right->val) return false;
            bool ret1 = dfs(left->left, right->right);
            bool ret2 = dfs(left->right, right->left);
            if (ret1 && ret2) return true;
            else return false;
        }
        else return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root->left && root->right) return dfs(root->left, root->right);
        else if (!root->left && !root->right) return true;
        else return false;
    }
};
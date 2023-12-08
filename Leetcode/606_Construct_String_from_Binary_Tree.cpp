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
    string preorder(TreeNode* node, string& ans) {
        if (!node) return ans;
        ans += to_string(node->val);
        if (node->left) {
            ans += "(";
            preorder(node->left, ans);
            ans += ")";
        }
        if (node->right) {
            if (!node->left) ans += "()";
            ans += "(";
            preorder(node->right, ans);
            ans += ")";
        }
        return ans;
    }
    string tree2str(TreeNode* root) {
        string ans = "";
        return preorder(root, ans);
    }
};
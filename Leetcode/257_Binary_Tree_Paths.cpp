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
    void search(TreeNode* node, string str, vector<string>& ans) {
        str += "->" + to_string(node->val);
        if (!node->left && !node->right) ans.push_back(str);
        else {
            if (node->left) search(node->left, str, ans);
            if (node->right) search(node->right, str, ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root->left && !root->right) return vector<string>(1, to_string(root->val));
        if (root->left) search(root->left, to_string(root->val), ans);
        if (root->right) search(root->right, to_string(root->val), ans);
        return ans;
    }
};
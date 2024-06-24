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
    void dfs(TreeNode* node, TreeNode* max_n, int& ans) {
        if (node->val >= max_n->val) {
            ans++;
            max_n = node;
        }
        if (node->left) dfs(node->left, max_n, ans);
        if (node->right) dfs(node->right, max_n, ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, root, ans);
        return ans;
    }
};
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
    void dfs(TreeNode* node, int cur, int& d, int& ans) {
        if (!node->left && !node->right) {
            if (cur > d) {
                d = cur;
                ans = node->val;
            }
        }
        if (node->left != NULL) dfs(node->left, cur+1, d, ans);
        if (node->right != NULL) dfs(node->right, cur+1, d, ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val, d = 0;
        dfs(root, 0, d, ans);
        return ans;
    }
};
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
    int ans = 0;
    void dfs(TreeNode* node, int minv, int maxv) {
        minv = min(minv, node->val);
        maxv = max(maxv, node->val);
        ans = max(ans, maxv - minv);
        if (node->left != NULL) dfs(node->left, minv, maxv);
        if (node->right != NULL) dfs(node->right, minv, maxv);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};
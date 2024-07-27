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
    vector<vector<int>> ans;
    void dfs(TreeNode* node,vector<int>& p, int sum, int& tg) {
        p.push_back(node->val);
        if (!node->left && !node->right) {
            if (sum + node->val == tg) ans.push_back(p);
            p.pop_back();
            return;
        }
        if (node->left) dfs(node->left, p, sum + node->val, tg);
        if (node->right) dfs(node->right, p, sum + node->val, tg);
        p.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return ans;
        vector<int> path;
        dfs(root, path, 0, targetSum);
        return ans;
    }
};

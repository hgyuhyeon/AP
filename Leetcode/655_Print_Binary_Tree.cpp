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
    void maxDepth(TreeNode* node, int d, int& h) {
        if (!node) return;
        h = max(d, h);
        maxDepth(node->left, d+1, h);
        maxDepth(node->right, d+1, h);
    }
    void print(vector<vector<string>>& ans, TreeNode* node, int d, int lo, int hi) {
        if (lo > hi) return;
        int mid = (lo + hi) / 2;
        ans[d][mid] = to_string(node->val);
        if (node->left) print(ans, node->left, d+1, lo, mid-1);
        if (node->right) print(ans, node->right, d+1, mid+1, hi);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = 0;
        maxDepth(root, 1, h);
        int w = (1 << h) - 1;
        vector<vector<string>> ans(h, vector<string>(w, ""));
        print(ans, root, 0, 0, w-1);
        return ans;
    }
};
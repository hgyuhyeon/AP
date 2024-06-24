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
    pair<int, int> calc(TreeNode* node, int& ans) {
        int lsum = 0, rsum = 0, div = 1;
        if (node->left) {
            pair<int, int> p = calc(node->left, ans);
            lsum = p.first;
            div += p.second;
        }
        if (node->right) {
            pair<int, int> p = calc(node->right, ans);
            rsum = p.first;
            div += p.second;
        }
        if ((lsum + rsum + node->val) / div == node->val) ans++;
        return {lsum + rsum + node->val, div};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        calc(root, ans);
        return ans;
    }
};
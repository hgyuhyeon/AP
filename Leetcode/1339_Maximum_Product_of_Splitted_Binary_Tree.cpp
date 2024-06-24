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
    int mod = 1e9 + 7;
    int calc(TreeNode* node, long long sum, long long& ans) {
        long long lsum = 0, rsum = 0;
        if (node->left) lsum = calc(node->left, sum, ans);
        if (node->right) rsum = calc(node->right, sum, ans);
        long long sub = lsum + rsum + node->val;
        ans = max(ans, sub * (sum - sub));
        return sub;
    }
    int maxProduct(TreeNode* root) {
        long long sum = 0, ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            sum += q.front()->val;
            if (q.front()->left) q.push(q.front()->left);
            if (q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        calc(root, sum, ans);
        return ans % mod;
    }
};
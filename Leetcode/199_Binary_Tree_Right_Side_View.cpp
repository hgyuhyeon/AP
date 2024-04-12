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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if (p.first->left != NULL) q.push({p.first->left, p.second+1});
            if (p.first->right != NULL) q.push({p.first->right, p.second+1});
            if (q.empty() || q.front().second > p.second) ans.push_back(p.first->val);
        }
        return ans;
    }
};
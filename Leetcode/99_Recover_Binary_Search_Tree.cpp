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
    void search(TreeNode* node, vector<TreeNode*>& v) {
        if (node->left) search(node->left, v);
        v.push_back(node);
        if (node->right) search(node->right, v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        search(root, v);
        int n = v.size();
        vector<pair<TreeNode*, TreeNode*>> pv;
        for (int i = 1; i < n; i++) {
            if (v[i]->val < v[i-1]->val) pv.push_back({v[i-1], v[i]});
        }
        if (pv.size() == 1) swap(pv[0].first->val, pv[0].second->val);
        else if (pv.size() == 2) swap(pv[0].first->val, pv[1].second->val);
    }
};

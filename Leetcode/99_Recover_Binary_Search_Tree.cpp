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
    vector<pair<TreeNode*, TreeNode*>> pv;
    TreeNode* prev = NULL;
    void search(TreeNode* node) {
        if (node->left) search(node->left);
        if (prev && prev->val > node->val) pv.push_back({prev, node});
        prev = node;
        if (node->right) search(node->right);
    }
    void recoverTree(TreeNode* root) {
        search(root);
        if (pv.size() == 1) swap(pv[0].first->val, pv[0].second->val);
        else if (pv.size() == 2) swap(pv[0].first->val, pv[1].second->val);
    }
};

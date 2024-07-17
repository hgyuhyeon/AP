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
    void del(TreeNode* node, map<int, TreeNode*>& m, map<int, int>& d) {
        if (node->left) {
            del(node->left, m, d);
            if (d[node->left->val]) node->left = NULL;
        }
        if (node->right) {
            del(node->right, m, d);
            if (d[node->right->val]) node->right = NULL;
        }
        if (!d[node->val]) m[node->val] = node;
    }
    void search(TreeNode* node, map<int, int>& v) {
        if (node->left && !v[node->left->val]) {
            v[node->left->val]++;
            search(node->left, v);
        }
        if (node->right && !v[node->right->val]) {
            v[node->right->val]++;
            search(node->right, v);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) return vector<TreeNode*>();
        map<int, TreeNode*> m;
        map<int, int> d;
        for (auto val: to_delete) d[val]++;
        del(root, m, d);

        vector<TreeNode*> ans;
        for (auto [i, val]: m) {
            if (!d[i]) {
                ans.push_back(val);
                d[i]++;
                search(val, d);
            }
        }
        return ans;
    }
};

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
    map<string, int> trees;
    vector<TreeNode*> ans;
    string serializer(TreeNode* node) {
        if (!node) return "*";
        string left = serializer(node->left);
        string right = serializer(node->right);
        string s = left + "," + right + "," + to_string(node->val);
        if (trees[s] == 1) ans.push_back(node);
        trees[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serializer(root);
        return ans;
    }
};
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
    set<string> s;
    void dfs(TreeNode* node, string tmp) {
        if (!node->left && !node->right) s.insert((char)(node->val+97) + tmp);
        else {
            if (node->left != NULL) dfs(node->left, (char)(node->val+97) + tmp);
            if (node->right != NULL) dfs(node->right, (char)(node->val+97) + tmp);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return *s.begin();
    }
};
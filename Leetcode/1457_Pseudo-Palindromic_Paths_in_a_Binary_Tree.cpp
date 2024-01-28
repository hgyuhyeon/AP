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
    int ans = 0;
    void dfs (TreeNode* node, vector<int> v, int cnt) {
        if (!v[node->val]) {
            v[node->val]++;
            cnt++;
        }
        else {
            v[node->val]--;
            cnt--;
        }

        if (!node->left && !node->right && cnt < 2) ++ans;
        
        if (node->left != NULL) dfs(node->left, v, cnt);
        if (node->right != NULL) dfs(node->right, v, cnt);

        if (!v[node->val]) {
            v[node->val]++;
            cnt++;
        }
        else {
            v[node->val]--;
            cnt--;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10, 0);
        dfs(root, v, 0);
        return ans;
    }
};
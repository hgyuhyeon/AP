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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int cur = 0, prev = -1;
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int d = q.front().second;
            if ((d % 2 == 0 && node->val % 2 == 1) || (d % 2 == 1 && node->val % 2 == 0)) {
                if (node->left != NULL) q.push({node->left, d+1});
                if (node->right != NULL) q.push({node->right, d+1});
                if (d != cur) {
                    cur = d;
                    prev = node->val;
                }
                else {
                    if (d % 2 == 0) {
                        if (node->val <= prev) return false;
                        else prev = node->val;
                    }
                    else {
                        if (node->val >= prev) return false;
                        else prev = node->val;
                    }
                }
                q.pop();
            }
            else return false;
        }
        return true;
    }
};
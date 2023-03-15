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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* ptr;
        q.push(root);
        while (!q.empty()) {
            ptr = q.front();
            q.pop();
            if (!ptr) {
                while (!q.empty()) {
                    if (q.front() == nullptr) q.pop();
                    else return false; 
                }
                return true;
            }
            q.push(ptr->left);
            q.push(ptr->right);
        }
        return true;
    }
};
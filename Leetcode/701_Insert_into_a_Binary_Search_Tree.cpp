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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* ptr = root;
        while (ptr->left || ptr->right) {
            if (ptr->val > val) {
                if (ptr->left) ptr = ptr->left;
                else break;
            }
            else if (ptr->val < val) {
                if (ptr->right) ptr = ptr->right;
                else break;
            }
        }
        if (ptr->val > val) ptr->left = new TreeNode(val);
        else ptr->right = new TreeNode(val);
        return root;
    }
};
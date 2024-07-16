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
private:
    TreeNode* head = new TreeNode(-1);
    TreeNode* ptr = head;
public:
    void inorder(TreeNode* node) {
        if (node->left) inorder(node->left);
        ptr->right = new TreeNode(node->val);
        ptr = ptr->right;
        if (node->right) inorder(node->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return head->right;
    }
};

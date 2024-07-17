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
    TreeNode* trimBST(TreeNode* root, int& low, int& high) {
        if (!root->left && !root->right) {
            if (root->val >= low && root->val <= high) return root;
            else return NULL;
        }
        if (root->val > high) return trimBST(root->left, low, high);
        else if (root->val < low) return trimBST(root->right, low, high);
        TreeNode* ptr = root, *ptr2;
        while (ptr != NULL) {
            if (ptr->left && ptr->left->val < low) {
                ptr2 = ptr->left; 
                while (ptr2 && ptr2->val < low) ptr2 = ptr2->right;
                if (ptr2 && ptr2->val >= low) ptr->left = ptr2;
                else ptr->left = NULL;
            }
            ptr = ptr->left;
        }
        ptr = root;
        while (ptr != NULL) {
            if (ptr->right && ptr->right->val > high) {
                ptr2 = ptr->right;
                while (ptr2 && ptr2->val > high) ptr2 = ptr2->left;
                if (ptr2 && ptr2->val <= high) ptr->right = ptr2;
                else ptr->right = NULL;
            }
            ptr = ptr->right;
        }
        return root;
    }
};

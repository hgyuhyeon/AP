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
    int getSum(TreeNode* node, int num, int& sum) {
        num = num*10 + node->val;
        if (!node->left && !node->right) sum += num;
        if (node->left) getSum(node->left, num, sum);
        if (node->right) getSum(node->right, num, sum);
        return sum;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return getSum(root, 0, sum);
    }
};
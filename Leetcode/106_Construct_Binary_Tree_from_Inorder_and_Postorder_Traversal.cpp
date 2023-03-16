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
    TreeNode* gen(vector<int>& in, vector<int>& post, int& idx, int left, int right) {
        if (left > right) return nullptr;
        int root = right;
        while (post[idx] != in[root]) root--; // find root index in inorder

        TreeNode* node = new TreeNode(post[idx--]);  // --: next root (right side)
        node->right = gen(in, post, idx, root+1, right);
        node->left = gen(in, post, idx, left, root-1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int end = inorder.size() - 1;
        return gen(inorder, postorder, end, 0, end);
    }
};
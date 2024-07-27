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
    TreeNode* gen(vector<int>& nums, int lo, int hi) {
        if (lo >= hi || lo >= nums.size()) return NULL;
        int idx = max_element(nums.begin() + lo, nums.begin() + hi) - nums.begin();
        TreeNode* node = new TreeNode(nums[idx]);
        node->left = gen(nums, lo, idx);
        node->right = gen(nums, idx+1, hi);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return gen(nums, 0, nums.size());
    }
};

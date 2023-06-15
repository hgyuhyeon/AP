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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0, level = 1, max = INT_MIN;
        q.push(root);

        while(!q.empty()) {
            int size = q.size(), sum = 0;

            while (size-- > 0) {
                TreeNode* node = q.front();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }

            if (sum > max) {
                max = sum;
                ans = level;
            }
            level++;
        }

        return ans;
    }
};
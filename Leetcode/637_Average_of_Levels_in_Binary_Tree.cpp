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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        double depth = 0, sum = 0, cnt = 0;
        while (!q.empty()) {
            if (depth == q.front().second) {
                sum += q.front().first->val;
                cnt++;
                if (q.front().first->left != NULL) q.push({q.front().first->left, depth+1});
                if (q.front().first->right != NULL) q.push({q.front().first->right, depth+1});
                q.pop();
            }
            else {
                ans.push_back(sum / cnt);
                sum = 0;
                cnt = 0;
                depth = q.front().second;
            }
        }
        if (cnt) ans.push_back(sum / cnt);
        return ans;
    }
};
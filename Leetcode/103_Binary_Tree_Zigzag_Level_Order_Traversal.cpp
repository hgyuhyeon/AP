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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        bool flag = true;
        if (root == NULL) return res;
        queue<pair<TreeNode*, int>> q;
        int level = 0;
        q.push({root, level});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            if (level < q.front().second) {
                if (!flag) reverse(temp.begin(), temp.end());
                flag = !flag;
                res.push_back(temp);
                temp.clear();
            }
            level = q.front().second;
            q.pop();
            if (node->left != NULL) q.push({node->left, level+1});
            if (node->right != NULL) q.push({node->right, level+1});
            temp.push_back(node->val);
        }

        if (temp.size() > 0) {
            if (!flag) reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
};
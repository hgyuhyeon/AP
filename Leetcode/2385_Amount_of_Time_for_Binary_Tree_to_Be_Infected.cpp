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
    int ans = 0;
    void dfs(int node, map<int, vector<TreeNode*>>& g, map<int, int>& v, int d) {
        ans = max(ans, d);

        for (auto next: g[node]) {
            if (v.find(next->val) == v.end()) {
                v[next->val]++;
                dfs(next->val, g, v, d+1);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        map<int, vector<TreeNode*>> g;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                g[node->val].push_back(node->left);
                g[node->left->val].push_back(node);
                q.push(node->left);
            }
            if (node->right) {
                g[node->val].push_back(node->right);
                g[node->right->val].push_back(node);
                q.push(node->right);
            }
        }
        map<int, int> v;
        v[start]++;
        dfs(start, g, v, 0);
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> ans;
public:
    void dfs(TreeNode* node, unordered_map<TreeNode*, int>& v, int d) {
        if (!node || v[node] == true) return;
        v[node] = true;
        if (d == 0) {
            ans.push_back(node->val);
        }
        else {
            dfs(node->left, v, d-1);
            dfs(node->right, v, d-1);
            dfs(parent[node], v, d-1);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) {
            ans.push_back(target->val);
            return ans;
        }

        queue<TreeNode*> q;
        parent[root] = root;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != NULL) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right != NULL) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        
        unordered_map<TreeNode*, int> v;
        dfs(target, v, k);
        return ans;
    }
};
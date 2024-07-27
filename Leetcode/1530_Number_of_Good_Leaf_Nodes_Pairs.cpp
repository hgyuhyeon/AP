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
    unordered_map<TreeNode*, TreeNode*> p;
    unordered_map<TreeNode*, int> leaf;
    int ans = 0;
    void collect(TreeNode* node) {
        if (!node->left && !node->right) {
            leaf[node]++;
        }
        else {
            if (node->left) {
                p[node->left] = node;
                collect(node->left);
            }
            if (node->right) {
                p[node->right] = node;
                collect(node->right);
            }
        }
    }
    void search(TreeNode* node, map<TreeNode*, int>& v, int d, int& dist) {
        if (d > dist || !node) return;
        if (!v[node]) {
            if (leaf.find(node) != leaf.end() && d > 0) {
                ans++;
                return;
            }
            v[node]++;
            search(node->left, v, d+1, dist);
            search(node->right, v, d+1, dist);
            search(p[node], v, d+1, dist);
        }
    }
    int countPairs(TreeNode* root, int distance) {
        p[root] = NULL;
        collect(root);
        
        for (auto [node, val]: leaf) {
            map<TreeNode*, int> v;
            search(node, v, 0, distance);
        }
        return ans / 2;
    }
};

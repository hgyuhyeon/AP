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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, TreeNode*> m; // parent
        map<TreeNode*, int> d; //depth
        queue<pair<int, TreeNode*>> qu;
        qu.push({0, root});
        m[root] = NULL;
        while (!qu.empty()) {
            pair<int, TreeNode*> pr = qu.front();
            d[pr.second] = pr.first;
            if (pr.second->left != NULL) {
                m[pr.second->left] = pr.second;
                qu.push({pr.first+1, pr.second->left});
            }
            if (pr.second->right != NULL) {
                m[pr.second->right] = pr.second;
                qu.push({pr.first+1, pr.second->right});
            }
            qu.pop();
        }
        
        while (d[p] > d[q]) p = m[p];
        while (d[p] < d[q]) q = m[q];
        while (p != q) {
            if (!m[p] || !m[q]) return root;
            p = m[p];
            q = m[q];
        }
        return p;
    }
};
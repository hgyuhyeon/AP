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
    bool search(TreeNode* node, int& val, string& ans) {
        if (node->val == val) return true;
        if (node->left) {
            ans.push_back('L');
            if (search(node->left, val, ans)) return true;
            ans.pop_back();
        }
        if (node->right) {
            ans.push_back('R');
            if (search(node->right, val, ans)) return true;
            ans.pop_back();
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string l, r, ans = "";
        search(root, startValue, l);
        search(root, destValue, r);
        int n = l.size() > r.size() ? l.size() : r.size();
        for (int cnt = 0; cnt < n; cnt++) {
            if (l[cnt] != r[cnt]) {
                for (int i = cnt; i < l.size(); i++) ans += 'U';
                ans += r.substr(cnt);
                return ans;
            }
        }
        return "";
    }
};

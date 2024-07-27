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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        TreeNode* head = new TreeNode(preorder[i++]);
        stack<TreeNode*> s;
        s.push(head);
        while (!s.empty() && i < preorder.size()) {
            if (preorder[i] < s.top()->val) {
                s.top()->left = new TreeNode(preorder[i++]);
                s.push(s.top()->left);
            }
            else {
                TreeNode* node = s.top();
                while (!s.empty() && s.top()->val < preorder[i]) {
                    node = s.top();
                    s.pop();
                }
                node->right = new TreeNode(preorder[i++]);
                s.push(node->right);
            }
        }
        return head;
    }
};

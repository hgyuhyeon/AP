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
class CBTInserter {
public:
    TreeNode* tree;

    CBTInserter(TreeNode* root) {
        tree = root;
    }
    
    int insert(int val) {
        TreeNode* ptr = tree;
        TreeNode *node = new TreeNode(val); 
        queue<TreeNode*> q;
        q.push(ptr);
        while (!q.empty()) {
            ptr = q.front();
            q.pop();

            if (ptr->left == nullptr) {
                ptr->left = node;
                return ptr->val;
            }
            else if (ptr->right == nullptr) {
                ptr->right = node;
                return ptr->val;
            }
            else {
                q.push(ptr->left);
                q.push(ptr->right);
            }
        }
        return NULL;
    }
    
    TreeNode* get_root() {
        return tree;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
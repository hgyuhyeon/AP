/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> q;
        if (!root) return root;
        q.push({root, 0});
        while (!q.empty()) {
            Node* node = q.front().first;
            int d = q.front().second;
            q.pop();
            if (node->left != NULL) q.push({node->left, d+1});
            if (node->right != NULL) q.push({node->right, d+1});

            if (!q.empty() && q.front().second == d) node->next = q.front().first;
            else node->next = NULL;
        }

        return root;
    }
};
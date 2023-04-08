/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        vector<Node*> ans(101);
        ans[1] = new Node(1);

        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (auto adj: curr->neighbors) {
                if (ans[adj->val] == NULL) {
                    q.push(adj);
                    ans[adj->val] = new Node(adj->val);
                }
                ans[curr->val]->neighbors.push_back(ans[adj->val]);
            }
        }
        return ans[1];
    }
};
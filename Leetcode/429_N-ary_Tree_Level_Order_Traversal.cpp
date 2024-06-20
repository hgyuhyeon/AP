/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<int> tmp;
        if (!root) return ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, lv] = q.front();
            q.pop();
            for (auto next: node->children) q.push({next, lv+1});
            tmp.push_back(node->val);
            if (q.empty() || q.front().second != lv) {
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};
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
    int search(TreeNode* node, map<int, int>& fq) {
        if (!node) return 0;
        int sum = node->val + search(node->left, fq) + search(node->right, fq);
        fq[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> fq;
        search(root, fq);
        vector<pair<int, int>> v(fq.begin(), fq.end());
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });
        vector<int> ans;
        for (auto [val, fq]: v) {
            if (fq != v[0].second) break;
            ans.push_back(val);
        }
        return ans;
    }
};
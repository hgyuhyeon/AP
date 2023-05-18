class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> head(n, true);
        for (auto edge: edges) {
            head[edge[1]] = false;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (head[i]) ans.push_back(i);
        }
        return ans;
    }
};
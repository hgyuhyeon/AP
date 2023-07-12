class Solution {
public:
    // Cycle detection dfs
    bool dfs(vector<vector<int>>& g, vector<int>& v, int i) {
        v[i] = 1; // unsure
        for (auto cur: g[i]) {
            if (v[cur] == 0 && !dfs(g, v, cur) || v[cur] == 1) {
                return false;
            }
        }
        v[i] = 2; // safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans, v(n, 0);
        for (int i = 0; i < n; i++) {
            if (v[i] == 2 || dfs(graph, v, i)) ans.push_back(i);
        }
        return ans;
    }
};
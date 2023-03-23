class Solution {
public:
    void dfs(int n, vector<vector<int>>& g, vector<bool>& v) {
        if (!v[n]) {
            v[n] = true;
            for (auto i: g[n]) if (!v[i]) dfs(i, g, v);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        vector<vector<int>> g(n);
        vector<bool> v(n, false);
        int ans = -1;

        for (auto c: connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                ans++;
                dfs(i, g, v);
            }
        }

        return ans;
    }
};
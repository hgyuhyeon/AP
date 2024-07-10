class Solution {
public:
    void dfs(vector<vector<int>>& g, map<int, int>& v, map<int, int>& r, int cur, int& ans) {
        for (auto next: g[cur]) {
            if (!v[next] && !r[next]) {
                v[next]++;
                ans++;
                dfs(g, v, r, next, ans);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int ans = 1;
        vector<vector<int>> g(n, vector<int>());
        map<int, int> r, v;
        v[0]++;
        for (auto res: restricted) r[res]++;
        for (auto e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(g, v, r, 0, ans);
        return ans;
    }
};

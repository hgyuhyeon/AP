class Solution {
public:
    bool dfs(int node, int prev, map<int, vector<int>>& m, vector<bool>& hasApple) {
        for (auto cur: m[node]) {
            if (cur != prev && dfs(cur, node, m, hasApple)) {
                hasApple[node] = true;
            }
        }
        return hasApple[node];
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int, vector<int>> m;
        int res = 0;
        for (auto e: edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        dfs(0, -1, m, hasApple);
        hasApple[0] = false;
        for (auto h: hasApple) {
            if (h) res += 2;
        }
        return res;
    }
};
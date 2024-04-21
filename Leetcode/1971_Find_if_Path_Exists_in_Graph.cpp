class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n, vector<int>());
        for (auto e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> v(n, false);
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int cur = q.front();
            if (!v[cur]) {
                v[cur] = true;
                if (cur == destination) return true;
                for (auto i: g[cur]) q.push(i);
            }
            q.pop();
        }
        return false;
    }
};
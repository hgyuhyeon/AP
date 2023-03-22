class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> path[n+1];
        for (auto r: roads) {
            path[r[0]].push_back({r[1], r[2]});
            path[r[1]].push_back({r[0], r[2]});
        }

        queue<int> q;
        vector<bool> visited(n+1, false);
        visited[1] = true;
        q.push(1);
        int minval = INT_MAX;

        while (!q.empty()) {
            for (auto p: path[q.front()]) {
                minval = min(p[1], minval);
                if (!visited[p[0]]) {
                    visited[p[0]] = true;
                    q.push(p[0]);
                }
            }
            q.pop();
        }

        return minval;
    }
};
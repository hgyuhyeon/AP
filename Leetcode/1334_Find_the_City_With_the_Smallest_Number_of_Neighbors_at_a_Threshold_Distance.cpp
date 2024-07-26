class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) g[i][i] = 0;
        for (auto e: edges) {
            g[e[0]][e[1]] = e[2];
            g[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
                }
            }
        }

        int ans = 0, val = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (g[i][j] <= distanceThreshold) cnt++;
            }
            if (cnt <= val) {
                ans = i;
                val = cnt;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int n, m, ans = 0;
    int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};
    void dfs(vector<vector<int>>& g, vector<vector<bool>>& v, int i, int j, int cur) {
        if (g[i][j] == 0) return;
        ans = max(ans, cur);
        for (int d = 0; d < 4; d++) {
            int nr = i + dr[d], nc = j + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !v[nr][nc]) {
                v[nr][nc] = true;
                dfs(g, v, nr, nc, cur+g[nr][nc]);
                v[nr][nc] = false;
            }
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    vector<vector<bool>> v(n, vector<bool>(m, false));
                    v[i][j] = true;
                    dfs(grid, v, i, j, grid[i][j]);
                }
            }
        }

        return ans;
    }
};

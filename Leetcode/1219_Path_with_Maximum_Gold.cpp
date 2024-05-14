class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<vector<bool>>& v, int i, int j, int cur, int& ans) {
        if (g[i][j] == 0) return;
        ans = max(ans, cur);
        if (i > 0 && !v[i-1][j]) {
            v[i-1][j] = true;
            dfs(g, v, i-1, j, cur+g[i-1][j], ans);
            v[i-1][j] = false;
        }
        if (j > 0 && !v[i][j-1]) {
            v[i][j-1] = true;
            dfs(g, v, i, j-1, cur+g[i][j-1], ans);
            v[i][j-1] = false;
        }
        if (i < g.size()-1 && !v[i+1][j]) {
            v[i+1][j] = true;
            dfs(g, v, i+1, j, cur+g[i+1][j], ans);
            v[i+1][j] = false;
        }
        if (j < g[0].size()-1 && !v[i][j+1]) {
            v[i][j+1] = true;
            dfs(g, v, i, j+1, cur+g[i][j+1], ans);
            v[i][j+1] = false;
        }

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    vector<vector<bool>> v(n, vector<bool>(m, false));
                    v[i][j] = true;
                    dfs(grid, v, i, j, grid[i][j], ans);
                }
            }
        }

        return ans;
    }
};
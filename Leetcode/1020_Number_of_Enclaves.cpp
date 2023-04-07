class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<vector<bool>>& v, int i, int j, int& cnt) {
        if (!g[i][j]) return true;
        if (i <= 0 || j <= 0 || i >= g.size()-1 || j >= g[i].size()-1) 
            return false;
        if (!v[i][j]) {
            v[i][j] = true;
            cnt++;
            bool up = dfs(g, v, i-1, j, cnt);
            bool down = dfs(g, v, i+1, j, cnt);
            bool left = dfs(g, v, i, j-1, cnt);
            bool right = dfs(g, v, i, j+1, cnt);
            return up && down && left && right;
        }
        return true;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] && !visited[i][j]) {
                    int cnt = 0;
                    if (dfs(grid, visited, i, j, cnt)) ans+=cnt;
                }
                else visited[i][j] = true;
            } 
        }
        return ans;
    }
};
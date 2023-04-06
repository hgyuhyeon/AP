class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<vector<bool>>& v, int i, int j) {
        if (g[i][j]) return true;
        if (i <= 0 || j <= 0 || i >= g.size()-1 || j >= g[i].size()-1) 
            return false;
        if (!v[i][j]) {
            v[i][j] = true;
            bool up = dfs(g, v, i-1, j);
            bool down = dfs(g, v, i+1, j);
            bool left = dfs(g, v, i, j-1);
            bool right = dfs(g, v, i, j+1);
            return up && down && left && right;
        }
        return true;
    }

    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!grid[i][j] && !visited[i][j]) {
                    if (dfs(grid, visited, i, j)) ans++;
                }
                else visited[i][j] = true;
            } 
        }
        return ans;
    }
};
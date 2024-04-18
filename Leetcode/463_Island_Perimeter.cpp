class Solution {
public:
    int check(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 1;
        return grid[i][j] == 1 ? 0 : 1;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;
                ans += check(grid, i-1, j) + check(grid, i+1, j) + check(grid, i, j-1) + check(grid, i, j+1);
            }
        }
        return ans;
    }
};
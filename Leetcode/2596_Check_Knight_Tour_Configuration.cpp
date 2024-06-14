class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size(), x = 0, y = 0;
        if (grid[x][y]) return false;
        while (grid[x][y] < n * n - 1) {
            pair<int, int> p = {-1, -1};
            for (int i = -2; i <= 2; i += 4) {
                for (int j = -1; j <= 1; j += 2) {
                    int r = x + i, c = y + j;
                    if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == grid[x][y] + 1) {
                        p.first = r;
                        p.second = c;
                    }
                }
            }
            for (int i = -1; i <= 1; i += 2) {
                for (int j = -2; j <= 2; j += 4) {
                    int r = x + i, c = y + j;
                    if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == grid[x][y] + 1) {
                        p.first = r;
                        p.second = c;
                    }
                }
            }
            if (p.first == -1) return false;
            x = p.first;
            y = p.second;
        }
        return true;
    }
};
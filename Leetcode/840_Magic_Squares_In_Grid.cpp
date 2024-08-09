class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < m-2; j++) {
                if (isValid(grid, i, j)) ans++;
            }
        }
        return ans;
    }

    bool isValid(vector<vector<int>>& grid, int i, int j) {
        map<int, int> m;
        for (int x = i; x < i+3; x++) {
            for (int y = j; y < j+3; y++) {
                if (m[grid[x][y]] > 0 || grid[x][y] > 9 || grid[x][y] == 0) return false;
                m[grid[x][y]]++;
            }
        }

        // sum
        if (grid[i][j] + grid[i+2][j+2] != grid[i+2][j] + grid[i][j+2]) return false;
        int sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        for (int x = i; x < i+3; x++) if (grid[x][j] + grid[x][j+1] + grid[x][j+2] != sum) return false;
        for (int y = j; y < j+3; y++) if (grid[i][y] + grid[i+1][y] + grid[i+2][y] != sum) return false;
        return true;
    }
};

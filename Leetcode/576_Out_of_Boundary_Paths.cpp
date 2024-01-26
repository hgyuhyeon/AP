const int mod = 1e9+7;
class Solution {
private:
    int row, column;
    vector<vector<vector<int>>> dp;
public:
    int dfs(int r, int c, int move) {
        if (move < 0) return 0;
        if (r < 0 || c < 0 || r >= row || c >= column) return 1;
        if (dp[r][c][move] != -1) return dp[r][c][move];
        int ans = 0;
        ans = (ans + dfs(r-1, c, move-1)) % mod;
        ans = (ans + dfs(r+1, c, move-1)) % mod;
        ans = (ans + dfs(r, c-1, move-1)) % mod;
        ans = (ans + dfs(r, c+1, move-1)) % mod;
        return dp[r][c][move] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        row = m;
        column = n;
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return dfs(startRow, startColumn, maxMove);
    }
};
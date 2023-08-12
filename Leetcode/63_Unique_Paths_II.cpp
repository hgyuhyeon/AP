class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        vector<vector<int>> dp(og.size(), vector<int>(og[0].size()));
        int n = dp.size(), m = dp[0].size();
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (og[i][j] == 1) dp[i][j] = 0;
                else {
                    if (i > 0) dp[i][j] += dp[i-1][j];
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
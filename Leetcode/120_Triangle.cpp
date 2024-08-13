class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = 2, ans = INT_MAX;
        if (n == 1) return triangle[0][0];
        vector<vector<int>> dp(triangle.begin(), triangle.end());
        for (int i = 1; i < n; i++, m++) {
            dp[i][0] += dp[i-1][0];
            for (int j = 1; j < m - 1; j++) dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
            dp[i][m-1] += dp[i-1][m-2];
        }

        for (int j = 0; j < dp[n-1].size(); j++) ans = min(ans, dp[n-1][j]);
        return ans;
    }
};

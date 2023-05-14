class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            long long prev = (i + q[i][1] + 1 <= n) ? dp[i + q[i][1] + 1] : 0;
            dp[i] = max(prev + q[i][0], dp[i + 1]);
        }

        return dp[0];
    }
};
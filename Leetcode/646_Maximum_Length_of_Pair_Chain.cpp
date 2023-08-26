class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > pairs[i-1][1]) dp[i] = dp[i-1] + 1;
            else {
                int j = i;
                for (j = i - 2; j >= 0; j--) {
                    if (pairs[i][0] > pairs[j][1]) {
                        dp[i] = dp[j]+1;
                        break;
                    }
                }
                if (j < 0) dp[i] = 1;
            }
        }
        return dp[n-1];
    }
};
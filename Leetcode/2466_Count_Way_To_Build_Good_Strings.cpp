class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int modulo = 1e9 + 7, ans = 0;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for (int i = 1; i < high + 1; i++) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % modulo;
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % modulo;
        }

        for (int l = low; l <= high; l++) {
            ans = (ans + dp[l]) % modulo;
        }

        return ans;
    }
};
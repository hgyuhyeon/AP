class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int len = 1, sum = 0, maxval = 0;
            for (int j = i; j >= 0; j--, len++) {
                if (len > k) break;
                maxval = max(maxval, arr[j]);
                sum = max(sum, maxval * len);
                int prev = (j - 1 >= 0) ? dp[j - 1] : 0;
                dp[i] = max(dp[i], prev + sum);
            }
        }
        return dp[n - 1];
    }
};
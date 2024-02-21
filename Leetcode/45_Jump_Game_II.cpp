class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 10000);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= i + nums[i]; j++) {
                if (j >= n) dp[n - 1] = min(dp[i] + 1, dp[n - 1]);
                else dp[j] = min(dp[i] + 1, dp[j]);
            }
        }
        return dp[n-1];
    }
};
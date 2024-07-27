class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < n; i++) {
            for (int j = i - 2; j >= 0; j--) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
        return max(dp[n-1], dp[n-2]);
    }
};

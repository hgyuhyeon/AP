class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), ans = abs(nums[0]);
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = nums[0];
        dp[1][0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i-1] + nums[i], nums[i]);
            dp[1][i] = min(dp[1][i-1] + nums[i], nums[i]);
            ans = max(ans, max(dp[0][i], abs(dp[1][i])));
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), len = 1;
        vector<int> ans, dp(n, 1);
        for (int i = 1; i < n; i++) { // dp[0] = 1
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    len = max(len, dp[i]);
                }
            }
        }

        int prev = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == len && (!prev || prev % nums[i] == 0)) {
                ans.push_back(nums[i]);
                len--;
                prev = nums[i];
            }
        }
        return ans;
        
    }
};
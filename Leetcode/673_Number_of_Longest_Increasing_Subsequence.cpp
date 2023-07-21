class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 1, ans = 0;
        vector<int> dp(n, 1), cnt(n, 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) { // pivot
            for (int j = 0; j < i; j++) { // behind
                if (nums[i] > nums[j]) { // if num increases
                    if (dp[j] + 1 > dp[i]) { // length increase
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i]) cnt[i] += cnt[j]; // same length
                }
            }
            len = max(len, dp[i]);
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] == len) ans += cnt[i];
        }

        return ans;
    }
};
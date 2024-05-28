class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            while (!pq.empty()) {
                if (pq.top().second >= i-k) {
                    dp[i] = max(dp[i], pq.top().first + nums[i]);
                    pq.push({dp[i], i});
                    break;
                }
                else pq.pop();
            }
            if (pq.empty()) {
                dp[i] = max(dp[i], nums[i]);
                pq.push({dp[i], i});
            }
        }
        return dp[n-1];
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo = 0, hi = -1, sum = 0, n = nums.size(), ans = INT_MAX;
        while (++hi < n) {
            sum += nums[hi];
            while (sum >= target && lo <= hi) {
                ans = min(ans, hi - lo + 1);
                sum -= nums[lo++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
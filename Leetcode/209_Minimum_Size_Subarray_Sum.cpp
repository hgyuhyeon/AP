class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e9, lo = 0, hi = 0, sum = nums[0], n = nums.size(), numSum = nums[0];
        if (hi == n - 1) return nums[0] > target ? 1 : 0;
        while (hi < n - 1) {
            if (sum < target) {
                sum += nums[++hi];
                numSum += nums[hi];
            }
            if (sum >= target) {
                while (sum >= target) sum -= nums[lo++];
                if (ans > hi - lo + 2) ans = hi - lo + 2;
            }
        }

        if (numSum >= target) return ans;
        else return 0;
    }
};
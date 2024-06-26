class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = nums[n-1] - nums[0];
        for (int i = 0; i < n-1; i++) {
            int lo = min(nums[0]+k, nums[i+1]-k); // 1~n-1
            int hi = max(nums[n-1]-k, nums[i]+k); // 0~n-2
            ans = min(ans, hi - lo);
        }
        return ans;
    }
};
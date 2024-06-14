class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i-1] >= nums[i]) {
                ans += (nums[i-1] + 1 - nums[i]);
                nums[i] = nums[i-1] + 1;
            }
        }
        return ans;
    }
};
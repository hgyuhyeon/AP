class Solution {
public:
    int ans = 0;
    void search(vector<int>& nums, int val, int idx, int& target) {
        if (idx == nums.size()) {
            if (val == target) ans++;
        }
        else {
            search(nums, val + nums[idx], idx+1, target);
            search(nums, val - nums[idx], idx+1, target);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        search(nums, 0, 0, target);
        return ans;
    }
};

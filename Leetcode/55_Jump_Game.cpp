class Solution {
public:
    bool jump(vector<int>& nums, vector<bool>& dp, int index) {
        if (index >= nums.size()-1) return true;
        for (int i = index + nums[index]; i > index; i--) {
            if (dp[i]) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        int last = nums.size() - 1;
        if (last == 0) return true;
        dp[last] = nums[last] > 0 ? true : false;
        for (int i = last - 1; i >= 0; i--) {
            if (i + nums[i] >= last) dp[i] = true;
            else dp[i] = jump(nums, dp, i);
        }
        return dp[0];
    }
};
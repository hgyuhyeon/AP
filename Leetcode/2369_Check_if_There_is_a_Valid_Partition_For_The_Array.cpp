class Solution {
public:
    bool validPartition(vector<int>& nums) {
        if (nums.size() == 2) {
            if (nums[0] == nums[1]) return true;
            else return false;
        } 

        vector<bool> dp(nums.size(), false);
        int n = nums.size();

        if (nums[0] == nums[1]) dp[1] = true;
        if ((nums[2] == nums[1] && nums[2] == nums[0]) || (nums[2] - nums[1] == 1 && nums[1] - nums[0] == 1)) dp[2] = true;
        
        for (int i = 3; i < n; i++) {
            if ((nums[i] == nums[i-1]) && dp[i-2]) dp[i] = true;
            else if ((nums[i] == nums[i-1] && nums[i] == nums[i-2]) && dp[i-3]) dp[i] = true;
            else if ((nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1) && dp[i-3]) dp[i] = true;
        }
        
        return dp[n-1];
    }
};
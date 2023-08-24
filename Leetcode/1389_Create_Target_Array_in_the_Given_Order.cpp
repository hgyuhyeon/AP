class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans(nums.size(), -1);
        
        for (int i = 0; i < nums.size(); i++) {
            if (ans[index[i]] == -1) ans[index[i]] = nums[i];
            else {
                for (int j = nums.size() - 1; j >= index[i] + 1; j--)
                    ans[j] = ans[j-1];
                ans[index[i]] = nums[i];
            }
        }

        return ans;
    }
};

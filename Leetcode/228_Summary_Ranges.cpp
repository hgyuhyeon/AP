class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int piv = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[i+1] != nums[i] + 1) {
                if (i == piv)
                    ans.push_back(to_string(nums[piv]));
                else {
                    ans.push_back(to_string(nums[piv]) + "->" + to_string(nums[i]));
                }
                piv = i + 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> val;
    void solve(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(val);
            return;
        }
        val.push_back(nums[idx]);
        solve(nums, idx+1);
        val.pop_back();
        int idx2 = idx;
        while (idx2 < nums.size() && nums[idx2] == nums[idx]) idx2++;
        solve(nums, idx2);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
};

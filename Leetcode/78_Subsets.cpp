class Solution {
public:
    void search(vector<int>& nums, vector<int> tmp, int i, vector<vector<int>>& ans) {
        for (int j = i; j < nums.size(); j++) {
            tmp.push_back(nums[j]);
            ans.push_back(tmp);
            search(nums, tmp, j+1, ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>());
        search(nums, vector<int>(), 0, ans);
        return ans;
    }
};
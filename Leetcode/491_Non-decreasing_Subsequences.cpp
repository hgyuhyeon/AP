class Solution {
public:
    vector<int> res;
    set<vector<int>> ans;

    void search(vector<int>& nums, int index) {
        if (index >= nums.size()) return;
        if (res.size() == 0 || nums[index] >= res.back()) {
            res.push_back(nums[index]);
            if (res.size() >= 2) ans.insert(res);
            search(nums, index+1);
            res.pop_back();
        }
        search(nums, index+1);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        search(nums, 0);
        return vector(ans.begin(), ans.end());
    }
};
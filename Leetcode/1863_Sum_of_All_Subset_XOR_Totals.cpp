class Solution {
public:
    void search(vector<int>& nums, int i, int t, int& ans) {
        ans += t ^ nums[i];
        for (int j = i + 1, n = nums.size(); j < n; j++) search(nums, j, t ^ nums[i], ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) search(nums, i, 0, ans);
        return ans;
    }
};
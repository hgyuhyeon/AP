class Solution {
public:
    void search(vector<int>& nums, int i, map<int, int>& m, int& k, int& ans) {
        for (int j = i, n = nums.size(); j < n; j++) {
            if (!m[nums[j] - k] && !m[nums[j] + k]) {
                m[nums[j]]++;
                search(nums, j+1, m, k, ++ans);
                m[nums[j]]--;
            }
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> m;
        search(nums, 0, m, k, ans);
        return ans;
    }
};
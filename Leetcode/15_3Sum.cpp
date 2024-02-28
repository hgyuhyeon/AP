class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int n = nums.size(), idx = 1;
        for (auto num: nums) {
            int lo = idx++, hi = n-1, mid;
            while (lo < hi) {
                if (num + nums[lo] + nums[hi] == 0) s.insert({num, nums[lo++], nums[hi--]});
                else if (num + nums[lo] + nums[hi] < 0) lo++;
                else hi--;
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
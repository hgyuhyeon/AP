class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        for (int ih = 3; ih < n; ih++) {
            for (int il = 0; il < ih - 2; il++) {
                int lo = il+1, hi = ih-1;
                while (lo < hi) {
                    if ((long)nums[il] + (long)nums[lo] + (long)nums[hi] + (long)nums[ih] == target) ans.insert({nums[il], nums[lo], nums[hi], nums[ih]});
                    if ((long)nums[il] + (long)nums[lo] + (long)nums[hi] + (long)nums[ih] < target) lo++;
                    else hi--;
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

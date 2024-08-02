class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0, n = nums.size(), ans = INT_MAX;
        for (int i : nums) if (i == 1) cnt++;
        int wd = 0;
        for (int i = 0; i < cnt; i++) if (nums[i] == 0) wd++;
        for (int lo = 0, hi = cnt; hi < n * 2; lo++, hi++) {
            ans = min(ans, wd);
            if (nums[hi % n] == 0) wd++;
            if (nums[lo % n] == 0) wd--;
        }
        return ans;
    }
};

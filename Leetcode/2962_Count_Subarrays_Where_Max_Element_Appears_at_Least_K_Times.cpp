class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_val = *max_element(nums.begin(), nums.end()), n = nums.size();
        long long ans = 0;
        for (int lo = 0, hi = 0, cnt = 0; hi < n; hi++) {
            if (nums[hi] == max_val) cnt++;
            while (cnt >= k) {
                if (nums[lo++] == max_val) cnt--;
                ans += n - hi;
            }
        }
        return ans;
    }
};
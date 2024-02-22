class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, cnt = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i-1] == nums[i]) continue;
            if (nums[i-1] + 1 == nums[i]) cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        return n == 0 ? 0 : max(ans, cnt);
    }
};
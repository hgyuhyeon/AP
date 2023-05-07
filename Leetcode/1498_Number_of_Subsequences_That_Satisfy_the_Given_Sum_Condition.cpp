class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0, mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1; // i = min, j = max

        vector<int> pows(nums.size(), 1);
        for (int p = 1; p < pows.size(); p++) pows[p] = pows[p - 1] * 2 % mod;

        while (i <= j) {
            if (nums[i] + nums[j] > target) j--;
            else ans = (ans + pows[j - i++]) % mod;
        }

        return ans;
    }
};
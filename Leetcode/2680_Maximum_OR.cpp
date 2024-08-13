class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long mul = pow(2, k), ans = 0;
        int n = nums.size();
        if (n == 1) return nums[0] * mul;
        vector<long long> pf(n, 0), sf(n, 0);
        pf[0] = nums[0];
        sf[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            pf[i] = pf[i-1] | nums[i];
            sf[n-i-1] = sf[n-i] | nums[n-i-1];
        }
        ans = (nums[0] * mul) | sf[1];
        for (int i = 1; i < n-1; i++) {
            ans = max(ans, (pf[i-1] | (nums[i] * mul) | sf[i+1]));
        }
        ans = max(ans, (nums[n-1] * mul) | pf[n-2]);
        return ans;
    }
};

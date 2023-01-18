class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxt = 0, mint = 0, minsum = INT_MAX, sum = INT_MIN, total = 0;
        if (nums.size() == 1) return nums[0];

        for (auto i: nums) {
            total += i;
            maxt = max(maxt + i, i);
            mint = min(mint + i, i);
            sum = max(sum, maxt);
            minsum = min(minsum, mint);
        }
        
        return sum < 0 ? sum : max(sum, total - minsum);
    }
};
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (auto i: nums) sum += i;
        for (int i = nums.size() - 1; i >= 2; i--) {
            if (sum - nums[i] > nums[i]) return sum;
            sum -= nums[i];
        }
        return -1;
    }
};
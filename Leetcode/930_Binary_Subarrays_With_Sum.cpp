class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        int n = nums.size(), sum = 0, ans = 0;
        m[0] = 1;
        for (auto i: nums) {
            sum += i;
            ans += m[sum - goal];
            m[sum]++;
        }
        return ans;
    }
};
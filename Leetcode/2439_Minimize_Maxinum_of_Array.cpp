class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ans = 0, avg;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            avg = sum / (i + 1);
            if (sum % (i + 1) != 0) avg++;
            ans = max(ans, avg);
        }
        return ans;
    }
};
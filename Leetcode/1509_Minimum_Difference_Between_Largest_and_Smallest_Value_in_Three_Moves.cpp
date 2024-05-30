class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n - 1, cnt = 0;
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i <= 3; i++) {
            pq.push(nums[n - 1 - (3 - i)] - nums[i]);
        }
        return pq.top();
    }
};
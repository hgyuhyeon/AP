class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        queue<int> q;
        int n = nums.size();
        k %= n;
        for (int i = n - k; i < n; i++) q.push(nums[i]);
        for (int i = 0; i < n - k; i++) q.push(nums[i]);
        for (int i = 0; i < n; i++) {
            nums[i] = q.front();
            q.pop();
        }
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pq, nq;
        for (auto i: nums) {
            if (i > 0) pq.push(i);
            else nq.push(i);
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = pq.front();
                pq.pop();
            }
            else {
                nums[i] = nq.front();
                nq.pop();
            }
        }
        return nums;
    }
};
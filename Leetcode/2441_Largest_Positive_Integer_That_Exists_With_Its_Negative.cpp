class Solution {
public:
    int findMaxK(vector<int>& nums) {
        priority_queue<int> pq;
        map<int, int> m;
        for (auto n: nums) {
            m[n]++;
            if (m[-n] > 0) pq.push(abs(n));
        }
        return pq.empty() ? -1 : pq.top();
    }
};
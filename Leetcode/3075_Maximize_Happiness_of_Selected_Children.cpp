class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for (auto h: happiness) pq.push(h);
        int dec = 0;
        long long ans = 0;
        while (!pq.empty() && dec < k) {
            if (pq.top() - dec > 0) ans += (pq.top()-dec++);
            pq.pop();
        }
        return ans;
    }
};
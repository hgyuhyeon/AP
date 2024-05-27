class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int lo = 0, hi = costs.size()-1;
        if (lo == hi) return costs[0];
        while (lo < candidates && lo < hi) {
            pq.push({costs[lo++], 0});
            pq.push({costs[hi--], 1});
        }
        long long ans = 0;
        while (k-- > 0) {
            auto [val, i] = pq.top();
            pq.pop();
            ans += val;
            if (lo <= hi) {
                if (i == 0) pq.push({costs[lo++], 0});
                else if (i == 1) pq.push({costs[hi--], 1});
            }
        }
        return ans;
    }
};
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        if (ladders >= n) return n-1;
        for (int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            if (diff > 0 && pq.size() < ladders) pq.push(diff);
            else if (diff > 0 && !pq.empty() && pq.top() < diff) {
                bricks -= pq.top();
                pq.pop();
                pq.push(diff);
            }
            else if (diff > 0) bricks -= diff;

            if (bricks < 0) return i-1;
        }
        return n - 1;
    }
};
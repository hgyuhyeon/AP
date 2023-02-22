class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 0, hi = 0, mid;
        for (int weight: weights) {
            hi += weight;
            if (lo < weight) lo = weight;
        }
        while (lo < hi) {
            mid = (lo + hi) / 2;
            int w = 0, d = 1;
            for (int weight: weights) {
                if (w + weight > mid) {
                    d++;
                    w = 0;
                }
                w += weight;
            }
            if (d > days) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
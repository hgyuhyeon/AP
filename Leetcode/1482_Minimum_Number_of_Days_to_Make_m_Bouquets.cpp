class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k) return -1;
        int lo = 1, hi = 1e9, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            int b = 0;
            for (int i = 0, n = bloomDay.size(), len = 0; i < n; i++) {
                if (bloomDay[i] <= mid) len++;
                else len = 0;
                if (len == k) {
                    b++;
                    len = 0;
                }
            }
            if (b >= m) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
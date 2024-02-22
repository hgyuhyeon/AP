class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end());
        int ans = 0, n = c.size(), lo = 0, hi = n - 1, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (c[mid] >= n - mid) {
                ans = max(ans, n - mid);
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, n = s.size();
        vector<int> pf(n);
        pf[0] = abs(s[0] - t[0]);
        for (int i = 1; i < n; i++) pf[i] = abs(s[i] - t[i]) + pf[i-1];
        int lo = 0, hi = 0;
        while (hi < n && pf[hi] <= maxCost) ans = max(++hi, ans);
        while (hi < n) {
            while (hi < n && pf[hi] - pf[lo] <= maxCost) ans = max(++hi - (lo+1), ans);
            lo++;
        }
        return ans;
    }
};
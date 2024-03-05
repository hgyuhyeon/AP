class Solution {
public:
    int minimumLength(string s) {
        int lo = 0, hi = s.size() - 1;
        char c = s[0];
        while (lo < hi) {
            if (s[lo] == s[hi]) {
                c = s[lo];
                while (s[lo] == c && lo <= hi) lo++;
                while (s[hi] == c && hi >= lo) hi--;
            }
            else break;
        }
        return hi - lo + 1 < 0 ? 0 : hi - lo + 1;
    }
};
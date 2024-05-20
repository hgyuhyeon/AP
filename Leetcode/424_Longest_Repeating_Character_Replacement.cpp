class Solution {
public:
    int characterReplacement(string s, int k) {
        int lo = 0, hi = 0, n = s.size(), len = 0;
        map<char, int> m;
        while (hi < n) {
            len = max(len, ++m[s[hi++]]);
            if (hi - lo - len > k) --m[s[lo++]];
        }
        return n - lo;
    }
};
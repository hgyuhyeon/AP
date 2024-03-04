class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int lo = 0, hi = 0, n = s.size(), len = 0, ans = 0;
        while (hi < n) {
            if (m[s[hi]] == 0) {
                m[s[hi++]]++;
                ans = max(ans, ++len);
            }
            else {
                while (m[s[hi]] > 0 && lo < hi) {
                    m[s[lo++]]--;
                    len--;
                }
                m[s[hi++]] = 1;
                len++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int partitionString(string s) {
        map<char, int> m;
        int lo = 0, hi = 0, ans = 1;
        while (hi < s.size()) {
            if (m[s[hi]] == 0) m[s[hi++]]++;
            else {
                ans++;
                while (m[s[lo]] && lo < hi) m[s[lo++]]--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for (auto c: s) m[c]++;
        int odd = 0, ans = 0;
        for (auto [c, val]: m) {
            if (val % 2 == 0) ans += val;
            else {
                ans += (val - 1);
                odd = max(odd, 1);
            }
        }
        return ans + odd;
    }
};
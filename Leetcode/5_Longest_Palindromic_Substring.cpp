class Solution {
public:
    string longestPalindrome(string s) {
        int lindex, rindex, len = 0;

        for (int i = 0; i < s.size(); i++) {
            int l = i - 1, r = i + 1, tmp = 1;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    tmp += 2;
                    l--;
                    r++;
                }
                else break;
            }

            if (len < tmp) {
                len = tmp;
                lindex = ++l;
                rindex = --r;
            }
        }

        for (int i = 0; i < s.size() - 1; i++) {
            int l = i, r = i + 1, tmp = 0;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    tmp += 2;
                    l--;
                    r++;
                }
                else break;
            }

            if (len < tmp) {
                len = tmp;
                lindex = ++l;
                rindex = --r;
            }
        }

        return s.substr(lindex, rindex - lindex + 1);
    }
};
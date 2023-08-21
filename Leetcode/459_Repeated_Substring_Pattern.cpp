class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = 1;
        while (len * 2 <= s.size()) {
            if (s.size() % len == 0) {
                string sub = s.substr(0, len), newstr = "";
                for (int i = 0; i < s.size() / len; i++) newstr += sub;
                if (newstr == s) return true;
            }
            len++;
        }
        return false;
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int lo = 0, hi = s.size()-1;
        while (lo < hi) if (s[lo++] != s[hi--]) return false;
        return true;
    }
};
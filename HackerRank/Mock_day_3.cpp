bool isPalindrome(string s, int lo, int hi) {
    while (lo < hi) if (s[lo++] != s[hi--]) return false;
    return true;
}
int palindromeIndex(string s) {
    int lo = 0, hi = s.size()-1;
    do {
        if (s[lo] != s[hi]) {
            bool val1 = isPalindrome(s, lo+1, hi), val2 = isPalindrome(s, lo, hi-1);
            if (!val1 && !val2) break;
            else if (val1) return lo;
            else return hi;
        }
    } while (++lo < --hi);
    return -1;
}
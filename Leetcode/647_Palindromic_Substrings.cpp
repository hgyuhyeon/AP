class Solution {
public:
    bool check(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) if (s[start++] != s[end--]) return false;
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size(), ans = n;
        for (int i = 0; i < n; i++) {
            string str(1, s[i]);
            for (int j = i + 1; j < n; j++) {
                str += s[j];
                if (check(str)) ans++;
            }
        }
        return ans;
    }
};
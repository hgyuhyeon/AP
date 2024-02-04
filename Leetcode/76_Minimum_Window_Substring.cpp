class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        map<char, int> m;
        int start = 0, end = 0, head = 0, n = s.size();
        int len = t.size(), d = INT_MAX;
        for (auto c: t) m[c]++;
        
        while (end < n) {
            if (m[s[end++]]-- > 0) len--;
            while (len == 0) {
                if (end - start < d) d = end - (head = start);
                if (m[s[start++]]++ == 0) len++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
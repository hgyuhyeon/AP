class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        for (auto c: s) m[c]++;
        int n = s.size();
        for (int i = 0; i < n ; i++) if (m[s[i]] == 1) return i;
        return -1;
    }
};
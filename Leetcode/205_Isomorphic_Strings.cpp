class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        map<char, int> occupied;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if ((!m[s[i]] && !occupied[t[i]]) || (m[s[i]] == t[i])) {
                m[s[i]] = t[i];
                occupied[t[i]]++;
            }
            else return false;
        }
        return true;
    }
};
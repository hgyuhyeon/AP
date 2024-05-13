class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        for (auto c: s) if (c == t[i]) i++;
        return t.size() - i;
    }
};
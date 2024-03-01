class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        map<char, int> m;
        for (auto c: s) m[c]++;
        string ans = "";
        for (int i = 0; i < m['1'] - 1; i++) ans += "1";
        for (int i = 0; i < m['0']; i++) ans += "0";
        return ans + "1";
    }
};
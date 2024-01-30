class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int index = 0, ssize = s.size();
        for (char c: pattern) {
            string temp = "";
            if (index >= ssize) return false;
            while (index < ssize && s[index] != ' ') temp += s[index++];
            index += 1;
            if (m1.count(c) == 0 && m2.count(temp) == 0) {
                m1[c] = temp;
                m2[temp] = c;
            }
            else if (m1[c] == temp && m2[temp] == c) continue;
            else return false;
        }
        return (index < ssize) ? false : true;
    }
};
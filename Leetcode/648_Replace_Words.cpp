class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        map<string, int> m;
        for (auto dict: dictionary) m[dict]++;

        string ans = "", w = "";
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == ' ') {
                ans += w + " ";
                w = "";
            }
            else {
                w += s[i];
                if (m[w] > 0) {
                    ans += w;
                    w = "";
                    while (i < n && s[i] != ' ') i++;
                    i--;
                }
            }
        }
        return ans + w;
    }
};
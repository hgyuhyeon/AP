class Solution {
public:
    string reverseWords(string s) {
        string sp = "", ans = "";
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (sp != "") ans += (' ' + sp);
                sp = "";
            }
            else sp = (s[i] + sp);
        }
        if (sp != "") ans += (' ' + sp);
        return ans.substr(1);
    }
};
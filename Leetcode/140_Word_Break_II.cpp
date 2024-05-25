class Solution {
public:
    vector<string> ans;
    void solve(string s, map<string, int>& m, int i, string& tmp) {
        if (i >= s.size()) ans.push_back(tmp);
        else {
            string word = "";
            for (int j = i; j <= i+10 && j < s.size(); j++) {
                word += s[j];
                if (m[word] > 0) {
                    if (tmp.size() == 0) tmp = word;
                    else tmp += " " + word;
                    solve(s, m, j+1, tmp);
                    for (int k = 0; k < word.size(); k++) tmp.pop_back(); // character
                    if (tmp.size() > 0) tmp.pop_back(); // " "
                }
                
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, int> m;
        for (auto w: wordDict) m[w]++;
        string tmp = "";
        solve(s, m, 0, tmp);
        return ans;
    }
};
class Solution {
private:
    vector<string> ans;
public:
    void search(string& s, int idx, string str) {
        if (idx == s.size()) ans.push_back(str);
        else {
            while (idx < s.size() && !isalpha(s[idx])) str += s[idx++];
            if (idx == s.size()) {
                ans.push_back(str);
                return;
            }
            search(s, idx+1, str + (char)tolower((s[idx])));
            search(s, idx+1, str + (char)toupper((s[idx])));
        }
    }
    vector<string> letterCasePermutation(string s) {
        search(s, 0, "");
        return ans;
    }
};

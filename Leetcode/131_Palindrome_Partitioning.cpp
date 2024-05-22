class Solution {
public:
    bool isPalindrome(string& s) {
        int lo = 0, hi = s.size()-1;
        while (lo < hi) if (s[lo++] != s[hi--]) return false;
        return true;
    }
    void search(string& s, int i, vector<string>& tmp, vector<vector<string>>& ans) {
        if (i == s.size()) ans.push_back(tmp);
        else {
            string tstr = "";
            for (int j = i; j < s.size(); j++) {
                tstr += s[j];
                if (!isPalindrome(tstr)) continue;
                tmp.push_back(tstr);
                search(s, j+1, tmp, ans);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        search(s, 0, tmp, ans);
        return ans;
    }
};
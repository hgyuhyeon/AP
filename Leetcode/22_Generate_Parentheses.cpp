class Solution {
public:
    void gen(vector<string>& ans, string s, int l, int r) {
        if (!l && !r) ans.push_back(s);
        else {
            if (l > 0) gen(ans, s+"(", l-1, r+1);
            if (r > 0) gen(ans, s+")", l, r-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        gen(ans, s, n, 0);
        return ans;
    }
};
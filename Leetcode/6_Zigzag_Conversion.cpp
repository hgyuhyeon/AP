class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> strs(numRows, "");
        int n = s.size(), diff = 2 * (numRows - 1);
        for (int i = 0; i < n; i++) {
            int k = i % diff;
            if (k >= numRows) k = diff - k;
            strs[k] += s[i];
        }

        string ans = "";
        for (auto c: strs) ans += c;
        return ans;
    }
};
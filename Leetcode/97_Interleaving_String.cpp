class Solution {
public:
    bool check(string& s1, string& s2, string& s3, int i1, int i2, int i3, vector<vector<int>>& dp) {
        if (i1 >= s1.size() && i2 >= s2.size() && i3 >= s3.size()) return true; // end

        if(i1 >= 0 && i2 >= 0 && dp[i1][i2] != -1) return dp[i1][i2]; // memorized

        if (i1 < s1.size() && i2 < s2.size() && s1[i1] == s3[i3] && s2[i2] == s3[i3]) {
            return dp[i1][i2] = check(s1, s2, s3, i1+1, i2, i3+1, dp) || check(s1, s2, s3, i1, i2+1, i3+1, dp);
        }
        else if (i1 < s1.size() && s1[i1] == s3[i3]) return check(s1, s2, s3, i1+1, i2, i3+1, dp);
        else if (i2 < s2.size() && s2[i2] == s3[i3]) return check(s1, s2, s3, i1, i2+1, i3+1, dp);
        else return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return check(s1, s2, s3, 0, 0, 0, dp);
    }
};
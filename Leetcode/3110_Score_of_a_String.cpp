class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i = s.size()-1; i > 0; i--) {
            ans += abs(s[i] - s[i-1]);
        }
        return ans;
    }
};
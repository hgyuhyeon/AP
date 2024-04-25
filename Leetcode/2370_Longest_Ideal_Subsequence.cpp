class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size(), ans = 0;
        vector<int> dp(26,0);
        for (auto i: s) {
            int idx = i - 'a';
            for (int j = idx-k; j <= idx+k; j++) {
                if (j < 0 || j > 25) continue; 
                dp[idx] = max(dp[idx], dp[j]);
            }
            ans = max(ans, ++dp[idx]);
        }
        return ans;
    }
};
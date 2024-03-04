class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0, lo = 0, hi = tokens.size() - 1, score = 0;
        sort(tokens.begin(), tokens.end());
        while (lo <= hi) {
            if (power - tokens[lo] >= 0) {
                power -= tokens[lo++];
                ans = max(ans, ++score);
            }
            else {
                power += tokens[hi--];
                if (--score < 0) return 0;
            }
        }
        return ans;
    }
};
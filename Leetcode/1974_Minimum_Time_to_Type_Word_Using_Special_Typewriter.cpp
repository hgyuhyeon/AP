class Solution {
public:
    int minTimeToType(string word) {
        int ans = word.size(), n = word.size();
        char p = 'a';
        for (auto c: word) {
            int diff = abs(c - p);
            if (26 - diff < diff) diff = 26 - diff;
            p = c;
            ans += diff;
        }
        return ans;
    }
};
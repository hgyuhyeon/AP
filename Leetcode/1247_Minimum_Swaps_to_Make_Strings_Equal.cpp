class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1 == s2) return 0;
        int ans = 0;
        vector<int> v(2, 0); // x y => 0, y x => 1
        for (int i = 0, n = s1.size(); i < n; i++) {
            if (s1[i] != s2[i]) v[s1[i]-'x']++;
        }
        ans += v[0] / 2 + v[1] / 2;
        v[0] %= 2;
        v[1] %= 2;
        if (v[0] && v[1]) return ans + 2;
        else if (v[0] || v[1]) return -1;
        else return ans;
    }
};
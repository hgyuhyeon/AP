class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> m, wm;
        int ans = 0;
        for (auto c: chars) m[c]++;

        for (auto w: words) {
            ans += w.size();
            wm.clear();
            for (auto c: w) {
                wm[c]++;
                if (m[c] < wm[c]) {
                    ans -= w.size();
                    break;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char, int> m;
        for (auto w: words) {
            for (auto c: w) m[c]++;
        }

        int n = words.size();
        for (char c = 'a'; c <= 'z'; c++) {
            if (m[c] % n != 0) return false;
        }

        return true;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (auto c: s) m[c]++;
        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](pair<char, int> a, pair <char,int> b) -> bool {
            if (a.second > b.second) return true;
            else return false;
        });
        s = "";
        for (auto p: v) {
            int i = 0;
            while (i++ < p.second) s += p.first;
        }
        return s;
    }
};
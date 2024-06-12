class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> m;
        for (auto i: arr) m[i]++;
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return abs(a.first) < abs(b.first);
        });
        for (auto [i, val]: v) {
            if (m[i] > m[i*2]) return false;
            m[i*2] -= m[i];
        }
        return true;
    }
};
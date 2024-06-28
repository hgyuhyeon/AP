class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> v(n);
        for (int i = 0 ; i < n; i++) v[i] = {i, 0};
        for (auto r: roads) {
            v[r[0]].second++;
            v[r[1]].second++;
        }
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });
        map<int, int> m;
        for (int i = n; i > 0; i--) m[v[n-i].first] = i;
        long long ans = 0;
        for (auto r: roads) ans += m[r[0]] + m[r[1]];
        return ans;
    }
};
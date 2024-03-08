class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.second > b.second) return true;
        else return false;
    }
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto i: nums) m[i]++;
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);
        int freq = v[0].second, i = 0, n = v.size(), ans = 0;
        while (i < n && v[i++].second == freq) ans += freq;
        return ans;
    }
};
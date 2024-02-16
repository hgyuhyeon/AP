class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b) {
        if (a.second < b.second) return true;
        else return false;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int i: arr) m[i]++;
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), compare);
        int ans = v.size();
        for (auto p: v) {
            if (k - p.second >= 0) {
                ans--;
                k -= p.second;
            }
            else break;
        }
        return ans;
    }
};
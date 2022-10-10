class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        if (a.second < b.second)
            return true;
        else if (a.second == b.second) {
            if (a.first <= b.first)
                return true;
            else 
                return false;
        }
        else
            return false;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        
        int idx = 0;
        for (auto i: mat) {
            int sum = 0;
            for (auto j: i) {
                sum += j;
            }
            v.push_back({idx++, sum});
        }
        
        sort(v.begin(), v.end(), compare);
        
        vector<int> ret(k);
        for (int i = 0; i < k; i++) {
            ret[i] = v[i].first;
        }
        
        return ret;
    }
};
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m; // num, index;
        int n = intervals.size();
        for (int i = 0; i < n; i++) m[intervals[i][0]] = i;
        vector<int> ans(intervals.size(), -1);
        for (int i = 0, n = intervals.size(); i < n; i++) {
            auto val = m.lower_bound(intervals[i][1]);
            ans[i] = val != m.end() ? val->second : -1;
        }
        return ans;
    }
};
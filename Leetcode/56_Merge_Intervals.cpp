class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> tmp = intervals[0];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] > tmp[1]) {
                ans.push_back(tmp);
                tmp = intervals[i];
            }
            else tmp[1] = max(tmp[1], intervals[i][1]);
        }
        ans.push_back(tmp);
        return ans;
    }
};
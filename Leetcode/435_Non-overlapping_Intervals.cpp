class Solution {
public:
    /*
    Hi, try to pass the vectors in the comparator by their address instead of their value.
    The difference is when in a function, you pass any data type via address, existing data is shared whereas when we pass any data type by its name/value, a new copy of that data type is created and then shared. Hence it becomes an expensive operation.
    */
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int ans = -1; // prev is intervals[0];
        vector<int> prev = intervals[0];
        for (auto i: intervals) {
            if (i[0] < prev[1]) ans++;
            else prev = i;
        }
        return ans;
    }
};
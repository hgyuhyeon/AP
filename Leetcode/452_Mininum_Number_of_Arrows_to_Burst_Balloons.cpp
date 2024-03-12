class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> merged;
        merged.push_back(points[0]);
        vector<int> tmp = points[0];
        for (int n = points.size(), i = 1; i < n; i++) {
            if (tmp[1] < points[i][0]) {
                merged.push_back(points[i]);
                tmp = points[i];
            }
            else {
                merged.back()[1] = max(points[i][1], merged.back()[1]);
                tmp[1] = min(points[i][1], tmp[1]);
            }
        }
        return merged.size();
    }
};
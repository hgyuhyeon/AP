class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int num = points[0][1], i = 1, res = 0;
        while (i < points.size()) {
            if (num >= points[i][0]) {
                if (num > points[i][1]) num = points[i][1];
                i++;
            }
            else {
                res++;
                num = points[i][1];
                i++;
            }
        }

        return res + 1;
    }
};
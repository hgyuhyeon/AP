class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid[0].size(), ans = 0;
        for (auto row: grid) {
            for (int i = 0; i < m; i++) {
                if (row[i] < 0) {
                    ans += m - i;
                    break;
                }
            }
        }
        return ans;
    }
};
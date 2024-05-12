class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans;
        vector<int> tmp(n-2, 0);
        for (int i = 1; i < n-1; i++) {
            int idx = 0;
            for (int j = 1; j < n-1; j++) {
                for (int k = i-1; k <= i+1; k++) {
                    for (int l = j-1; l <= j+1; l++) tmp[idx] = max(tmp[idx], grid[k][l]);
                }
                idx++;
            }
            ans.push_back(tmp);
            tmp = vector<int>(n-2, 0);
        }
        return ans;
    }
};
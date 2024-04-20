class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    int k = i+1, l = j+1;
                    while (k < n && land[k][j] == 1) k++;
                    while (l < m && land[i][l] == 1) l++;
                    ans.push_back({i, j, k-1, l-1});
                    for (int p = i; p < k; p++) {
                        for (int o = j; o < l; o++) land[p][o] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
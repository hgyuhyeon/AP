class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mod = 12345;
        vector<vector<int>> pf(n, vector<int>(m, 1));
        for (int i=0, pd=1; i<n; i++) {
            for (int j=0; j<m; j++) {
                pf[i][j] = pd;
                pd = (pd*(grid[i][j]%12345))%12345;
            }
        }
        for (int i=n-1, pd=1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                pf[i][j] = (pf[i][j]*pd)%12345;
                pd = (pd*(grid[i][j]%12345))%12345;
            }
        }
        return pf;
    }
};
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pf(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pf[i][j] = (i==0?0:pf[i-1][j]) + (j==0?0:pf[i][j-1]) + mat[i][j] - (i==0||j==0?0:pf[i-1][j-1]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int rmx = i+k>=n?n-1:i+k, rmn = i-k-1<0?-1:i-k-1, cmx = j+k>=m?m-1:j+k, cmn = j-k-1<0?-1:j-k-1;
                mat[i][j] = pf[rmx][cmx];
                if (cmn != -1) mat[i][j] -= pf[rmx][cmn];
                if (rmn != -1) mat[i][j] -= pf[rmn][cmx];
                if (rmn != -1 && cmn != -1) mat[i][j] += pf[rmn][cmn];
            }
        }
        return mat;
    }
};
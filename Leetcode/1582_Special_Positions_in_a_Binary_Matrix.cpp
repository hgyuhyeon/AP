class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size(), m = mat[0].size();
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1 && row[i] + col[j] - mat[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};

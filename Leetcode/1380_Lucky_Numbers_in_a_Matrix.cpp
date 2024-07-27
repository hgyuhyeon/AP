class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n, INT_MAX), col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] = min(matrix[i][j], row[i]);
                col[j] = max(matrix[i][j], col[j]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == col[j]) ans.push_back(row[i]);
            }
        }

        return ans;
    }
};

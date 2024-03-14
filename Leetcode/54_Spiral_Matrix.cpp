class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size() - 1, m = matrix[0].size() - 1, ln = 0, lm = 0;
        while (n >= ln && m >= lm) {
            for (int i = lm; i <= m; i++) {
                if (matrix[ln][i] <= 100) {
                    ans.push_back(matrix[ln][i]);
                    matrix[ln][i] = 101;
                }
            }
            for (int i = ln; i <= n; i++) {
                if (matrix[i][m] <= 100) {
                    ans.push_back(matrix[i][m]);
                    matrix[i][m] = 101;
                }
            }
            for (int i = m; i >= lm; i--) {
                if (matrix[n][i] <= 100) {
                    ans.push_back(matrix[n][i]);
                    matrix[n][i] = 101;
                }
            }
            for (int i = n; i >= ln; i--) {
                if (matrix[i][lm] <= 100) {
                    ans.push_back(matrix[i][lm]);
                    matrix[i][lm] = 101;
                }
            }
            lm++; ln++; m--; n--;
        }
        return ans;
    }
};
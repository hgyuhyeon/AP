class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size() - 1, m = matrix[0].size() - 1, ln = 0, lm = 0;
        while (n >= ln && m >= lm) {
            for (int i = lm; i <= m; i++) ans.push_back(matrix[ln][i]);
            ln++;
            for (int i = ln; i <= n; i++) ans.push_back(matrix[i][m]);
            m--;
            if (n >= ln) {
                for (int i = m; i >= lm; i--) ans.push_back(matrix[n][i]);
                n--;
            }
            if (m >= lm) {
                for (int i = n; i >= ln; i--) ans.push_back(matrix[i][lm]);
                lm++;
            }
        }
        return ans;
    }
};
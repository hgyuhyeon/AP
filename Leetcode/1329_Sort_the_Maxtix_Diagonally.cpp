class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (n == 1 || m == 1) return mat;
        vector<priority_queue<int, vector<int>, greater<>>> srt(n+m-1);
        int idx = 0;
        for (int j = m-1; j > 0; j--) {
            for (int i = 0, k = j; k < m && i < n; i++, k++) srt[idx].push(mat[i][k]);
            idx++;
        } 
        for (int i = 0; i < n; i++) {
            for (int j = 0, k = i; k < n && j < m; j++, k++) srt[idx].push(mat[k][j]);
            idx++;
        }
        idx = 0;
        for (int j = m-1; j > 0; j--) {
            for (int i = 0, k = j; k < m && i < n; i++, k++) {
                mat[i][k] = srt[idx].top();
                srt[idx].pop();
            }
            idx++;
        } 
        for (int i = 0; i < n; i++) {
            for (int j = 0, k = i; k < n && j < m; j++, k++) {
                mat[k][j] = srt[idx].top();
                srt[idx].pop();
            }
            idx++;
        }
        return mat;
    }
};
int flippingMatrix(vector<vector<int>> matrix) {
    int n = matrix.size(), ans = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            ans += max(matrix[i][j], max(matrix[n-1-i][j], max(matrix[i][n-1-j], matrix[n-1-i][n-1-j])));
        }
    }
    return ans;
}
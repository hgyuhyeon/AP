class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size();
        for (int i = 0; i < n; i++) {
            ans += mat[i][i];
            ans += mat[i][n-1-i];
        }
        
        if (mat.size() % 2 == 1) ans -= mat[n/2][n/2];
        return ans;
    }
};
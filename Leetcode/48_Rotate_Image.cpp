class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        queue<int> q;
        for (auto i: matrix) {
            for (auto j: i) q.push(j);
        }

        int n = matrix.size();
        for (int j = n - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                matrix[i][j] = q.front();
                q.pop();
            }
        }
    }
};
class Solution {
public:
    int calc(vector<vector<int>>& board, int r, int c) {
        int val = 0;
        int i = r-1 < 0 ? 0 : r-1, j = c-1 < 0 ? 0 : c-1;
        int n = r+1 >= board.size() ? r : r+1, m = c+1 >= board[0].size() ? c : c+1;
        for (;i <= n; i++) {
            for (int k = j; k <= m; k++) {
                val += board[i][k];
            }
        }
        return val - board[r][c];
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> tmp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int neighbor = calc(board, i, j);
                if (neighbor > 3 || neighbor < 2) tmp[i][j] = 0;
                else if (neighbor == 3) tmp[i][j] = 1;
                else tmp[i][j] = board[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) board[i][j] = tmp[i][j];
        }
    }
};
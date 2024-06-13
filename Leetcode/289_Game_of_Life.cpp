class Solution {
public:
    int calc(vector<vector<int>>& board, int x, int y) {
        int cnt = 0, n = board.size(), m = board[0].size();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int r = x + i, c = y + j;
                if (r >= 0 && r < n && c >= 0 && c < m && board[r][c]) cnt++;
            }
        }
        if (cnt == 3 || (board[x][y] && cnt == 2)) return 1;
        else return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> tmp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = calc(board, i, j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = tmp[i][j];
            }
        }
    }
};
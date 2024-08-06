class Solution {
public:
    void solve(vector<vector<char>>& origin, vector<vector<char>>& board, vector<pair<int, int>>& cell, int idx) {
        if (idx == cell.size()) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) origin[i][j] = board[i][j];
            }
            return;
        }
        bool c[10] = { false, };
        for (int i = 0; i < 9; i++) {
            if (board[cell[idx].first][i] != '.') c[board[cell[idx].first][i] - '0'] = true;
            if (board[i][cell[idx].second] != '.') c[board[i][cell[idx].second] - '0'] = true;
        }
        int x = cell[idx].first / 3 * 3, y = cell[idx].second / 3 * 3;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if(board[i][j] != '.') c[board[i][j] - '0'] = true;
            }
        }

        for (int i = 1; i <= 9; i++) {
            if (!c[i]) {
                board[cell[idx].first][cell[idx].second] = i + '0';
                solve(origin, board, cell, idx+1);
                board[cell[idx].first][cell[idx].second] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> tmp(board.begin(), board.end());
        vector<pair<int, int>> cell;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (tmp[i][j] == '.') cell.push_back({i, j});
            }
        }
        solve(board, tmp, cell, 0);
    }
};

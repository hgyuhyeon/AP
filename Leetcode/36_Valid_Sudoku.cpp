class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<int, int>> w(9), h(9);
        vector<vector<map<int, int>>> sq(3, vector<map<int, int>>(3));
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char val = board[i][j];
                if (val == '.') continue;
                if (++w[val - '1'][i] > 1 || ++h[val - '1'][j] > 1 || ++sq[i/3][j/3][val - '1'] > 1) return false;
            }
        }
        return true;
    }
};
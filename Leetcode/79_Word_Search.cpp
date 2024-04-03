class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int cnt, int i, int j) {
        if (cnt == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if (word[cnt] == board[i][j]) {
            char tmp = board[i][j];
            board[i][j] = ' ';
            bool ans = search(board, word, cnt+1, i+1, j) || search(board, word, cnt+1, i-1, j) || search(board, word, cnt+1, i, j+1) || search(board, word, cnt+1, i, j-1);
            board[i][j] = tmp;
            return ans;
        }
        else return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j]) if (search(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
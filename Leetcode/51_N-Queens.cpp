class Solution {
private:
    int n;
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> oc;
public:
    bool check(int lv) {
        for (int j = 0; j < lv; j++) {
            if (oc[lv] == oc[j] || (abs(oc[lv] - oc[j]) == lv - j)) return false;
        }
        return true;
    }
    void solve(int lv) {
        if (lv == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            board[lv][i] = 'Q';
            oc[lv] = i;
            if (check(lv)) solve(lv+1);
            board[lv][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        string str = "";
        for (int i = 0; i < n; i++) str += '.';
        board = vector<string>(n, str);
        oc = vector<int>(n);
        solve(0);
        return ans;
    }
};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<int> sq(n*n+1);
        for (int i = n-1, num = 1; i >= 0; i--) {
            if (num / n % 2 == 0) for (int j = 0; j < m; j++) sq[num++] = board[i][j];
            else for (int j = m-1; j >= 0; j--) sq[num++] = board[i][j];
        }

        queue<pair<int, int>> q;
        vector<int> v(n*n+1, false);
        q.push({1, 0});
        while (!q.empty()) {
            int val = q.front().first, cnt = q.front().second;
            q.pop();
            if (val == n*n) return cnt;
            for (int i = 1; i <= 6 && val+i <= n*n; i++) {
                if (v[val+i]) continue;
                v[val+i] = true;
                if (sq[val+i] != -1) q.push({sq[val+i], cnt+1});
                else q.push({val+i, cnt+1});
            }
        }
        return -1;
    }
};
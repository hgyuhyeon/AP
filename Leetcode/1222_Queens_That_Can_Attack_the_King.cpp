class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> q(8, vector<int>(8, 0)), ans;
        for (auto queen: queens) q[queen[0]][queen[1]] = 1;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int r = king[0] + i, c = king[1] + j;
                while (r >= 0 && r < 8 && c >= 0 && c < 8) {
                    if (q[r][c] == 1) {
                        ans.push_back({r, c});
                        break;
                    }
                    r += i;
                    c += j;
                }
            }
        }
        return ans;
    }
};
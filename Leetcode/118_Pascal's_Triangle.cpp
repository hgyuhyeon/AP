class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>(1, 1));
        for (int i = 2; i <= numRows; i++) {
            for (int j = 1; j < i - 1; j++) ans[i-1].push_back(ans[i-2][j-1] + ans[i-2][j]);
            ans[i-1].push_back(1);
        }
        return ans;
    }
};
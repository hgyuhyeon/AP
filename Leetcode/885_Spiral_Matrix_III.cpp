class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int rl = rStart, rh = rStart, cl = cStart, ch = cStart, val = 1;
        vector<vector<int>> ans;
        while (!(rl < 0 && rh >= rows && cl < 0 && ch >= cols)) {
            ch++;
            if (rl >= 0) for (int j = cl; j <= ch; j++) if (j >= 0 && j < cols) ans.push_back({rl, j});
            rh++;
            if (ch < cols) for (int i = rl+1; i <= rh; i++) if (i >= 0 && i < rows) ans.push_back({i, ch});
            cl--;
            if (rh < rows) for (int j = ch-1; j >= cl; j--) if (j >= 0 && j < cols) ans.push_back({rh, j});
            rl--; 
            if (cl >= 0) for (int i = rh-1; i > rl; i--) if (i >= 0 && i < rows) ans.push_back({i, cl});
        }
        return ans;
    }
};

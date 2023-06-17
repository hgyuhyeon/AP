class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> m;
        int size = grid.size(), ans = 0;
        for (auto i: grid) m[i]++;

        for (int i = 0; i < size; i++) {
            vector<int> v(size);
            for (int j = 0; j < size; j++) {
                v[j] = grid[j][i];
            }
            if (m[v]) ans += m[v];
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lose;
        int n = 0;
        for(auto m: matches) {
            if(lose[m[0]] == 0) lose[m[0]] = 0;
            lose[m[1]]++;
        }
        vector<vector<int>> ans(2, vector<int>());
        for (auto [i, l]: lose) {
            if (l == 0) ans[0].push_back(i);
            else if (l == 1) ans[1].push_back(i);
        }
        return ans;
    }
};
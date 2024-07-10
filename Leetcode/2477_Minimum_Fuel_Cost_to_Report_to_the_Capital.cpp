class Solution {
public:
    long long dfs(vector<vector<int>>& g, int cur, int p, int& seats, long long& ans) {
        if (g[cur].size() == 1 && cur) {
            ans++;
            return 1;
        }
        long long cnt = 1;
        for (auto next: g[cur]) {
            if (next != p) cnt += dfs(g, next, cur, seats, ans);
        }
        if (cur) ans += (cnt / seats) + (cnt % seats ? 1 : 0);
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> g(n);
        for (auto r: roads) {
            g[r[0]].push_back(r[1]);
            g[r[1]].push_back(r[0]);
        }
        long long ans = 0;
        dfs(g, 0, -1, seats, ans);
        return ans;
    }
};

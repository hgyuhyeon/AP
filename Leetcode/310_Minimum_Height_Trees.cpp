class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> g(n);
        map<int, int> cnt;
        int max_edge = -1;
        for (auto e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            cnt[e[0]]++;
            cnt[e[1]]++;
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++) if (cnt[i] == 1) q.push(i);
        int c = n;
        while (!q.empty()) {
            int qs = q.size();
            c -= qs;
            for (int i = 0; i < qs; i++) {
                if (c == 0) ans.push_back(q.front());
                for (int w: g[q.front()]) if (--cnt[w] == 1) q.push(w);
                q.pop();
            }
        }
        return ans;
    }
};
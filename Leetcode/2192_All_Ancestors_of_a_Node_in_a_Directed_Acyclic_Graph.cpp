class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> a;
        for (int i = 0; i < n; i++) a[i] = vector<int>();
        for (auto e: edges) a[e[1]].push_back(e[0]);
        vector<vector<int>> ans(n, vector<int>());
        for (int i = 0; i < n; i++) {
            queue<int> q;
            vector<bool> v(n, false);
            v[i] = true;
            for (auto j: a[i]) {
                q.push(j);
                v[j] = true;
            }
            while (!q.empty()) {
                ans[i].push_back(q.front());
                for (auto j: a[q.front()]) {
                    if (!v[j]) {
                        q.push(j);
                        v[j] = true;
                    }
                }
                q.pop();
            }
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};